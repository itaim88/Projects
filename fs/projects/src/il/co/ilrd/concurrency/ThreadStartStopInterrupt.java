package il.co.ilrd.concurrency;

public class ThreadStartStopInterrupt extends Thread {

	    @Override
	    public void run()
	    {
	        while (!Thread.interrupted())
	        {
	            System.out.println("I am running....");
	        }
	         
	        System.out.println("Interrupt Stopped Running.....");
	    }
	
	    public static void main(String[] args) 
	    {
	    	ThreadStartStopInterrupt thread = new ThreadStartStopInterrupt();
	         
	        thread.start();
	         
	        try
	        {
	            Thread.sleep(100);
	        } 
	        catch (InterruptedException e) 
	        {
	            e.printStackTrace();
	        }
	         
	        //interrupting the thread
	         
	        thread.interrupt();
	    }   
	}

