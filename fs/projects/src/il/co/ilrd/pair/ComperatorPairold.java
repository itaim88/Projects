package il.co.ilrd.pair;

import java.util.Comparator;

public class ComperatorPair<T extends Comparable<T>> implements Comparator<T> {

	@Override
	public int compare(T arg0, T arg1) {
			return (arg0.compareTo(arg1));	

	}
}


