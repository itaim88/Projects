package il.co.ilrd.factory;

import java.util.HashMap;
import java.util.Map;
import java.util.function.*;

public class Factory<K, T, D> {
	Map<K, Function<D, ? extends T>> map_types = new HashMap<K, Function<D, ? extends T>>();
	
	public void add(K key, Function<D, ? extends T> ctorFunc) {
		map_types.put(key, ctorFunc);
	}
	
	public T create(K key, D data) {
		return map_types.get(key).apply(data);
	}
}
