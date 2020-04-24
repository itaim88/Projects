package il.co.ilrd.factory;

public class Cat implements Animal {
	String color;
	
	public Cat(String color) {
		this.color = color;
		System.out.println(color + " Cat Ctor");
	}
	
	public static Cat getInstance(String str) {
		return new Cat(str);
	}
	
	@Override
	public String makeSound(String str) {
		System.out.println("Meaooooo");
		return "Meaooooo";
	}

}
