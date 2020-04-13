package il.co.ilrd.pair;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.Comparator;

import org.junit.jupiter.api.Test;


class Player implements Comparable<Player> {
		
		String name;
		int points;
		
		public Player(String name, int points) {
			this.name = name;
			this.points = points;
		}

		@Override
		public String toString() {
			return "Name: " + name + " points: "+ points;
		}

		@Override
		public int compareTo(Player o) {
			return this.points - o.points;
		}

	}

class test {

	@Test
	void test() {
		Integer key1 = 1;
		Integer value1 = 7;
		
		Pair<Integer,Integer> pair1 = Pair.of(key1, value1);
		Pair<Integer,Integer> pair2 = Pair.of(10, 99);
		
		Pair<String,String> pair3 = Pair.of("hello", "99");
		Pair<String,String> pair4 = Pair.of("o", "9");
		
		assertEquals(key1, pair1.getKey());
		assertEquals(value1, pair1.getValue());
		
		pair2 = Pair.swap(pair1);
		assertEquals(key1, pair1.getKey());
		assertEquals(value1, pair1.getValue());
		assertEquals(value1, pair2.getKey());
		assertEquals(key1, pair2.getValue());
		
		pair3 = Pair.swap(pair4);
		assertEquals("9", pair3.getKey());
		assertEquals("o", pair3.getValue());
		
		Integer[] arr = {1,2,99,100,-100,9,4,2,88,3};
		Integer[] arr1 = {1,2,99,50,-100};
		Pair<Integer,Integer> pair5 = Pair.minMax(arr);
		
		assertEquals((Integer)(-100), pair5.getKey());
		assertEquals((Integer)100, pair5.getValue());
		
		Pair<Integer,Integer> pair6 = Pair.minMax(arr1);
		assertEquals((Integer)(-100), pair6.getKey());
		assertEquals((Integer)99, pair6.getValue());
		
		assertTrue(pair5.equals(pair6)); 
		assertFalse(pair3.equals(pair4)); 
	}

		class PlayerComperator implements Comparator<Player>{

			@Override
			public int compare(Player o1, Player o2) {
				return o1.points - o2.points;
			}
		}
		
		@Test
		void testMinMaxCmp() {
			Player[] p1 = new Player[5];
			
			p1[0] = new Player("A", 5);
			p1[1] = new Player("B", 99);
			p1[2] = new Player("C", 3);
			p1[3] = new Player("D", 111);
			p1[4] = new Player("E", -77);
			
			Pair<Player,Player> pair7 = Pair.minMax(p1, new PlayerComperator());
			
			System.out.println(pair7.getKey());
			System.out.println(pair7.getValue());
		}
	}

		
		
	

	



