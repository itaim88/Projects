package il.co.ilrd.MultiThreadCountingSort;

public class CountingSort {

	void sort(char arr[], int startIndex, int endIndex) { 
		//int charNum = arr.length; 
		int charNum = (endIndex - startIndex) + 1; 
		char output[] = new char[charNum]; 
		int count[] = new int[256]; 
		
		for (int i = 0; i < 256; ++i) {
		    count[i] = 0;
		}
  
		for (int i = 0; i < charNum; ++i) { 
			++count[arr[i + startIndex]];
		}
  
		for (int i = 1; i <= 255; ++i) {
			count[i] += count[i - 1];
		}
	  
		for (int i = 0; i < charNum; ++i) { 
			output[count[arr[i +startIndex]] - 1] = arr[i + startIndex]; 
			--count[arr[i + startIndex]]; 
		} 
	 
		for (int i = 0; i < charNum; ++i) { 
	            arr[i+startIndex] = output[i]; 
		}
	}  
} 