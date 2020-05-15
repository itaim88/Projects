package il.co.ilrd.crud;

import static org.junit.jupiter.api.Assertions.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

class Test {

	public static void main(String[] s) throws IOException {
		Monitor monitor = new Monitor("C:\\Users\\yuval tsuk\\Desktop\\monitorFile.txt");
		monitor.addObserver(new FileObserver("C:\\Users\\yuval tsuk\\Desktop\\write.txt"));
		monitor.startMonitoring();
	
		try {
			Thread.sleep(10000 * 3);
		} catch (InterruptedException e) {
		}
		
		monitor.stopMonitor();
		System.out.println("finish");
	}
}
