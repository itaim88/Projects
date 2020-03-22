package il.co.ilrd.singleton;

public class Sync {
	private static Sync rs = null;
	
	public synchronized static Sync getResource() {
		if (rs == null) {
			rs = new Sync();
		}
		
		return rs;
	}
	
	public static void main(String[] args) {
		Sync d = Sync.getResource(); 
		
		for (int i = 0; i < 100; ++i) {
			Sync d2 = Sync.getResource(); 
			System.out.println(d == d2); 
		}
	}
}



