package il.co.ilrd.GenericSLL;

import java.util.ConcurrentModificationException;
import java.util.Iterator;

public class SinglyLinkedList<T> implements Iterable<T> {
	private Node<T> head = new Node<>(null ,null);
	private volatile int listCounter = 0;
	
	private static class Node<T>  {
	private T data;
	private Node<T> nextNode;
	
	private Node(T data, Node<T> nextNode) {
		this.data = data;
		this.nextNode = nextNode;
	}
		
	public T getData() {
		return data;
	}
	
	public Node<T> getNextNode() {
		return nextNode;
	}
	}
	
	private static class ListIteratorImp<T> implements Iterator<T> {

	private Node<T> currentNode;
	SinglyLinkedList<T> list;
	private volatile int iteratorCounter;
    
	private ListIteratorImp(SinglyLinkedList<T> list) {
		currentNode = list.head;
		this.list = list;
		iteratorCounter = list.listCounter;
	}
	
	@Override
	public boolean hasNext() {

		if (iteratorCounter != list.listCounter) {
			throw new ConcurrentModificationException("ERROR: Data Structre have been modified");
		}
		
		return(currentNode.getNextNode() != null );
	}
	
	@Override
	public T next() {
		
		if (iteratorCounter != list.listCounter) {
			throw new ConcurrentModificationException("ERROR: Data Structre have been modified");
		}
		
		if (list.isEmpty()) {
			throw new NullPointerException("list is empty");
		}
		
		T data = currentNode.getData();
		currentNode = currentNode.getNextNode();	
	
		return data;
	}
}

	@Override
	public Iterator<T> iterator() {
		return new ListIteratorImp<T>(this); 
	}

	public void pushFront(T data) {
		++listCounter;
		Node<T> newNode = new Node<T>(data, head);
		head = newNode;
	}

	public T popFront() throws GenericException {
	
	if (isEmpty()) {
		throw new GenericException("Can't pop from Empty List");
	}
	
	++listCounter;
	T data = head.getData();
	head = head.getNextNode();
	
	return data;
	}

	public int size() {
	int size = 0;
	for (@SuppressWarnings("unused") T item : this) {
		++size;
	}
		return size;
	}
	
	public Iterator<T> find(T data) {
		Iterator<T> iter = iterator();
		
		for(T e : this) {
			if (e.equals(data)) {
		        return iter;
			}
        	
			iter.next();
        }
		
		return null;
	}
	
	public boolean isEmpty() {
		return (head.getNextNode() == null);
	}
	
	public static <E> SinglyLinkedList<E> Merge(SinglyLinkedList<E> list1, SinglyLinkedList<E> list2) {
        SinglyLinkedList<E> newSinglyList = new SinglyLinkedList<>();
        
        for(E element: list1) {
        	newSinglyList.pushFront(element);
        }
        
        for(E element: list2) {
        	newSinglyList.pushFront(element);
        }
        return newSinglyList;
		
	}
	
	public static <E> SinglyLinkedList<E> newReverse(SinglyLinkedList<E> list) {
		SinglyLinkedList<E> reversList = new  SinglyLinkedList<>();
	
		for (E item : list) {
			reversList.pushFront(item);
		}
				
		return reversList;
	}
	
	public static <E> void Print(SinglyLinkedList<E> list) {

		for (E item : list) {
			System.out.println(item);
		}
		
	}
}
