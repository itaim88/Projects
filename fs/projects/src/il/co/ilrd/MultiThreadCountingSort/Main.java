package il.co.ilrd.MultiThreadCountingSort;

import java.util.Arrays;

public class Main {
	
	public static void main(String[] args) { 
		int NUM_OF_THREADS = 7;
	
		for (int i = 0; i < NUM_OF_THREADS; ++i) {
		 ThreadCountingSort c = new ThreadCountingSort();
		 c.start();
		}
		
		try {
			Thread.sleep(10000);
		} catch (InterruptedException e) {	
			e.printStackTrace();
		}
		
		System.out.println("finish sleeping");	
	
	}
}
