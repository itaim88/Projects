package homeTests;

import java.util.Arrays;
import java.util.Stack;

public class StackWithMin {
	
	Stack<Element> s1;

	private class Element {
		private int data;
		private int min;
		
		private Element(int data, int min) {
			this.data = data;
			this.min = min;
		}

		public int getData() {
			return data;
		}

		public int getMin() {
			return min;
		}

	}

	public StackWithMin() {
		s1 = new Stack<>();
	}
		
	public void push(int data) {
		if (null == s1.peek()) {
			s1.push(new Element(data, data));
		}
		int min = (data > s1.peek().getMin()) ? s1.peek().getMin() : data;
		s1.push(new Element(data, min));
	}
		
	public int peek() {
		if (null == s1.peek()) {return -1;}
		return s1.peek().getData();
	}
	
	public int min() {
		if (null == s1.peek()) {return -1;}
		return s1.peek().getMin();
	}
	
	public void pop() {
		if (null == s1.peek()) {return;}
		s1.pop();
	}
	   public static int []f = new int[7];
		  public static int fib(int n) {

		   	  // System.out.println(f[1]);	 
		        	if (n <= 1)
		            	return (f[n] = n);
		      	 
		        	if (f[n] != 0)
		            	return f[n];
		    
		        	f[n] = (fib(n-2) + fib(n-1));
		      	 
		        	return f[n];
		  }

	
	static int revNum (int num){
        int reversed = 0;
        
        while (num > 0) {
        //for(;num != 0; num /= 10) {
            int dig = num % 10;
        	num /=10;
            reversed = (reversed * 10) + dig;
        }
	
	return reversed;
}


    static String encodeStr1(String str) {
	StringBuilder code = new StringBuilder();
	int size = str.length();
	int count = 0;
	char curr, prev = str.charAt(0);

	for (int i = 0; i < size; ++i) {
	    curr = str.charAt(i);
		if (curr != prev) { 
			code.append(prev);
			code.append(count);
			count = 0;
		}
		++count;
		prev = curr;
	}
	
	code.append(prev);
	code.append(count);
	
	return code.toString();
}

	public static void main(String[] args) {
		StackWithMin s = new StackWithMin();
		System.out.println(s.fib(6));
		System.out.println(s.encodeStr1("abccd"));
		//System.out.println(s.revNum(1200)); 
	}

}

