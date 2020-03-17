package vendingMachine;

public enum Product {
	COLA(1,10d),
	TUTIT(2,5d),
	ZERO(3,7d),
	TEA(4,7d),
	WATER(5,6d);
	
	private int key;
	private double price;
	private int stock;
	
	private Product(int key, double price) {	
		this.price = price;
		this.key = key;
	}

	public int getKey() {return key;}
	public double getPrice() {return price;}
	public int getStock() {return stock;}
	public void setStock(int stock) {this.stock = stock;}
	public boolean isAvilable() {return (0 < getStock());}
}
