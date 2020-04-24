package il.co.ilrd.factory;

public class Main {

	public static void main(String[] args) {
		
		/****** Class Constructor **************************/
		
		Factory<String, Animal, String> f = new Factory<>();
		
		f.add("Dog", Dog::new);
		f.add("Cat", Cat::new);
		f.add("Bird", Bird::new);
		
		Animal d = f.create("Dog", "Brown");
		Animal c = f.create("Cat", "Pink");
		Animal b = f.create("Bird", "Black");
	
		f.add("myKey", x -> new Bird(x));
		f.create("myKey", "lambda Bird");
		
		/****** Static method **************************/
	
		Factory<String, Animal, String> f1 = new Factory<>();
		f1.add("Dog Static", Dog::getInstance);
		f1.add("Cat Static", Cat::getInstance);
		Animal d1 = f1.create("Cat Static", "Orenge");
		Animal c1 = f1.create("Dog Static", "Lime");
		
		/****** Instance method  **************************/

		Factory<String, Animal, String> f2 = new Factory<>();
		Factory<String, Animal, AnimalFactory> f3 = new Factory<>();
		
		f2.add("Dog Instance", (AnimalFactory) -> new AnimalFactory("RED").getDog());
		Animal dd = f2.create("Dog Instance","bbbb");
		dd.makeSound(null);
		AnimalFactory myCat = new AnimalFactory("yyy");
		f2.add("try", myCat::getCat);

		Animal cat = f2.create("try","bbbb");
		cat.makeSound(null);
		
		f3.add("e", (AnimalFactory) -> new AnimalFactory("the").getDog());
		Animal dd2 = f3.create("e",new AnimalFactory(null));
		
		myLambda lambdaExp = () -> System.out.println("woooof");
		myLambda oneMore = () -> System.out.println("one more");
		
	}
}

	interface myLambda {
		void foo();
		
		default int add(int a, int b) {return a + b;}
	}
