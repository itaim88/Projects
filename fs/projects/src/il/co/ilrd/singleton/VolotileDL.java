package il.co.ilrd.singleton;

public class VolotileDL {
	private static volatile VolotileDL rs = null;
	
	private VolotileDL() {}
	
	private static VolotileDL getResource() {
		if (rs == null) {
			synchronized(VolotileDL.class) {
				if (rs == null) {
					rs = new VolotileDL();
				}
			}
		}
		
		return rs;
	}

	public static void main(String[] args) {
		VolotileDL d = VolotileDL.getResource(); 
		VolotileDL d2 = VolotileDL.getResource(); 

		System.out.println(d == d2); // return true
	}
}



