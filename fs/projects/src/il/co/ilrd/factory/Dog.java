package il.co.ilrd.factory;

public class Dog implements Animal {
	String color;
	
	public Dog(String color) {
		this.color = color;
		System.out.println(color + " Dog Ctor");
	}
	
	public static Dog getInstance(String str) {
		return new Dog(str);
	}
	
	@Override
	public String makeSound(String str) {
		System.out.println("woooof");
		return "woooof";
	}

}
