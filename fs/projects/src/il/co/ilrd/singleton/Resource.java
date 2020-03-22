package il.co.ilrd.singleton;

//HOLDER singleton//
public class Resource {
	private Resource() {}
	
	 static class Holder {
		static final Resource INSTANCE = new Resource();
	}
	
	public static Resource getInstance() {
		return Holder.INSTANCE;
	}

    public static void main(String[] args) {
    	Resource r1 = Resource.getInstance();
    	Resource r2 = Resource.getInstance();
    	
    	for (int i = 0; i < 100; ++i) {
    		System.out.println(r1 == r2); 
		}  
   }
}


