package il.co.ilrd.ThreadPool;

import java.util.concurrent.Callable;

import java.util.concurrent.CancellationException;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

import il.co.ilrd.waitableQueue.WaitableQueue;

/**
 * NOT THREAD SAFE THREAD POOL
 * 
 * @author Itai Marienberg
 */

public class ThreadPool {
	private int totalThreads;
	private WaitableQueue<Task<?>> queue;
	private LinkedBlockingDeque<WorkerThread> workingThreads = new LinkedBlockingDeque<>();
	private boolean shutDownFlag = false;
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
		LOW (1),
		MID (5),
		HIGH (10);

		private int priorityVal;
		
		private Priority(int priorityVal) {
			this.priorityVal = priorityVal;
		}
		
		private int getPriorityVal(){
			return priorityVal;
		}
	}
	
	private class WorkerThread extends Thread {
		private volatile boolean workFlag = true;
	
		@Override
		public void run() {
		
			while(workFlag) {
				try {
					queue.dequeue().executeTask();
				} catch (InterruptedException e) {
					e.printStackTrace();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
		private void disable() {
			workFlag = false;
		}
	}

	private class Task<T> implements Comparable<Task<T>>{
		private int priority;
		private Callable<T> callable;
		private FutureKeeper<T> FutureKeeper = new FutureKeeper<>();
		private Semaphore resultBlockSem = new Semaphore(0);
		
		private Task(Callable<T> callable, int priority) {
			this.callable = callable;
			this.priority = priority;
		}
		
		private void executeTask() throws Exception {
			if(!FutureKeeper.cancelleFlag) {
				try {
					FutureKeeper.returnVal = callable.call();
				} finally {
					FutureKeeper.completeFlag = true;
					 resultBlockSem.release();
				}
			}
		}

		@Override
		public int compareTo(Task<T> task) {
			return task.priority - priority;
		}
		
		private class FutureKeeper<V> implements Future<V> {
			private volatile boolean completeFlag = false;
			private volatile boolean cancelleFlag = false;
			private V returnVal = null;
			
			@Override
			public boolean cancel(boolean mayInterruptIfRunning) {
				cancelleFlag = true;
				return !FutureKeeper.isDone();
			}

			@Override
			public V get() throws CancellationException, InterruptedException {
				if(!cancelleFlag) {
					resultBlockSem.acquire();
					
					return returnVal;
				}
				
				throw new CancellationException("task is cancelled");
			}

			@Override
			public V get(long time, TimeUnit unit) throws TimeoutException, CancellationException, InterruptedException {
				if(cancelleFlag) {
					throw new CancellationException("task is cancelled");
				}
				
				resultBlockSem.tryAcquire(time , unit);
				return returnVal;
			}
			
			@Override
			public boolean isCancelled() {return cancelleFlag;}
			@Override
			public boolean isDone() {return completeFlag;}
			
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
			throw new RejectedExecutionException("can`t submit task after shutdown");
		}
		
		try {
			Task<T> t = new Task<>(callable, priority.getPriorityVal());
			queue.enqueue(t);
			return t.FutureKeeper;
	
		} catch(NullPointerException e) {
			throw new NullPointerException();			
		}
	}
	
	public void setNumOfThreads(int newThreadNumber) {
		
		if (totalThreads <= newThreadNumber) {
			for (int i = 0; i < newThreadNumber - totalThreads; ++i) {
				new WorkerThread().start();
			}
		}
		
		else  {
			for (int i = 0; i < totalThreads - newThreadNumber; ++i) {
				Task<Object> t = new Task<>(Executors.callable(() -> {
					((WorkerThread)Thread.currentThread()).disable();
				}), Priority.HIGH.getPriorityVal() + 1);
				queue.enqueue(t);
			}	
		}
		totalThreads = newThreadNumber;
	}
	
	public void shutdown() {
		shutDownFlag = true;
		for (int i = 0; i < totalThreads; ++i) {
			Task<Object> t = new Task<>(Executors.callable(() -> {
				WorkerThread thread = (WorkerThread)Thread.currentThread();
				thread.disable();
				workingThreads.add(thread);	
			}), Priority.LOW.getPriorityVal() - 1);
			queue.enqueue(t);
		}
	}
	
	public boolean awaitTermination(long timeOut, TimeUnit unit) throws InterruptedException {
		long timeInMiliSec = TimeUnit.MILLISECONDS.convert(timeOut, unit);
		long startTime = System.currentTimeMillis();
		
		for (int i = 0; i < totalThreads; ++i) {
			Thread thread = workingThreads.poll(timeInMiliSec - (System.currentTimeMillis() - startTime),
																				TimeUnit.MILLISECONDS );
			if (thread == null) {
				return false;
			}
			
			thread.join();
		}
		
		return true;
	}

	public void pause() {
		for (int i = 0; i < totalThreads; ++i) {
			Task<Object> t = new Task<>(Executors.callable(() -> {
			try {
				pauseSemaphor.acquire(); 
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			}), Priority.HIGH.getPriorityVal() + 1);
			queue.enqueue(t);
		}
		
		pauseNumberOfThreads = totalThreads;
	}
	
	public void resume() {
		pauseSemaphor.release(pauseNumberOfThreads);
		pauseNumberOfThreads = 0;
	}
}

