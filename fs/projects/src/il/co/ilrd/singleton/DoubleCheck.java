package il.co.ilrd.singleton;

	public class DoubleCheck {
	private DoubleCheck rs = null;
	
	private DoubleCheck() {}
	
	public DoubleCheck getResource() {
		if (rs == null) {
			synchronized(this) {
				if (rs == null) {
					rs = new DoubleCheck();
				}
			}
		}
		
		return rs;
	}
}
