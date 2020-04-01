package il.co.ilrd.generic;

import java.util.ArrayList;
import java.util.List;

public class TestWs {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		List rawList;
		List<?> listOfAnyType = new ArrayList();

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
