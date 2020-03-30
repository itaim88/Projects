package il.co.ilrd.Exceptions;

import java.io.IOException;

public class Foo {
	
	public void func1() throws IOException {
		
	}
	
	public void func2() {
		throw new NullPointerException("test null");	
	}

	public static void main(String[] args) {
		Foo foo = new Foo();
		
		try {
			foo.func1();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		foo.func2();
	}

}
