package il.co.ilrd.MultiThreadCountingSort;

import java.util.Arrays;
import java.util.List;

public class ThreadCountingSort {
	public void ThreadCountSort(String str, int numberOfThreads) {
		char arr[] = str.toCharArray();
		int length = arr.length;
		CountingSort obj = new CountingSort(); 
		
		if (0 == numberOfThreads) {
			obj.sort(arr, 0, length - 1);
			System.out.println(Arrays.toString(arr));
		}
		
		else {
			int startIndex = 0;
			int endIndex = length - 1;
			int jump = length / numberOfThreads;
			int factor = 0;
			
			for (int i = 0; i < numberOfThreads - 1; ++i) {
				obj.sort(arr,startIndex + factor, jump - 1 + factor);
				factor += jump;
			}
			
			obj.sort(arr, factor, endIndex);
			char splitArr[][] = splitArray(arr, length/numberOfThreads);
			/*for (int i = 0; i < splitArr.length; i++) {
				System.out.println(Arrays.toString(splitArr[i]));
		    }*/
			
			MergeSortedArr ms = new MergeSortedArr();
			char[] res = ms.mergeKSortedArray(splitArr);
			System.out.println(Arrays.toString(res));
		}
	}

			
	public static char[][] splitArray(char[] arrayToSplit, int chunkSize){	   
		int rest = arrayToSplit.length % chunkSize;  
		int chunks = arrayToSplit.length / chunkSize + (rest > 0 ? 1 : 0); 
		char[][] arrays = new char[chunks][];
		
		for(int i = 0; i < (rest > 0 ? chunks - 1 : chunks); ++i){
		    arrays[i] = Arrays.copyOfRange(arrayToSplit, i * chunkSize, i * chunkSize + chunkSize);
		}
		
		if(rest > 0) { 
		    arrays[chunks - 1] = Arrays.copyOfRange(arrayToSplit, (chunks - 1) * chunkSize, (chunks - 1) * chunkSize + rest);
		}
		
		return arrays; 
	}
	
}
	
