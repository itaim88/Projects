package vendingMachine;

import org.junit.jupiter.api.Test;

class VendingTest {

	@Test
	void test() {
		VendingMachine m = new VendingMachine();
		
		m.insertCoin(11);
		m.Order(Product.COLA.getKey());

		m.insertCoin(14);
		m.Order(Product.COLA.getKey());
		
		m.insertCoin(11);
		m.Order(Product.COLA.getKey());
		
		m.insertCoin(2);
		m.Order(Product.WATER.getKey());
		/*m.insertCoin(14);
		m.Order(Product.COLA);
		
		assertEquals(true, Product.COLA.isAvilable()); 
		m.insertCoin(165);
		m.Order(Product.COLA);
		
		assertEquals(false, Product.COLA.isAvilable()); 
		m.insertCoin(11);
		m.Order(Product.COLA);*/

		

	}

}
