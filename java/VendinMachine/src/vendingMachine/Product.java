package vendingMachine;

public enum Product {
	COLA(1,10d,2),
	TUTIT(2,5d,3),
	ZERO(3,7d,2),
	TEA(4,7d,2),
	WATER(5,6d,1);
	
	private int key;
	private double price;
	private int stock;
	
	private Product(int key, double price, int stock) {	
		this.price = price;
		this.key = key;
		this.stock = stock;
	}

	public int getKey() {return key;}
	public double getPrice() {return price;}
	public int getStock() {return stock;}
	public void setStock(int stock) {this.stock = stock;}
	public boolean isAvilable() {return (0 < getStock());}
}
