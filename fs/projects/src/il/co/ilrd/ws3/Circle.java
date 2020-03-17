package il.co.ilrd.ws3;


public class Circle extends shape {

	double radius = 0;
	double pi = Math.PI;
	
	public Circle() {
		
		super();
		radius = 1.0;
	}
	
	public Circle(double radius) {
		
		super();
		this.radius = radius;
	}
	
	public Circle(double radius, String color, boolean filled) {
		
		super(color, filled);
		this.radius = radius;
	}
	
	public void setRadius(double radius) {
		
		this.radius = radius;		
	}
	
	public double getRadius() {
		
		return radius;		
	}
	
	public double getArea() {
		
		return (pi * Math.pow(radius, 2));
	}
	
	public double getPerimeter() {
		
		return (pi * 2 * radius);
	}
	
	@Override
	public String toString() {
		
		return ("raduis"+" "+getRadius() +" "+ super.toString());
	}
	
	
}

	