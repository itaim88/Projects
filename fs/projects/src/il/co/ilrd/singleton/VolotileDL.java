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
		
		for (int i = 0; i < 100_000; ++i) {
			VolotileDL d2 = VolotileDL.getResource(); 
			if (d != d2) {
				System.out.println("Not singleton");
				return;
			}
		}
		
		System.out.println("singleton");
	}
}



