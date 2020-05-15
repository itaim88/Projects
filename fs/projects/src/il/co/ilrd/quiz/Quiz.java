package il.co.ilrd.quiz;

import java.util.HashMap;
import java.util.Map;



public class Quiz {
	
	public static boolean isPermutation(String s, String t) {
		if(s.length() != t.length()) {
			return false;
		}
		
		Map<Character, Integer> sMap = new HashMap<>();
		Map<Character, Integer> tMap = new HashMap<>();
		
		for (int i = 0; i < s.length(); ++i) {
			Character cs = s.charAt(i);
			Character ct = t.charAt(i);
			try {
				sMap.put(cs, sMap.get(cs) + 1);
			} catch(NullPointerException e) {
				sMap.put(cs, 1);
			}
			try {
				tMap.put(ct, tMap.get(ct) + 1);				
			} catch(NullPointerException e) {
				tMap.put(ct, 1);		
			}
		}
		
		for(int i = 0; i<s.length(); i++) {
			char sChar = s.charAt(i);
			
			if(sMap.get(sChar) != tMap.get(sChar))
				return false;
		}
		
		return true;
	}
	
	private class CircularBuffer {
		private int [] arr;
		private int nextFreeIndex;
		private int lastIndex;
		private int sizeN;
	    
	    public CircularBuffer(int sizeN){
			this.sizeN = sizeN;
			arr = new int[sizeN];
	    }
	    public void record(int order_id) {
			arr[nextFreeIndex] = order_id;
			lastIndex = nextFreeIndex;
			nextFreeIndex = (nextFreeIndex + 1) % sizeN;
	    }
	    public int getLast(int NthFromLast) {
	    	return arr[(sizeN + lastIndex - NthFromLast) % sizeN];
	    }
	}
	    
	public static void main(String[] args) {
		System.out.println(Quiz.isPermutation("hello", "lohel"));
		System.out.println(Quiz.isPermutation("helio", "lohel"));
		
		Quiz q = new Quiz();
		CircularBuffer c = q.new CircularBuffer(3);
		c.record(1);
		c.record(55);
		c.record(100);
		c.record(4000);
		
		System.out.println(c.getLast(3));
	}
}
