package il.co.ilrd.waitableQueue;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class WaitableQueue<E> {
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
		synchronized(this) {
			try {
				queue.add(element);
				
			} catch (ClassCastException e) { 
				System.out.println("ClassCastException");
			
			} catch (NullPointerException n) {
				System.out.println("NullPointerException");
			}
			
			notify();
		}	
}

	public  synchronized E dequeue() throws InterruptedException {
		while (queue.isEmpty()) {
				wait();
		}
		
		return queue.poll();
	}
	
	public E dequeueWithTimeot(int timeInMillSeconds) throws InterruptedException{
		long startTime = System.currentTimeMillis();
		while (timeInMillSeconds > System.currentTimeMillis() - startTime) {
			synchronized(this) {
				if(!queue.isEmpty()) {
					return queue.poll();
				}	
			}
		}
		
		return null;
	}
}

