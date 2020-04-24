package il.co.ilrd.observer;

import java.util.function.Consumer;

class Test {

	@org.junit.jupiter.api.Test
	void test() {
		
		Consumer<String> update = msg -> System.out.println("first sprinkler: "+msg);
		Runnable notifyDeath = ()-> System.out.println("first sprinkler: stoping all");
		
		Consumer<String> update2 = msg -> System.out.println("sec sprinkler: "+msg );
		Runnable notifyDeath2 = ()-> System.out.println("sec sprinkler: stoping all" );
		
		Dispatcher<String> fireCheck = new Dispatcher<>();
		Dispatcher<String> fireCheck2 = new Dispatcher<>();

		Dispatcher.Callback<String> sprinkler =  new Dispatcher.Callback<>(update, notifyDeath);
		Dispatcher.Callback<String> sprinkler2 =  new Dispatcher.Callback<>(update2, notifyDeath2);
		Dispatcher.Callback<String> sprinkler3 =  new Dispatcher.Callback<>(update, notifyDeath);
		Dispatcher.Callback<String> sprinkler4 =  new Dispatcher.Callback<>(update2, notifyDeath2);
		fireCheck.register(sprinkler);
		fireCheck.register(sprinkler2);
		fireCheck.updateAll("fire started");
		System.out.println();
		
		sprinkler2.stopService();
		System.out.println("sprinkler2 is out of service");
		
		fireCheck.updateAll("fire stoped");
		System.out.println();
		
		fireCheck.register(sprinkler2);
		System.out.println("sprinkler2 is back!");
		fireCheck.updateAll("no fire for now");
		System.out.println();
		
		fireCheck.stopAll();
		System.out.println();
		
		fireCheck2.register(sprinkler3);
		fireCheck2.register(sprinkler4);
		fireCheck2.updateAll("fireCheck2 have 2 sprinklers");
		System.out.println();
		sprinkler3.stopService();
		fireCheck2.updateAll("fireCheck2 have 1 sprinklers");
		fireCheck2.register(sprinkler3);
		System.out.println();
		fireCheck2.updateAll("fireCheck2 have 2 sprinklers again!");
		System.out.println();
		fireCheck.stopAll();
	}
}
