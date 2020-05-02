package il.co.ilrd.waitableQueue;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

public class WaitableQueue<E> {
	private volatile Object lock = new Object();
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
				System.out.println("Thread add");
				queue.add(element);
				
			} catch (ClassCastException e) { 
				System.out.println("enqueue ClassCastException");
			
			} catch (NullPointerException n) {
				System.out.println("enqueue NullPointerException");
			}
		}
			sem.release();
			
}

	public E dequeue() throws InterruptedException {
			sem.acquire();
			synchronized(lock) {
				System.out.println("Thread remove");
				E hold = null;
			try {
				hold = queue.remove(); 
			} catch (Exception e) {
				System.out.println("dequeue exception");
			}
			return hold;
		}
	}
	
	public E dequeueWithTimeot(int timeInMillSeconds, TimeUnit unit) throws InterruptedException{
		
		if(sem.tryAcquire(timeInMillSeconds, unit)) {
			synchronized (lock) {
				return queue.remove();	
			}
		}
		
		return null;
	}
}

