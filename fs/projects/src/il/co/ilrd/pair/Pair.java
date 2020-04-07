package il.co.ilrd.pair;

import java.util.Comparator;
import java.util.Map;

public class Pair<K,V> implements Map.Entry<K,V> {

	private K key;
	private V value;
	
	private Pair(K key, V value) {
		
		this.key = key;
		this.value = value;
	}
	
	public static<K,V> Pair<K,V> of(K key, V value) {
		
		return new Pair<K,V>(key,value);
	}

	public static<K, V> Pair<V,K> swap(Pair<K,V> pair) {
		
		return of(pair.getValue(),pair.getKey());
	}

	public K setKey(K key) {
		
		K oldKey = getKey();
		setKey(key);
		
		return oldKey;	
	}

	@Override
	public K getKey() {
		return this.key;
	}
	
	@Override
	public V getValue() {
		return this.value;
	}
	
	@Override
	public V setValue(V arg0) {
		
		V oldValue = getValue();
		setValue(arg0);
		
		return oldValue;
	}

	@Override
	public String toString() {
		return "Pair [key=" + key + ", hashCode()=" + hashCode() + "]";
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		
		if (obj == null)
			return false;
		
		if (getClass() != obj.getClass())
			return false;
		
		Pair<K,V> other = (Pair<K,V>) obj;
		if (key == null) {
			if (other.key != null)
				return false;
			
		} else if (!key.equals(other.key))
			return false;
		
		return true;
	}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((key == null) ? 0 : key.hashCode());

		return result;
	}
	
	public static<T extends Comparable<T>> Pair<T, T> minMax(T[] array) {
		T max = null;
		T min = null;
		
		if (array.length == 0) {
			//exception??
			
			return new Pair<T,T>(min, max);
		}
		if (array.length == 1) {
			
			return new Pair<T,T>(array[0],array[0]);
		}
	 
		if (0 < array[0].compareTo(array[1])) {
			max = array[0];
			min = array[1];
		}
		
		else {
			max = array[1];
			min = array[0];
		}
		
		for (int i = 2; i < array.length - 1; i +=2) {
			
			if (0 < array[i].compareTo(array[i + 1])) {
				
				if(max.compareTo(array[i]) < 0) {
					max = array[i];
				}
				
				if(min.compareTo(array[i + 1]) > 0) {
					min = array[i + 1];
				}
			} 
			
			else {
				
				if(max.compareTo(array[i + 1]) < 0) {
					max = array[i + 1];
				}
				
				if(min.compareTo(array[i]) > 0) {
					min = array[i];
				}
			}
		}
		
		if (array.length % 2 == 1) {
			
			int index = array.length - 1;
			if(max.compareTo(array[index]) < 0) {
				max = array[index];
			}
			
			if(min.compareTo(array[index]) > 0) {
				min = array[index];
			}
		}
		
		return new Pair<T,T>(min,max);
	}
	
	public static <T> Pair<T, T> minMax(T[] array, Comparator<T> cmp){
		T max = null;
		T min = null;
		
		if (array.length == 0) {
			//exception??
			
			return new Pair<T,T>(min, max);
		}
		if (array.length == 1) {
			
			return new Pair<T,T>(array[0],array[0]);
		}
		
		
		if (0 < cmp.compare(array[0],array[1])) {
			max = array[0];
			min = array[1];
		}
		
		else {
			max = array[1];
			min = array[0];
		}
		
		for (int i = 2; i < array.length - 1; i +=2) {
			
			if (0 < cmp.compare(array[i], array[i + 1])) {
				
				if(cmp.compare(max, array[i]) < 0) {
				max = array[i];
				}
				
				if(cmp.compare(min,array[i + 1]) > 0) {
					min = array[i + 1];
				}
			} 
			
			else {
				
				if(cmp.compare(max, array[i + 1]) < 0) {
					max = array[i + 1];
				}
				if(cmp.compare(min, array[i]) > 0) {
					min = array[i];
				}
			}
		}
		
		if (array.length % 2 == 1) {
			
			int index = array.length - 1;
			
			if(cmp.compare(max, array[index]) < 0) {
				max = array[index];
			}
			
			if(cmp.compare(min, array[index]) > 0) {
				min = array[index];
			}
		}
		
		return new Pair<T,T>(min,max);
	}
	
}