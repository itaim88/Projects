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
    	
    	for (int i = 0; i < 100_000; ++i) {
    		Resource r2 = Resource.getInstance();
    		if (r1 != r2) {
				System.out.println("Not singleton");
				return;
			}
		}
		System.out.println("singleton");
    
   }
}


