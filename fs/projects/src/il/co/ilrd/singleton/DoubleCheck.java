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
    	DoubleCheck d2 = DoubleCheck.getResource(); 
 
        System.out.println(d == d2); // return true
    }
}


