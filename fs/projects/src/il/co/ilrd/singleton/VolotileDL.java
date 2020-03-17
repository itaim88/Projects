package il.co.ilrd.singleton;

public class VolotileDL {
	private volatile VolotileDL rs = null;
	
	private VolotileDL() {}
	
	public VolotileDL getResource() {
		if (rs == null) {
			synchronized(this) {
				if (rs == null) {
					rs = new VolotileDL();
				}
			}
		}
		
		return rs;
	}
}


