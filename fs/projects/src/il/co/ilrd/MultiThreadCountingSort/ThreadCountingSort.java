package il.co.ilrd.MultiThreadCountingSort;

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

public class ThreadCountingSort extends Thread  {
	static Object lock = new Object();
	static AtomicInteger threadCount = new AtomicInteger();
	//static String str ="shhljovaiswwmylpvnbcdrjtqqjmnleopigqughiopfwedrrxabcriampojncgemnhkicdeal";
	static String path = "d:/words.txt";
	static String str =  TextToString.readLineByLineJava8(path);
	static char arr[] = str.toCharArray();
	static int length = arr.length;
	CountingSort obj = new CountingSort(); 
	static int startIndex = 0;
	static int endIndex = length - 1;
	static int numThreads = 7;
	static int jump = length / numThreads;
	static int factor = 0;

	@Override
	public void run() {
		ThreadCountingSort t = new ThreadCountingSort();
		t.ThreadCountSort(numThreads);	
		
	}
	
	public void ThreadCountSort(int numberOfThreads) {
		synchronized (lock) {
			threadCount.incrementAndGet();
			if(threadCount.get() < numberOfThreads) {
				obj.sort(arr, factor, jump - 1 + factor);	 
				factor += jump;
			}
		
			else  {
				obj.sort(arr, factor, endIndex);
				char splitArr[][] = splitArray(arr, length/numberOfThreads);
				MergeSortedArr ms = new MergeSortedArr();
				char[] res = ms.mergeKSortedArray(splitArr);
				System.out.println(Arrays.toString(res));
				return;
			}
		}
	}

	public static char[][] splitArray(char[] arrayToSplit, int chunkSize) {	   
		int rest = arrayToSplit.length % chunkSize;  
		int chunks = arrayToSplit.length / chunkSize + (rest > 0 ? 1 : 0); 
		char[][] arrays = new char[chunks][];
		
		for (int i = 0; i < (rest > 0 ? chunks - 1 : chunks); ++i) {
		    arrays[i] = Arrays.copyOfRange(arrayToSplit, i * chunkSize, i * chunkSize + chunkSize);
		}
		
		if (rest > 0) { 
		    arrays[chunks - 1] = Arrays.copyOfRange(arrayToSplit, (chunks - 1) * chunkSize, (chunks - 1) * chunkSize + rest);
		}
		
		return arrays; 
	}

}
	
