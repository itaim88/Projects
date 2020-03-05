package test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import com.singly.linked.list.listIterator;
import com.singly.linked.list.singlyLinkedList;

class sllTest {

	@Test
	void test1() {
		singlyLinkedList sll1 = new singlyLinkedList();
		Integer data1 = 10;
		Integer data2 = 5;

		assertEquals(true, sll1.isEmpty());
		assertEquals(0, sll1.size());
		
		sll1.pushFront(data1);
		assertEquals(false, sll1.isEmpty());
		assertEquals(1, sll1.size());
		
		sll1.pushFront(data2);
		assertEquals(2, sll1.size());
	}
	
	@Test
	void test2() {
		singlyLinkedList sll1 = new singlyLinkedList();
		Integer data1 = 10;
		Integer data2 = 5;
		Integer data3 = 12;
		Integer data4 = 20;
		
		sll1.pushFront(data1);
		sll1.pushFront(data2);
		sll1.pushFront(data4);
		
		assertEquals(data1, sll1.find(data1).next());
		assertEquals(data2, sll1.find(data2).next());
		assertEquals(data4, sll1.find(data4).next());
		assertEquals(null, sll1.find(data3));
	}
	
	@Test
	void test3() {
		singlyLinkedList sll1 = new singlyLinkedList();
		Integer data1 = 10;
		Integer data2 = 5;
		Integer data4 = 20;
		
		sll1.pushFront(data1);
		sll1.pushFront(data2);
		sll1.pushFront(data4);
		
		listIterator iter = sll1.begin();
		
		assertTrue(iter.hasNext());
		assertEquals(iter.next(), null);
		
		assertTrue(iter.hasNext());
		assertEquals(iter.next(), data4);
		
		assertTrue(iter.hasNext());
		assertEquals(iter.next(), data2);
		
		assertFalse(iter.hasNext());
		assertEquals(iter.next(), data1);
	}
	
	@Test
	void test4() {
		singlyLinkedList sll1 = new singlyLinkedList();
		Integer data1 = 10;
		Integer data2 = 5;
		Integer data3 = 20;
		
		sll1.pushFront(data1);
		sll1.pushFront(data2);
		sll1.pushFront(data3);
		
		assertEquals(sll1.popFront(), data3);
		assertEquals(sll1.popFront(), data2);
		assertEquals(sll1.popFront(), data1);
	}
}
