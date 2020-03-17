package il.co.ilrd.vending_machine;

import org.junit.jupiter.api.Test;

class VendingTest {

	@Test
	void test() {
		int[] pruducts = {2,2,5,4,6};
		int[] pruducts2 = {5,3,3,1,0};
		Monitor imp = new MonitorIMP();
		
		VendingMachine m = new VendingMachine(pruducts, imp);
		VendingMachine m2 = new VendingMachine(pruducts2, imp);
		
		m.order(11);
		
		m.insertCoin(11);
		m.order(Product.COLA.getKey());

		m.insertCoin(14);
		m.order(Product.COLA.getKey());
		
		m.insertCoin(11);
		m.order(Product.COLA.getKey());
		
		m2.insertCoin(22);
		m2.order(Product.COLA.getKey());
		
		m.insertCoin(2);
		m.order(Product.WATER.getKey());
		m.insertCoin(14);
		m.order(Product.TUTIT.getKey());
		
		m.insertCoin(11);
		m.order(Product.WATER.getKey());
		
		m.insertCoin(100);
		m.returnChange();
		
	}
}
