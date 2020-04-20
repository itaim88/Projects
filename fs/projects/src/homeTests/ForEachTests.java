package homeTests;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;

public class ForEachTests {
	
	enum Suit { CLUB, DIAMOND, HEART, SPADE }
	enum Rank { ACE, DEUCE, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
	NINE, TEN, JACK, QUEEN, KING }
	
	static Collection<Suit> suits = Arrays.asList(Suit.values());
	static Collection<Rank> ranks = Arrays.asList(Rank.values());
	

	public ForEachTests(Suit suit, Rank rank) {
		
	}


	public static void main(String[] args) {
	
		List<ForEachTests> deck = new ArrayList<>();
		
		for (Suit suit : suits)
			for (Rank rank : ranks)
			deck.add(new ForEachTests(suit, rank));
			System.out.println(suits);
			System.out.println(ranks);
	}
}
	



