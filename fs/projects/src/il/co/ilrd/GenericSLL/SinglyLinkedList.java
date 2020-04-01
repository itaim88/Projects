package il.co.ilrd.GenericSLL;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class SinglyLinkedList<T> implements Iterable<T> {
	private Node head;
	
	private class Node {
		
		private T data;
		private Node nextNode;

		private Node(T data, Node nextNode) {
			
		}
		public T getData() {
			return data;
		}
		public void setNext(Node next) {
			
		}
		public Node getNext(Node next) {
			return null;
		}
	}
	
	private class listIteratorImp implements Iterator<T>{

		private Node curr;
		
		@Override
		public boolean hasNext() {
			return true;
		}
		
		@Override
		public T next() {
			return null;
		}
	}
	
	@Override
	public Iterator<T> iterator() {
		return null;
	}
	
	public void pushFront(T data) {
		
	}
	public T popFront() {
		return null;
	}
	public int size() {
		return 0;
	}
	public Iterator<T> find(T data) {
		return null;
	}
	public boolean isEmpty() {
		return true;
	}
	public static <E> SinglyLinkedList<E> Merge(SinglyLinkedList<E> list1, SinglyLinkedList<E> list2) {
		return null;
		
	}
	public static <E> SinglyLinkedList<E> newReverse(SinglyLinkedList<E> list) {
	
		return null;
	}
	public static <E> void Print(SinglyLinkedList<E> list) {
		
	}
	
	


}


