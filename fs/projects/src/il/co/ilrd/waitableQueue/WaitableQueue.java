package il.co.ilrd.waitableQueue;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class WaitableQueue<E> {
	private Object lock = new Object();
	private Semaphore sem = new Semaphore(0);
	private Queue<E> queue;
	private  final int DEFAULT_CAPACITY; 
	
	public WaitableQueue() {
		DEFAULT_CAPACITY = 11; 
		queue = new PriorityQueue<>(DEFAULT_CAPACITY);
	}
	
	public WaitableQueue(int DEFAULT_CAPACITY, Comparator<E> comparator) {
		this.DEFAULT_CAPACITY = DEFAULT_CAPACITY;
		queue = new PriorityQueue<E>(DEFAULT_CAPACITY,comparator);
	}

	public void enqueue(E element) {
		synchronized(lock) {
			try {
				queue.add(element);
				
			} catch (ClassCastException e) { 
				System.out.println("ClassCastException");
			
			} catch (NullPointerException n) {
				System.out.println("NullPointerException");
			}
			
			sem.release();
		}	
}

	public E dequeue() throws InterruptedException {
		synchronized(lock) {
			sem.acquire();
			return queue.remove();
		}
	}
	
	public E dequeueWithTimeot(int timeInMillSeconds) throws InterruptedException{
		
		if(sem.tryAcquire(timeInMillSeconds, TimeUnit.SECONDS)) {
			synchronized (lock) {
				return queue.remove();	
			}
		}
		
		else {return null;}
	}
}

