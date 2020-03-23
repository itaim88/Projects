package il.co.ilrd.MultiThreadCountingSort;

import java.util.Arrays;

public class Main {
	
	public static void main(String[] args) { 
		String str = "aaaa bbb ccc abcdef g";
		String str1 = "fdsfdsfafaaabbkpazxxxtaabbbdfhfgkasdfvadsva";
		String path = "d:/words.txt";
		String str2 =  TextToString.readLineByLineJava8(path);
		
		ThreadCountingSort tc = new ThreadCountingSort();
		ThreadCountingSort tc1 = new ThreadCountingSort();
		//ThreadCountingSort tc2 = new ThreadCountingSort();
		
		tc.ThreadCountSort(str, 2);
		tc1.ThreadCountSort(str1, 13);
		//tc2.ThreadCountSort(str2, 3);
		

		}
}
