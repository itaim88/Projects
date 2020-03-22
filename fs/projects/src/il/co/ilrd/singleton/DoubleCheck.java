package il.co.ilrd.singleton;

	public class DoubleCheck {
	private static DoubleCheck rs = null;
	
	private DoubleCheck() {}
	
	private static DoubleCheck getResource() {
		if (rs == null) {
			synchronized( DoubleCheck.class) {
				if (rs == null) {
					rs = new DoubleCheck();
				}
			}
		}
		
		return rs;
	}
    public static void main(String[] args) {
    	DoubleCheck d = DoubleCheck.getResource(); 
    	
    	for (int i = 0; i < 100_000; ++i) {
    		DoubleCheck d2 = DoubleCheck.getResource(); 
    		if (d != d2) {
				System.out.println("Not singleton");
				return;
			}
		}
    	
		System.out.println("singleton");
		
    }
}


