package il.co.ilrd.concurrency;

import java.util.concurrent.atomic.*;

public class ProdCons1 {
	//static volatile int x = 0;
	private static AtomicInteger x = new AtomicInteger();
	static volatile boolean flag = true;

	public class Consumer implements Runnable {

		@Override
		public void run() {
			while (flag) {
				if (1 == x.get()) {
				System.out.println("pong ");
				x.decrementAndGet();
				}
			}
		}	
	}
	
	public class Producer implements Runnable {

		@Override
		public void run() {
			while (flag) {
				if (0 == x.get()) {
				System.out.println("ping ");
				x.incrementAndGet();
				}
		    }
		}	
	}
	public static void main(String[] args) {
		Producer ping = new ProdCons1().new Producer();
		Consumer pong = new ProdCons1().new Consumer();
		
		Thread thread1 = new Thread(ping);
		Thread thread2 = new Thread(pong);
		
		thread1.start();
		thread2.start();
		
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {	
			e.printStackTrace();
		}
		
		flag = false;
		System.out.println("finish sleeping");	
	}			
}
