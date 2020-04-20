package il.co.ilrd.generic;

import java.util.ArrayList;
import java.util.List;

public class TestWs {

	@SuppressWarnings("unused")
	public static void main(String[] args) {
		
		@SuppressWarnings("rawtypes")
		List rawList;
		List<?> listOfAnyType = new ArrayList<>();

		List<Object> listOfObject = new ArrayList<Object>();
		List<String> listOfString = new ArrayList<String>();
		List<Integer> listOfInteger = new ArrayList<>();

		rawList = listOfInteger;
		rawList = listOfAnyType;
		rawList = listOfString;
		rawList = listOfObject;
		listOfAnyType = listOfString;
		listOfAnyType = listOfInteger;
		listOfAnyType = listOfObject;
		//listOfObject = (List<Object>)listOfString;
	}

}
