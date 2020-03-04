package com.singly.linked.list;

public class singlyLinkedList {
	
	private node head = new node(null, null);
	
	public Boolean isEmpty(){
		
		
		return (null == head.getNextNode());
		
	}
	
	public listIterator find(Object data) {
		
		Object 
		
		while (iter.ha)
		
		return null;
	}
	
	public int size() {
		
		long size = 1L;
		
		listIterator iter = begin();
		if (null == iter)
		{
			return 0;
		}
		
		while (iter.hasNext())
		{
			++size;
			iter.next();
		}
		
		return size;
	}
	
	public Object popFront(){
		
		Object data =  head.getNextNode().getNextNode();
		head.nextNode = head.getNextNode().getNextNode();
		
		return data;		
	}
	
	public void pushFront(Object data) {
	
		node newNode = new node(data, head.getNextNode()); 
		head.nextNode = newNode;
	}
	
	public listIterator begin() {	
		listIterator itr = new listIteratorImp();
	
		return itr;	
	}
	
	private class node {
		
		private Object data;
		private node nextNode;
			
		public node(Object data, node nextNode) {
			this.data = data;
			this.nextNode = nextNode;
		}
			
		public Object getData() {	
			return data;
		}
		
		public node getNextNode() {
			return nextNode;
		}
	}
	
	 class listIteratorImp implements listIterator {
	
		node currentNode;
		
		listIteratorImp() {
			currentNode = head.getNextNode();
		}
		
		@Override
		public Object next() {
			Object currentData = currentNode.getData();
			currentNode = currentNode.getNextNode();
			return currentData;
		}
	
		@Override
		public Boolean hasNext() {
			return (null != currentNode.getNextNode());
		}
	}
}
