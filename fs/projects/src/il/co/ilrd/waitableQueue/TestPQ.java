package il.co.ilrd.waitableQueue;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;
import java.util.concurrent.TimeUnit;

class TestPQ {
    WaitableQueue<String> q = new WaitableQueue<>();

    class RunnableDequeue implements Runnable {
        @Override
        public void run() {
            try {
                System.out.println("dequeue: " + q.dequeue());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    class RunnableEnqueue implements Runnable{

        @Override
        public void run() {
            q.enqueue(Thread.currentThread().getName());
        }
    }

    class RunnableDequeueWithTime implements Runnable {
        @Override
        public void run() {
            try {
                System.out.println("dequeueWithTimeot: " + q.dequeueWithTimeot(6));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

	@Test
	void test() throws InterruptedException {
		for (int i = 0; i < 5; ++i) {
			new Thread(new RunnableDequeueWithTime()).start();
		}
        for (int i = 0; i < 20; ++i) {
            new Thread(new RunnableEnqueue()).start();
        }
       
        for (int i = 0; i < 10; ++i) {
            new Thread(new RunnableDequeueWithTime()).start();
        }
        for (int i = 0; i < 10; ++i) {
            new Thread(new RunnableEnqueue()).start();
        }
        
        for (int i = 0; i < 10; ++i) {
            new Thread(new RunnableDequeue()).start();
        }
        for (int i = 0; i < 20; ++i) {
            new Thread(new RunnableDequeueWithTime()).start();
        }
       
        for (int i = 0; i < 100; ++i) {
            new Thread(new RunnableEnqueue()).start();
        }
           
    }
}
