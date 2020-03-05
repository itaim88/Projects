import static java.lang.Math.*;

class Point2D {

		public static void foo(Integer i) {System.out.println("Integer");}
		public static void foo(short i) {System.out.println("s");}
		//public static void foo(long i) {System.out.println("long");}
		//public static void foo(int i) {System.out.println("int");}
		public static void foo(int ...i) {System.out.println("int...");}
		public static void foo(Long i) {System.out.println("Long");}
		
	public static void main(String[] args) {
		foo(10);
		
	double x =10;
	x = pow(2,10);
	System.out.println(x);
	}

}
