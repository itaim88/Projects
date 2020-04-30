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
	
	public static void main(String[] args) {
		System.out.println(Quiz.isPermutation("hello", "lohel"));
		System.out.println(Quiz.isPermutation("helio", "lohel"));
	}
}
