package il.co.ilrd.reflection;

import java.lang.reflect.*;

public class ObjectAnalyzer  {
	
	public static void main(String[] args) throws Exception {
	
	Class fooObj = Foo.class;
	ObjectAnalyzer obj = new ObjectAnalyzer();
	
	Class fooSuper = fooObj.getSuperclass();
	int fooModifire = fooObj.getModifiers();
	Class[] interfaces = fooObj.getInterfaces();
	Field[] fields = fooObj.getDeclaredFields();
	Class[] intefaces = fooObj.getInterfaces();
	Field[] f = obj.getClass().getDeclaredFields();
	
	System.out.println("Foo super class is: "+fooSuper);
	System.out.println("Foo Modifiers: "+fooModifire);	
	
	for(Field i : fields) {
		System.out.println(i);
	}
	//
		
	Method m = Foo.class.getDeclaredMethod("Foo1");
	m.setAccessible(true);
	m.invoke(null);
	
	
	}

}
