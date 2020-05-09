package il.co.ilrd.crud;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Observable;

public class Monitor extends Observable implements Runnable{
	private String pathFileToMonitor;
	private volatile boolean Monitoring = true;
	
	public Monitor(String fileToMonitor){
		this.pathFileToMonitor = fileToMonitor;
	}
	
	@Override
	public void run() {
		String line = null;
		try (BufferedReader reader = new BufferedReader(new FileReader(pathFileToMonitor))) {		
			while (Monitoring) {
				if ( (line = reader.readLine()) != null ) {
					setChanged();	
					notifyObservers(line);
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void startMonitoring() {
		Thread t = new Thread(() -> {run();});
		t.start();
		
	}
	public void stopMonitor() {
		Monitoring = false;	
	}
}
