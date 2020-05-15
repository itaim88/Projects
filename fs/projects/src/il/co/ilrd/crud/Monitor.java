package il.co.ilrd.crud;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardWatchEventKinds;
import java.nio.file.WatchEvent;
import java.nio.file.WatchKey;
import java.nio.file.WatchService;
import java.util.Observable;

public class Monitor extends Observable implements Runnable {
	private File file;
	private volatile boolean Monitoring = true;
	private WatchService watchService;
	private Path dirPath;
	private Thread thread;
	
	public Monitor(String pathFileToMonitor){
		file = new File(pathFileToMonitor);
		dirPath = Paths.get(file.getParent());
		
		try {
			watchService = FileSystems.getDefault().newWatchService();
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			dirPath.register(watchService, StandardWatchEventKinds.ENTRY_MODIFY);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	@Override
	public void run() {
		String line = null;
		try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
			while((line = reader.readLine()) != null ) {
				setChanged();	
				notifyObservers(line);
			}
			
			WatchKey key; 
            while (Monitoring) {
            	key = watchService.take();
                for (WatchEvent<?> event : key.pollEvents()) {
                    @SuppressWarnings("unchecked")
                    Path fileName = ((WatchEvent<Path>)event).context();
                    if (fileName.toString().equals(file.getName().toString())) {
                        setChanged();
                        notifyObservers(reader.readLine());
                    }
                }
                if (!key.reset()) {break;}
            }
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (InterruptedException e) {
			//ignor
			//System.out.println("thread interrupted");
		}

	}
	public void startMonitoring() {
		thread = new Thread(() -> {run();});
		thread.start();
		
		}
	public void stopMonitor() throws IOException {
		Monitoring = false;	
		thread.interrupt();
		
	}
}
