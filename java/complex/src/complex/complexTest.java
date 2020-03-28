package complex;

import static org.junit.Assert.*;
import org.junit.jupiter.api.Test;

class complexTest {

	Complex obj1 = new Complex(1,1);
	Complex obj2 = new Complex(2,3);
	Complex res1_2 = new Complex();
	Complex setTest = new Complex(9,9);
	
	@Test
	void testMath() {
		System.out.println("test Math");
		
		res1_2 = obj1.add(obj2);
		assertEquals(3, res1_2.getReal(),5);
		assertEquals(4, res1_2.getImg(),3);
		System.out.println(res1_2.toString());
		
		res1_2 = obj2.subtract(obj1);
		assertEquals(1, res1_2.getReal(),3);
		assertEquals(2, res1_2.getImg(),3);
		System.out.println(res1_2.toString());
	
		res1_2 = obj2.multiplyBy(obj1);
		System.out.println(res1_2.toString());
		assertEquals(-1, res1_2.getReal(),3);
		assertEquals(5, res1_2.getImg(),3);
		
		res1_2 = obj2.divideBy(obj1);
		System.out.println(res1_2.toString());
		assertEquals((2.5), res1_2.getReal(),3);
		assertEquals((0.5), res1_2.getImg(),3);
		
		System.out.println("end test Math");	
	}
	
	@Test
	void testSet() {
		System.out.println("test set");
		
		System.out.println(setTest.toString());
		setTest.setImg(7);
		setTest.setReal(8);
		assertEquals(8, setTest.getReal(),3);
		assertEquals(7, setTest.getImg(),3);
		
		setTest.setValue(0, 1);
		assertEquals(0, setTest.getReal(),3);
		assertEquals(1, setTest.getImg(),3);
		
		assertEquals(false, setTest.isReal());
		assertEquals(true, setTest.isImg());
		
		setTest.setValue(1, 1);
		assertEquals(false, setTest.isReal());
		assertEquals(false, setTest.isImg());
		
		setTest.setValue(0, 0);
		assertEquals(true, setTest.isReal());
		assertEquals(true, setTest.isImg());
		
		System.out.println("test set");
	}
	
	@Test
	void testparse() {
		
		String str = "4+2.83i";
		Complex c = Complex.parse(str);
		assertEquals(4, c.getReal(),4);
		assertEquals(2.83, c.getImg(),4);
		
		str = "4 + 2.83i";
		c = Complex.parse(str);
		assertEquals(4, c.getReal(),4);
		assertEquals(2.83, c.getImg(),4);
		
		str = "-4 + -2.83i";
		c = Complex.parse(str);
		assertEquals(-4, c.getReal(),4);
		assertEquals(-2.83, c.getImg(),4);
		
	}
	
	@Test
	void testComperTo() {
		
		Complex c = new Complex(8,10);
		Complex c1 = new Complex(8,10);

		assertEquals(0, c.compareTo(c1));
		
		c.setValue(8, 14);
		assertNotEquals(0, c.compareTo(c1));
	}
	
	@Test
	void testRegExp() {
		Complex c = new Complex();
		
		c = Complex.regexParse("4+3i");
		
		System.out.println("parse exp" + c.toString());	
	}
	
	@Test
	void testEquals() {
		Complex c = new Complex(2,4);
		Complex c1 = new Complex(2,4);
		Complex c2 = new Complex(2,6);
		
		assertTrue(c.equals(c1));
		assertFalse(c2.equals(c1));
	} 
}
