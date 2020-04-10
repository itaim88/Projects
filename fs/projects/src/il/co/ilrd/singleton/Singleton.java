package il.co.ilrd.singleton;

public enum Singleton {

	INSTANCE;


	public static void main(String[] args) {
		
	for (int i = 0; i < 100_000; ++i) {
		Singleton s1 = Singleton.INSTANCE;
		Singleton s2 = Singleton.INSTANCE;
		
		if (s1 != s2) {
			System.out.println("Not singleton");
			return;
		}
	}
	
	System.out.println("singleton");
	}
}