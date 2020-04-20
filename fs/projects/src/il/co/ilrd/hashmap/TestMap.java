package il.co.ilrd.hashmap;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Collection;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import org.junit.jupiter.api.Test;
import il.co.ilrd.pair.*;

class TestMap {

	@Test
	void testContainsKey() {
		HashMap<Integer, Integer> hash_Map1 = new HashMap<Integer, Integer>();
		hash_Map1.put(1, 10);
		hash_Map1.put(2, 20);
		hash_Map1.put(3, 30);
		assertTrue(hash_Map1.containsKey(1));
		assertFalse(hash_Map1.containsKey(10));
		Set<Map.Entry<Integer,Integer>> s = hash_Map1.entrySet();
		Iterator itera = s.iterator();
		
		System.out.println("next " + itera.next());
		System.out.println("next " + itera.next());
		System.out.println("next " + itera.next());
		System.out.println("hasNext " + itera.hasNext());
		
		Iterator itr = hash_Map1.entrySet().iterator();
		System.out.println(" next " + itr.next());
		System.out.println(" next " + itr.next());
		System.out.println(" next " + itr.next());
		System.out.println(" hasNext " + itr.hasNext());
	}

	@Test
	void testIsEmpty() {
		HashMap<Integer, Integer> hash_Map2 = new HashMap<Integer, Integer>();
		assertTrue(hash_Map2.isEmpty());		
		hash_Map2.put(1, 10);
		hash_Map2.put(2, 20);
		hash_Map2.put(3, 30);
		assertFalse(hash_Map2.isEmpty());
		assertEquals(3,hash_Map2.size());
	}	
	
	@Test
	void testPut() {
		HashMap<Integer, Integer> hash_Map3 = new HashMap<Integer, Integer>();
		hash_Map3.put(1, 10);
		hash_Map3.put(2, 20);
		hash_Map3.put(3, 30);
		hash_Map3.put(4, 40);
		System.out.println(hash_Map3.keySet());
		Set<Integer> s = hash_Map3.keySet();
		assertEquals(4,s.size());
		assertTrue(s.iterator().hasNext());
		
		System.out.println(hash_Map3.values());
		Collection<Integer> c = hash_Map3.values();
		System.out.println(c.iterator().getClass()); //interesting//
		
		System.out.println(hash_Map3.entrySet());
		Set<Integer> s2 = hash_Map3.keySet();
		assertEquals(4,s2.size());
		
		
		hash_Map3.put(4, 400);
		assertEquals(4,hash_Map3.size());
		System.out.println(hash_Map3.values());
		hash_Map3.remove(4);
		System.out.println(hash_Map3.values());
		
		assertNull(hash_Map3.put(null, 99));
		System.out.println(hash_Map3.values());
		
		assertNull(hash_Map3.put(4, 15));
		System.out.println(hash_Map3.values());
		
		System.out.println(hash_Map3.values());
		assertEquals((Integer)10, hash_Map3.put(1, 8));
	}
	
	@Test
	void testSize() {
		HashMap<Integer, Integer> hash_Map4 = new HashMap<Integer, Integer>();
		assertEquals(0, hash_Map4.size());
		hash_Map4.put(1, 10);
		hash_Map4.put(2, 20);
		hash_Map4.put(3, 30);
		hash_Map4.put(4, 40);
		assertEquals(4, hash_Map4.size());
		System.out.println(hash_Map4.keySet());
		System.out.println(hash_Map4.values());
		System.out.println(hash_Map4.entrySet());
	}	

	@Test
	void testClear() {
		HashMap<Integer, Integer> hash_Map5 = new HashMap<Integer, Integer>();
		hash_Map5.put(1, 10);
		hash_Map5.put(2, 20);
		hash_Map5.put(3, 30);
		hash_Map5.put(4, 40);
		hash_Map5.clear();
		assertEquals(0, hash_Map5.size());
	}
	
	@Test
	void testContainsValue() {
		HashMap<Integer, Integer> hash_Map6 = new HashMap<Integer, Integer>();
		hash_Map6.put(1, 10);
		hash_Map6.put(2, 20);
		System.out.println(hash_Map6.values());
		
		assertTrue(hash_Map6.containsValue(10));
		assertFalse(hash_Map6.containsValue(100));
		assertFalse(hash_Map6.containsValue(null));
	}

	@Test
	void testGet() {
		HashMap<Integer, Integer> hash_Map7 = new HashMap<Integer, Integer>();
		hash_Map7.put(1, 10);
		hash_Map7.put(2, 20);
		assertEquals((Integer)10, hash_Map7.get(1));
		assertEquals(null, hash_Map7.get(10));
	
		assertEquals(null, hash_Map7.get(null));
		assertEquals(null, hash_Map7.get("g"));
	}

	@Test
	void testPutAll() {
		HashMap<Integer, Integer> hash_Map8 = new HashMap<Integer, Integer>();
		hash_Map8.put(10, 100);
		
		HashMap<Integer, Integer> hash_Map9 = new HashMap<Integer, Integer>();
		hash_Map9.put(1, 10);
		hash_Map9.put(2, 20);
		hash_Map9.put(3, 30);
		hash_Map9.put(4, 40);
		
		assertEquals(1, hash_Map8.size());
		hash_Map8.putAll(hash_Map9);
		assertEquals(5, hash_Map8.size());
	}

	@Test
	void testRemove() {
		HashMap<Integer, Integer> hash_Map10 = new HashMap<Integer, Integer>();
		hash_Map10.put(1, 10);
		hash_Map10.put(2, 20);
		hash_Map10.put(3, 30);
		hash_Map10.put(null, 999);
		System.out.println(hash_Map10.keySet());
		System.out.println(hash_Map10.values());
		System.out.println(hash_Map10.entrySet());

	
		assertEquals((Integer)999, hash_Map10.remove(null));
		assertEquals(null, hash_Map10.remove(0));
		assertEquals(null, hash_Map10.remove(null));
		assertEquals((Integer)10, hash_Map10.remove(1));
		assertEquals((Integer)20, hash_Map10.remove(2));
	}
	
}
