package il.co.ilrd.ThreadPool;

import static org.junit.jupiter.api.Assertions.*;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.TimeUnit;

import il.co.ilrd.ThreadPool.ThreadPool.Priority;

class Test {

	@org.junit.jupiter.api.Test
	void test() throws InterruptedException, ExecutionException {
		int NUM_OF_THREADS = 4;
		ThreadPool t = new ThreadPool(NUM_OF_THREADS);
		Future<?> f1 = t.submit(new Runnable() {
			@Override
			public void run() {
				System.out.println("first task done!");
				
			}
			
		} , Priority.MID); 
		
		Future<String> f2 = t.submit(() -> System.out.println("Task #2 is done!"),  Priority.MID, "Task #2");
		Future<Integer> f3 = t.submit(() -> 2 * 3);
	
		//Thread.sleep(10000);

		System.out.println(f1.get());
		System.out.println(f2.get());
		System.out.println(f2.get());
		int a = f3.get();
		assertEquals(6,a);  
		
			t.pause();
		
		
		Future<String> f4 = t.submit(() -> System.out.println("Task #4 is done!"),  Priority.MID, "Task #4");
		t.resume();
		
		Thread.sleep(100);
		t.setNumOfThreads(2);
		
		
		t.pause();
		
		for (int i = 0; i < 30; ++i) {
			Future<String> f5 = t.submit(() -> System.out.println("Task #5 is done!"),  Priority.MID, "Task #5");
			Future<String> f6 = t.submit(() -> System.out.println("Task #6 is done!"),  Priority.LOW, "Task #6");
			Future<String> f7 = t.submit(() -> System.out.println("Task #7 is done!"),  Priority.HIGH, "Task #7");
		}
	
		Thread.sleep(1000);
		t.resume();
		
		Future<?> f_long = t.submit(new Runnable() {
			@Override
		public void run() {
				for(int i = 0; i < 1_000_000_000; ++i) {
					for(int j = 0; j < 1_000_000_000; ++j) {
						
					}
				}
				
			}
			
		} , Priority.MID); 
	
		t.shutdown();
		System.out.println(t.awaitTermination(3, TimeUnit.SECONDS));

		try { Future<String> f8 = t.submit(() -> System.out.println("Task #8 is done!"),  Priority.HIGH, "Task #8");
		}catch (RejectedExecutionException e) {
			System.out.println("shutdown");
	
		}
	}

}
