package il.co.ilrd.GenericSLL;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Iterator;

class Test {

	@org.junit.jupiter.api.Test
	void test() {
		
		SinglyLinkedList<Integer> list1 = new SinglyLinkedList<>();
		SinglyLinkedList<Integer> list2 = new SinglyLinkedList<>();
		SinglyLinkedList<Integer> list3 = new SinglyLinkedList<>();
		SinglyLinkedList<Integer> list4 = new SinglyLinkedList<>();
		
		assertTrue(list1.isEmpty());
		assertEquals(0, list1.size());
		
		list1.pushFront(1);
		assertEquals(1, list1.size());
		assertFalse(list1.isEmpty());
		SinglyLinkedList.Print(list1);
		System.out.println();
		list1.pushFront(2);
		list1.pushFront(3);
		list1.pushFront(4);
		assertEquals(4, list1.size());
		assertFalse(list1.isEmpty());
		SinglyLinkedList.Print(list1);
		System.out.println();
		Integer i = 4;	
		try {
			assertEquals(i, list1.popFront());
		} catch (GenericException e1) {
			
			e1.printStackTrace();
		}
		SinglyLinkedList.Print(list1);
		System.out.println();
		SinglyLinkedList<Integer> revers = SinglyLinkedList.newReverse(list1);
		SinglyLinkedList.Print(revers);
		System.out.println();
		
		list2.pushFront(8);
		list2.pushFront(9);
		list2.pushFront(10);
		list2.pushFront(11);
		
		SinglyLinkedList<Integer> mergelist = SinglyLinkedList.Merge(list1, list2);
		SinglyLinkedList.Print(mergelist);
		System.out.println();
		assertEquals(7, mergelist.size());
		assertEquals((Integer)11, mergelist.find(11).next());
		

		try {
			list3.pushFront(67);
			Iterator<Integer> iter = list3.iterator();
			iter.next();
			list3.pushFront(60);
			iter.next();

			System.out.println("Shouldn't get here");
			iter.next();
			
		} catch(Exception e) {
			assertEquals(e.getMessage(), "ERROR: Data Structre have been modified");
		}
		
		try {
			list4.popFront();
		} catch (Exception e) {
			assertEquals(e.getMessage(), "Can't pop from Empty List");
		}
	
	}	

}
