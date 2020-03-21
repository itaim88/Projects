package il.co.ilrd.concurrency;

public class RunnableStartStop implements Runnable {
    private boolean doStop = false;

    public synchronized void doStop() {
    	this.doStop = true;
    }

    private synchronized boolean keepRunning() {
    	return this.doStop == false;
    }

    @Override
    public void run() {
    	while(keepRunning()) {
    		System.out.println("Running");

    		try {
    			Thread.sleep(1000);
    		} catch (InterruptedException e) {
    			e.printStackTrace();
    		}
         
    	}
    	
    	System.out.println("Interrupt Stopped Running.....");
    }
    
    public static void main(String[] args) {
    	RunnableStartStop myRunnable = new RunnableStartStop();
    	Thread thread = new Thread(myRunnable);
    	thread.start();

    	try {
    		Thread.sleep(10_000L);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        myRunnable.doStop();
    }
}