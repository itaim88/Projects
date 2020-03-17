package il.co.ilrd.linked_list;

public class Main {

	public static void main(String[] args) {
		
		singlyLinkedList sll1 = new singlyLinkedList();
		Integer data1 = 10;
		Integer data2 = 5;
		Integer data3 = 12;
		Integer data4 = 20;
		
		System.out.println(sll1.isEmpty() + " - empty list test");
		System.out.println(sll1.size() + " - size = 0");
		
		sll1.pushFront(data1);
		System.out.println(sll1.isEmpty() +" - one node in test");
		System.out.println(sll1.size() + " - size = 1");
		
		sll1.pushFront(data2);
		System.out.println(sll1.size() + " - size = 2");
		
		sll1.pushFront(data4);
		
		System.out.println(data2.equals(sll1.find(data2).next()) + " find test"); 
		System.out.println(data1.equals(sll1.find(data1).next()) + " find test"); 
		System.out.println((sll1.find(data3) + " no find test"));
		System.out.println(data4.equals(sll1.find(data4).next()) + " find test"); 
		
		listIterator iter = sll1.begin();
		System.out.println(iter.hasNext() == true);
		System.out.println(iter.next());
		System.out.println(iter.hasNext() == true);
		System.out.println(iter.next());
		System.out.println(iter.hasNext() == false);
		System.out.println(iter.next());
		
		Object obj = sll1.popFront();
		System.out.println(sll1.size() + " - size = 1 after pop");
		System.out.println(obj + " - 10 is pop");
		obj = sll1.popFront();
		System.out.println(sll1.size() + " - size = 0 after two pop");
		System.out.println(obj + " - 5 is pop");
		
	}

}
