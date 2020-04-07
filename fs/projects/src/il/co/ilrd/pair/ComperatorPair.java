package il.co.ilrd.pair;

import java.util.Comparator;

public class ComperatorPair<T extends Comparable<T>> implements Comparator<T> {

	@Override
	public int compare(T arg0, T arg1) {
		if(arg0.compareTo(arg1) > 0){
			return 1;	
		} 
		
		return -1;
	}
}


