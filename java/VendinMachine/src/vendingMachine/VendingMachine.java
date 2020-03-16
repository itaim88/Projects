package vendingMachine;

public class VendingMachine {
	private double balance = 0d;
	private State state;
	
	MonitorIMP monitor = new MonitorIMP();
	
	public VendingMachine() {
		state = State.WAIT_FOR_COIN;
	}
	
	public void insertCoin(double coin) {
		balance += coin;
		state = state.gotCoin();
	}
	
	public void returnChange() {
		monitor.print("Your change is " + String.valueOf(balance));
		balance = 0d;
	}
	
	public void Order(int key) {
		Product[] products = Product.values();
		Product drink;
		
		if (State.WAIT_FOR_COIN == state) {
			return;
		}
		
		for ( int i = 0; i < products.length ; ++i) {
			
			if (key == products[i].getKey()) {
				drink = products[i];
				
				if (drink.isAvilable()) {	
					
					if  (drink.getPrice() <= balance) {
						balance -= drink.getPrice();
						drink.setStock(drink.getStock() - 1);
						monitor.print("The product is: " +drink.toString());
					}
					
					else {monitor.print("Not enoåth money, the price is: " +drink.getPrice());}		
				}
				
				else {
					monitor.print(drink.getStock()+" "+drink.toString() +" products in the machine");
				}
			}
		}
				
		state = state.gotOrder();
		returnChange();
	}
	
	public enum State {
		WAIT_FOR_COIN,
		WAIT_FOR_ORDER;

		public State gotCoin() {return State.WAIT_FOR_ORDER;}
		public State gotOrder() {return State.WAIT_FOR_COIN;}	
	}	
}
