package il.co.ilrd.ThreadPool;

import static org.junit.jupiter.api.Assertions.*;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.RejectedExecutionException;

import il.co.ilrd.ThreadPool.ThreadPool.Priority;

class Test {

	@org.junit.jupiter.api.Test
	void test() throws InterruptedException, ExecutionException {
		int NUM_OF_THREADS = 1;
		ThreadPool t = new ThreadPool(NUM_OF_THREADS);
		Future<Object> f1 = t.submit(new Runnable() {
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
		int a = f3.get();
		assertEquals(6,a);  
		

			t.pause();
		
		
		Future<String> f4 = t.submit(() -> System.out.println("Task #4 is done!"),  Priority.MID, "Task #4");
		t.resume();
		
		Thread.sleep(100);
		t.setNumOfThreads(3);
		
		
		t.pause();
		
		for (int i = 0; i < 10; ++i) {
			Future<String> f5 = t.submit(() -> System.out.println("Task #5 is done!"),  Priority.MID, "Task #5");
			Future<String> f6 = t.submit(() -> System.out.println("Task #6 is done!"),  Priority.LOW, "Task #6");
			Future<String> f7 = t.submit(() -> System.out.println("Task #7 is done!"),  Priority.HIGH, "Task #7");
		}
		Thread.sleep(1000);
		t.resume();
		
	
		t.shutdown();
		
	
		Thread.sleep(1000);
		
		try { Future<String> f8 = t.submit(() -> System.out.println("Task #8 is done!"),  Priority.HIGH, "Task #8");
		}catch (RejectedExecutionException e) {
			System.out.println("shutdown");
	
		}
		
		//t.setNumOfThreads(3);
		//t.setNumOfThreads(2);
		//Thread.sleep(10000);
		//Future<String> f3 = t.submit(() -> System.out.println("Task #3 is done!"),  Priority.MID, "hello");
		
	}

}
