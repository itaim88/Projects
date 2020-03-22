package il.co.ilrd.concurrency;

import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

public class OneProdMultiCons {
	private static AtomicInteger x = new AtomicInteger();
	static int num = 0;
	static Integer lock = 1;
	private static final int NUM_THREADS = 10;
	private final static Semaphore semaphore = new Semaphore(NUM_THREADS - 1);
	
	public class Consumer implements Runnable {
		@Override
		public void run() {
			while (true) {
				semaphore.release();
	
				synchronized (lock) {
					try {
						x.incrementAndGet();
						lock.wait();
						System.out.println("consumer reads: "+ num);
				
					} catch (InterruptedException e) {
							e.printStackTrace();
					}
				}
			}	
		}	
	}
		
	public class Producer implements Runnable {
		@Override
		public void run() {
			while (true) {
	
				for (int i = 0; i < NUM_THREADS; ++i) {
					x.decrementAndGet();
				}
				
				try {
					semaphore.acquire();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				
				while (0 != x.get());
				synchronized(lock) {
					++num;
					System.out.println("producer: " + num);
				}
				
				while (0 != x.get());
					
				synchronized(lock) {	
				lock.notifyAll();
				}
			}		
		}		
	}
		
	public static void main(String[] args) {
		Producer p1 = new OneProdMultiCons().new Producer();
		Consumer c1 = new OneProdMultiCons().new Consumer();
		
		Thread thread1 = new Thread(p1);
		thread1.start();
		for (int i = 0; i < NUM_THREADS; ++i) {
			new Thread(c1).start();
		}

		try {
			thread1.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}	
}



