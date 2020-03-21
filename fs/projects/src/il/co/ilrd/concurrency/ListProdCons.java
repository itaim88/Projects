package il.co.ilrd.concurrency;

import java.util.LinkedList;
import java.util.concurrent.Semaphore;

public class ListProdCons {
	static LinkedList<Integer> list = new LinkedList<Integer>();
	private final static Semaphore semaphore = new Semaphore(0);
	Integer num = 0;
	private static final int NUM_THREADS = 33;
	
	public class Consumer implements Runnable {
		@Override
		public void run() {
			//while (list.isEmpty());// busy waiting
			try {
				semaphore.acquire();
			} catch (InterruptedException e) {
				
				e.printStackTrace();
			}
			
			synchronized(this) {
			System.out.println("remove "+list.remove());
			}	
		}	
	}
		
	public class Producer implements Runnable {
		@Override
		public void run() {
			synchronized(this) {
			list.add(++num);
			System.out.println("add " + list.peekLast());
			semaphore.release();
			}
		}		
	}
		
	public static void main(String[] args) {
		Producer ping = new ListProdCons().new Producer();
		Consumer pong = new ListProdCons().new Consumer();
		
		for (int i = 0; i < NUM_THREADS; ++i) {
			new Thread(ping).start();
			new Thread(pong).start();
		}
	
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {	
			e.printStackTrace();
		}
		
		System.out.println("finish sleeping");				
	}	
}

