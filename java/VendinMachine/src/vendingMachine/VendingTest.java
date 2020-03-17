package vendingMachine;

import static org.junit.Assert.assertEquals;

import org.junit.jupiter.api.Test;

class VendingTest {

	@Test
	void test() {
		int[] pruducts = {2,2,5,4,6};
		Monitor imp = new MonitorIMP();
		
		VendingMachine m = new VendingMachine(pruducts, imp);
		
		
		m.insertCoin(11);
		m.order(Product.COLA.getKey());

		m.insertCoin(14);
		m.order(Product.COLA.getKey());
		
		m.insertCoin(11);
		m.order(Product.COLA.getKey());
		
		m.insertCoin(2);
		m.order(Product.WATER.getKey());
		m.insertCoin(14);
		m.order(Product.TUTIT.getKey());
		
		assertEquals(false, Product.COLA.isAvilable()); 
		
		
		assertEquals(true, Product.WATER.isAvilable()); 
		m.insertCoin(11);
		m.order(Product.WATER.getKey());
		
		m.insertCoin(100);
		m.returnChange();
	}
}
