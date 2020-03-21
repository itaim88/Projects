package il.co.ilrd.concurrency;

public class ThreadStartStopFlag extends Thread {
	private volatile boolean flag = true;
    
	public void stopRunning() {
		flag = false;
	}
     
	@Override
	public void run() {
		while (flag){
			System.out.println("I am running....");
		}
         
		System.out.println("Stopped Running....");
	}
	
	public static void main(String[] args) {
		ThreadStartStopFlag thread = new ThreadStartStopFlag(); 
		thread.start();
         
        try {
        	Thread.sleep(100);
        } catch (InterruptedException e) {
        	e.printStackTrace();
        	}
            
        thread.stopRunning();
    } 
}
