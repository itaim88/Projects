package com.singly.linked.list;

public class singlyLinkedList {
	
	private node head = new node(null, null);
	
	public Boolean isEmpty(){
		
		return (null == head.getNextNode());	
	}
	
	public listIterator find(Object data) {
		
		listIterator iterNext = begin();
		listIterator iterPrev = begin();
		
		while (iterPrev.hasNext())
		{
			if (data.equals(iterNext.next()))
			{
				return iterPrev;
			}
			
			iterPrev.next();
		}
		
		if (data.equals(iterNext.next()))
		{
			return iterPrev;
		}
		
		return null;
	}
	
	public long size() {
		
		long size = 0L;
		
		listIterator iter = begin();
	
		while (iter.hasNext())
		{
			++size;
			iter.next();
		}
		
		return size;
	}
	
	public Object popFront(){
		
		Object data =  head.getNextNode().getData();
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
			currentNode = head;
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
