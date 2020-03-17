package il.co.ilrd.vending_machine;

public enum Product {
	COLA(0,10d,0),
	TUTIT(1,5d,1),
	ZERO(2,7d,2),
	TEA(3,7d,3),
	WATER(4,6d,4);
	
	private int key;
	private double price;
	private int stockIndex;
	
	private Product(int key, double price, int stockIndex) {	
		this.price = price;
		this.key = key;
		this.stockIndex = stockIndex;
	}

	public int getKey() {return key;}
	public double getPrice() {return price;}
	public int getStockIndex() {return this.stockIndex;}
}
