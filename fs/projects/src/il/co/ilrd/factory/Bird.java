package il.co.ilrd.factory;

public class Bird implements Animal {
	String color;
	
	public Bird(String color) {
		this.color = color;
		System.out.println(color + " Bird Ctor");
	}
	
	
	@Override
	public String makeSound(String str) {
		System.err.println("Squik");
		return "Squik";
	}

}
