package il.co.ilrd.ThreadPool;

import java.util.concurrent.Callable;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.FutureTask;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

import il.co.ilrd.waitableQueue.WaitableQueue;

public class ThreadPool {
	private int totalThreads;
	private WaitableQueue<Task<?>> queue;
	private WaitableQueue<WorkerThread> threadPool;
	private volatile boolean shutdownFlag = false;
	private Semaphore semaphor = new Semaphore(0);
	
	public ThreadPool(int totalThreads) {
		this.totalThreads = totalThreads;
		this.queue = new WaitableQueue<>();
		this.threadPool = new WaitableQueue<>();
		 infrastructure();
	}
	
	private void infrastructure() {
		for (int i = 0; i < totalThreads; ++i) {
			new WorkerThread().start();
		}
	}
	
	public enum Priority {
		LOW	(1),
		MID	(5),
		HIGH(10);

		private int priorityVal;
		
		private Priority(int priorityVal) {
			this.priorityVal = priorityVal;
		}
		
		private int getPriorityVal(){
			return priorityVal;
		}
	}
	
	private class WorkerThread extends Thread{
		private boolean flag = true;
	
		@Override
		public void run() {
			while(flag) {
				System.out.println(getName() + " run");
				try {
					queue.dequeue().futureTask.run();
				} catch (InterruptedException e) {
					System.out.println("not running");
					e.printStackTrace();
				}
			}
			/*
			try {
				queue.dequeue().futureTask.cancel(true); / cancel task???
			} catch (InterruptedException e) {
				
				e.printStackTrace();
			}
			*/
		}
	
		private void disable() {
			flag = false;
		}
	}

	private static class Task<T> implements Comparable<Task<T>> {
		private Callable<T> callable;
		private int priority;
		private FutureTask<T> futureTask;
	
		private Task(Callable<T> callable, int priority) {
			this.callable = callable;
			this.priority = priority;
			this.futureTask = new FutureTask<>(this.callable);
		}
	
		@Override
		public int compareTo(Task<T> task) {
			return  task.priority - this.priority;
		}
	}
	
	/**
	 * Submits a value-returning task for execution and returns a Future 
	 * representing the pending results of the task. The Future's get method 
	 * will return the task's result upon successful completion.
	 * 
	 * @param runnable
	 * @param priority
	 * @return
	 */
	public Future<Object> submit(Runnable runnable, Priority priority) {
		if (shutdownFlag) {
			throw new RejectedExecutionException("the pool is shutdown");
		}
		
		try {
			Task<Object> t = new Task<>(Executors.callable(runnable), priority.getPriorityVal());
			queue.enqueue(t);
			
			return t.futureTask;
			
		} catch(NullPointerException e) {
			throw new NullPointerException();
		}
	}
	
	public <T> Future<T> submit(Runnable runnable, Priority priority, T value) {
		if (shutdownFlag) {
			throw new RejectedExecutionException("the pool is shutdown");
		}
		try {
			Task<T> t = new Task<>(Executors.callable(runnable, value), priority.getPriorityVal());
			queue.enqueue(t);
			return t.futureTask;
		} catch(NullPointerException e) {
			throw new NullPointerException();			
		}
	}
	
	public <T> Future<T> submit(Callable<T> callable) {
		if (shutdownFlag) {
			throw new RejectedExecutionException("the pool is shutdown");
		}
		try {
			Task<T> t = new Task<>(callable, Priority.MID.getPriorityVal());
			queue.enqueue(t);
			return t.futureTask;
			
		} catch(NullPointerException e) {
			throw new NullPointerException();
		}
	}
	
	public <T> Future<T> submit(Callable<T> callable, Priority priority) {
		if (shutdownFlag) {
			throw new RejectedExecutionException("the pool is shutdown");
		}
		
		try {
			Task<T> t = new Task<>(callable, priority.getPriorityVal());
			queue.enqueue(t);
			return t.futureTask;
		} catch(NullPointerException e) {
			throw new NullPointerException();			
		}
	}
	
	public void setNumOfThreads(int num) {
		if (totalThreads <= num) {
			for (int i = 0; i < (num - totalThreads); ++i) {
				new WorkerThread().start();
			}
		}
		
		else  {
			for (int i = 0; i < totalThreads - num; ++i) {
				Task<Object> t = new Task<>(Executors.callable(new ShutDown()), Priority.HIGH.getPriorityVal() - 1);
				queue.enqueue(t);
			}
			
		}
		totalThreads = num;
	}
	
	private class ShutDown implements Runnable{
		@Override
		public void run() {
			WorkerThread wt = (WorkerThread)Thread.currentThread();
			wt.disable();
		}
	}
	
	public void shutdown() {
		shutdownFlag = true;
		
		for (int i = 0; i < totalThreads; ++i) {
			Task<Object> t = new Task<>(Executors.callable(new ShutDown()), Priority.LOW.getPriorityVal() - 1);
			queue.enqueue(t);
		}
	}
	
	/**
	 * Blocks until all tasks have completed execution after a shutdown request, 
	 * or the timeout occurs, or the current thread is interrupted, 
	 * whichever happens first.
	 * 
	 * @param timeOut - the maximum time to wait
	 * @param unit - the time unit of the timeout argument
	 * @return true if this executor terminated and false if the timeout elapsed before termination
	 * @throws InterruptedException - if interrupted while waiting
	 */
	public boolean awaitTermination(int timeOut, TimeUnit unit) throws InterruptedException {
		Thread thread = null;
		
		for (int i = 0; i < totalThreads; ++i) {
			thread = threadPool.dequeueWithTimeot(timeOut, unit);
			thread.join();
		}
		
		return (thread == null ? false : true);
	}

	public void pause() {
		
		class Pause implements Runnable{
			@Override
			public void run() {
				try {
					System.out.println("in wait");
					semaphor.acquire(); ;
					System.out.println("out of wait");
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}	
		
		for (int i = 0; i < totalThreads; ++i) {
			Task<Object> t = new Task<>(Executors.callable(new Pause()), Priority.HIGH.getPriorityVal() + 1);
			queue.enqueue(t);
		}
	}
	
	public void resume() {
		semaphor.release(totalThreads);;
	}
}

