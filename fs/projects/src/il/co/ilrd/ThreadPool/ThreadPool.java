package il.co.ilrd.ThreadPool;

import java.util.concurrent.Callable;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.FutureTask;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

import il.co.ilrd.waitableQueue.WaitableQueue;

public class ThreadPool {
	private int totalThreads;
	private WaitableQueue<Task<?>> queue;
	private LinkedBlockingDeque<WorkerThread> WorkingThreads = new LinkedBlockingDeque<>();
	private volatile boolean shutDownFlag = false;
	private Semaphore pauseSemaphor = new Semaphore(0);
	private int pauseNumberOfThreads;
	
	public ThreadPool(int totalThreads) {
		this.totalThreads = totalThreads;
		this.pauseNumberOfThreads = totalThreads;
		this.queue = new WaitableQueue<>();
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
		private boolean workFlag = true;
	
		@Override
		public void run() {
			while(workFlag) {
				try {
					queue.dequeue().futureTask.run();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
	
		private void disable() {
			workFlag = false;
		}
	}

	private static class Task<T> implements Comparable<Task<T>> {
		private int priority;
		private FutureTask<T> futureTask;
	
		private Task(Callable<T> callable, int priority) {
			this.priority = priority;
			this.futureTask = new FutureTask<>(callable);
		}
	
		@Override
		public int compareTo(Task<T> task) {
			return task.priority - this.priority;
		}
	}
	
	
	public Future<?> submit(Runnable runnable) {
		return submit(Executors.callable(runnable), Priority.MID);
	}
	
	public Future<?> submit(Runnable runnable, Priority priority) {
		return submit(Executors.callable(runnable), priority);
	}
	public <T> Future<T> submit(Runnable runnable, Priority priority, T value) {
		return submit(Executors.callable(runnable, value), priority);
	}
	
	public <T> Future<T> submit(Callable<T> callable) {
		return submit(callable, Priority.MID);
	}
	
	public <T> Future<T> submit(Callable<T> callable, Priority priority) {
		if (shutDownFlag) {
			throw new RejectedExecutionException("can`t submit class in shutdown");
		}
		
		try {
			Task<T> t = new Task<>(callable, priority.getPriorityVal());
			queue.enqueue(t);
			return t.futureTask;
		} catch(NullPointerException e) {
			throw new NullPointerException();			
		}
	}
	
	public void setNumOfThreads(int newThreadNumber) {
		if (totalThreads <= newThreadNumber) {
			for (int i = 0; i < (newThreadNumber - totalThreads); ++i) {
				new WorkerThread().start();
			}
		}
		
		else  {
			for (int i = 0; i < totalThreads - newThreadNumber; ++i) {
				Task<Object> t = new Task<>(Executors.callable(new ShutDown()), Priority.HIGH.getPriorityVal() + 1);
				queue.enqueue(t);
			}	
		}
		
		totalThreads = newThreadNumber;
	}
	
	private class ShutDown implements Runnable{
		@Override
		public void run() {
			WorkerThread thread = (WorkerThread)Thread.currentThread();
			thread.disable();
			WorkingThreads.add(thread);
		}
	}
	
	public void shutdown() {
		shutDownFlag = true;
		for (int i = 0; i < totalThreads; ++i) {
			Task<Object> t = new Task<>(Executors.callable(new ShutDown()), Priority.LOW.getPriorityVal() - 1);
			queue.enqueue(t);
		}
	}
	
	public boolean awaitTermination(int timeOut, TimeUnit unit) throws InterruptedException {
		for (int i = 0; i < totalThreads; ++i) {
			Thread thread = WorkingThreads.poll(timeOut, unit);
			if (thread == null) {
				return false;
			}
			
			thread.join();
		}
		
		return true;
	}

	public void pause() {
		pauseNumberOfThreads = totalThreads;
		class Pause implements Runnable{
			@Override
			public void run() {
				try {
					pauseSemaphor.acquire(); ;
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
		pauseSemaphor.release(pauseNumberOfThreads);
		pauseNumberOfThreads = 0;
	}
}

