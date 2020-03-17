package il.co.ilrd.singleton;

public class Sync {
	private Sync rs = null;
	
	public Sync getResource() {
			synchronized(this) {
				if (rs == null) {
					rs = new Sync();
				}
			}
			
		return rs;
	}
}
