
public class MainWS3 {

	public static void main(String[] args) {
	
		//BaseExtender extender1 = new BaseExtender();
		//BaseWS3 b = new BaseWS3();
		//BaseWS3 b1 = new BaseWS3(2);
		//BaseExtender extender = new BaseExtender();
		
		shape s = new shape();
		shape s1 = new shape("blue", false);
	
		System.out.println(s.toString()); 
		System.out.println(s1.toString()); 
		
		Circle c1 = new Circle();
		Circle c2 = new Circle(3);
		System.out.println(c1.toString()); 
		System.out.println(c2.toString()); 
		System.out.println(c2.getArea()); 
		System.out.println(c2.getPerimeter()); 
		
		Circle c3 = new Circle(4,"red",true);
		System.out.println(c3.getPerimeter()); 
		System.out.println(c3.toString());
		System.out.println(c3.getArea()); 
				

		try {
		Class cls = Class.forName(args[0]);
        System.out.println("Name: " + cls.getName());
        System.out.println("class: " + args[0]);
	    System.out.println("classes: " +cls.getClasses());
	    System.out.println("annotations: " + cls.getAnnotations());
	    System.out.println("constructor: " + cls.getConstructors());
	    System.out.println("Feilds: " + cls.getFields());
	    System.out.println("Methods: " + cls.getMethods());
	    System.out.println("modifiers: " + cls.getModifiers());   
		}
		
		catch(ClassNotFoundException ex) {
			System.out.println(ex.toString());
		}	
	}
}
