package com.andrew.singly.linked.list;

public class singlyLinkedList {
	private node head = new node(null, null);
	
	
	public Boolean isEmpty(){};
	public listIterator find(Object data) {};
	public int size() {};
	public Object popFront(){};
	public void pushFront() {};
	public listIterator begin() {};

private class node {
	private Object data;
	private node nextNode;
		
	public node(Object data, node nextNode) {}
		
	public Object getData() {};
	public node getNextNode() {};
	}
}





