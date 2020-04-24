package il.co.ilrd.factory;

public class AnimalFactory {
	String color;

	public AnimalFactory(String color) {
		this.color = color;
	}
	
	
	public Dog getDog() {
		return new Dog(this.color);
	}
	
	public Cat getCat(String str) {
		return new Cat(this.color);
	}
	
	public Bird getBird() {
		return new Bird(this.color);
	}
}
