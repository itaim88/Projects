package il.co.ilrd.ws3;


public class BaseWS3 {
	
	public int var1 = 10;
	String str1 = "Hello"; 
	
	public BaseWS3(){
		System.out.println("constractor");
	}
	
	static{
		
		int i = 9;
		System.out.println("static block " + i);
	}
	
	{
		int blk = 10;
		System.out.println("instance block " +blk);
	}
	
	 public BaseWS3(int x){
		System.out.println("constractor 2");
	}

}
