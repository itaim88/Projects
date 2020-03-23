package il.co.ilrd.MultiThreadCountingSort;

import java.util.Arrays;
import java.util.PriorityQueue;

public class MergeSortedArr {
	
	public char[] mergeKSortedArray(char[][] arr) {
		
		PriorityQueue<ArrayContainer> queue = new PriorityQueue<ArrayContainer>();
		int total = 0;
 
		for (int i = 0; i < arr.length; ++i) {
			queue.add(new ArrayContainer(arr[i], 0));
			total = total + arr[i].length;
		}
 
		int index = 0;
		char result[] = new char[total];
 
		while(!queue.isEmpty()) {
			ArrayContainer ac = queue.poll();
			result[index++] = ac.arr[ac.index];
 
			if(ac.index < ac.arr.length-1){
				queue.add(new ArrayContainer(ac.arr, ac.index+1));
			}
		}
 
		return result;
	}
}

class ArrayContainer implements Comparable<ArrayContainer> {
	char[] arr;
	int index;
 
	public ArrayContainer(char[] arr, int index) {
		this.arr = arr;
		this.index = index;
	}
 
	@Override
	public int compareTo(ArrayContainer o) {
		return this.arr[this.index] - o.arr[o.index];
	}
}
