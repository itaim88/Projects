package il.co.ilrd.collections;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.*;


public class CollectionWS {

	public static void main(String[] args) {
		
		int[] arr = {4,8,1,-9,99,3};
		
		for (int i = 0; i < arr.length ; ++i ) {
			System.out.println(arr[i]);
		}
		
		System.out.println();
		
		List<Integer> list = new ArrayList<>();
		for (int i : arr) {
	    	list.add(i);
		}
		
		list.sort(null);
		
		for (Integer i : list) {
			System.out.println(i);
		}

		 HashMap<String, Integer> weekDays = new HashMap<>();
		 weekDays.put("Sunday", 1);
		 weekDays.put("Monday", 2);
		 weekDays.put("Tuesday", 3);
		 weekDays.put("Wednesday", 4);
		 weekDays.put("Thursday", 5);
		 weekDays.put("Friday", 6);
		 weekDays.put("Saturday", 7);
	
		 Iterator iter =  weekDays.entrySet().iterator();
		 
		 while (iter.hasNext()) { 
			 Map.Entry mapElement = (Map.Entry)iter.next(); 
			 int num = ((int)mapElement.getValue()); 
			 System.out.println(mapElement.getKey() + " : " + num); 
		}
	        
	        
		 
	}

}
