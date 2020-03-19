package il.co.ilrd.concurrency;

import java.util.concurrent.Semaphore;

public class ProdConsu2 {
	
	private final static Semaphore semaphore = new Semaphore(1);
	private final static Semaphore semaphore1 = new Semaphore(0);
	static volatile boolean flag = true;

	public class Consumer implements Runnable {

		@Override
		public void run() {
			while (flag) {
				try {
					semaphore1.acquire();
				} catch (InterruptedException e) {
					e.printStackTrace();
				} 
				System.out.println("pong");
				semaphore.release();
			}
		}	
	}
	
	public class Producer implements Runnable {

		@Override
		public void run() {
			while (flag) {
				try {
					semaphore.acquire();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				System.out.println("ping");
				semaphore1.release(); 
		    }
		}	
	}
	public static void main(String[] args) {
		Producer ping = new ProdConsu2().new Producer();
		Consumer pong = new ProdConsu2().new Consumer();
		
		Thread thread1 = new Thread(ping);
		Thread thread2 = new Thread(pong);
		
		thread1.start();
		thread2.start();
		
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {	
			e.printStackTrace();
		}
		
		flag = false;
		System.out.println("finish sleeping");
					
	}
}
