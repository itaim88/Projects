package il.co.ilrd.concurrency;

import java.util.LinkedList;
import java.util.concurrent.Semaphore;

public class ListProdCons {
	
	static LinkedList<Integer> list = new LinkedList<Integer>();
	private final static Semaphore semaphore = new Semaphore(0);
	Object lock = new Object();
	Integer num = 7;	
	
	public class Consumer implements Runnable {
		@Override
		public void run() {
			//while (list.isEmpty());// busy waiting
			try {
				semaphore.acquire();
			} catch (InterruptedException e) {
				
				e.printStackTrace();
			}
			synchronized(lock) {
			System.out.println("remove "+list.remove());
			}	
		}	
	}
		
		public class Producer implements Runnable {
			@Override
			public void run() {
				synchronized(lock) {
				list.add(++num);
				System.out.println("add " + list.peekLast());
				semaphore.release();
				}
			}		
		}
		public static void main(String[] args) {
			Producer ping = new ListProdCons().new Producer();
			Consumer pong = new ListProdCons().new Consumer();
			
			for (int i = 0; i < 30; ++i) {
				new Thread(ping).start();
				new Thread(pong).start();
			}
		
			try {
				Thread.sleep(100000);
			} catch (InterruptedException e) {	
				e.printStackTrace();
			}
			
			System.out.println("finish sleeping");
						
		}	

}

