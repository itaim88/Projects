package vendingMachine;

public class VendingMachine {
	private double balance = 0d;
	private State state;
	private Monitor imp;
	
	public VendingMachine(int[] stock, Monitor imp) {
		for (Product item : Product.values()) {
			item.setStock(stock[item.ordinal()]);   
		}
		
		this.imp = imp;
		state = State.WAIT_FOR_COIN;
	}

	public void insertCoin(double coin) {state.gotCoin(this, coin);}
	public void order(int key) {state.gotOrder(this, key);}
	public void returnChange() {
		imp.print("Your change is " + String.valueOf(balance));
		balance = 0d;
	}
	
	public enum State {
		WAIT_FOR_COIN {
			@Override
			public void gotOrder(VendingMachine mac, int key) {
				Product[] products = Product.values();
				for (Product item : products) {
					if (key == item.getKey()) {
						mac.imp.print("Your order is "+item.name() + " the price is "+ item.getPrice());	
						return;
					}
				}
				mac.imp.print("Wrong key");	
			}
		},
		
		WAIT_FOR_ORDER {
			@Override
			public void gotOrder(VendingMachine mac, int key) {
				Product drink;
				Product[] products = Product.values();
				
				for (int i = 0; i < products.length ; ++i) {
					
					if (key == products[i].getKey()) {
						drink = products[i];
						
						if (drink.isAvilable()) {	
							
							if  (drink.getPrice() <= mac.balance) {
								mac.balance -= drink.getPrice();
								drink.setStock(drink.getStock() - 1);
								mac.imp.print("The product is: " +drink.toString());
							}
							
							else {mac.imp.print("Not enoåth money, the price is: " +drink.getPrice());}		
						}
						
						else {
							mac.imp.print(drink.getStock()+" "+drink.toString() +" products in the machine");
						}
					}
				}
				
				mac.state = State.WAIT_FOR_COIN;
				mac.returnChange();
			}	
		
		};

		private void gotCoin(VendingMachine mc, double coin) {
			mc.balance += coin;
			mc.state = State.WAIT_FOR_ORDER;
		}
		
		public abstract void gotOrder(VendingMachine mac, int key);
	
	}	
}
