package il.co.ilrd.ThreadPool;

import static org.junit.jupiter.api.Assertions.*;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
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
		
		Future<String> f2 = t.submit(() -> System.out.println("Task #2 is done!"),  Priority.MID, "hello");
		Future<Integer> f3 = t.submit(() -> 2 * 3);
	
		//Thread.sleep(10000);

		System.out.println(f1.get());
		System.out.println(f2.get());
		int a = f3.get();
		assertEquals(6,a);  
		
		for(int i = 0; i < NUM_OF_THREADS; ++i) {
		//	t.pause();
		}
		
		//t.resume();
		//t.shutdown();
		t.setNumOfThreads(3);
		//t.setNumOfThreads(2);
		//Thread.sleep(10000);
		//Future<String> f3 = t.submit(() -> System.out.println("Task #3 is done!"),  Priority.MID, "hello");
		
	}

}
