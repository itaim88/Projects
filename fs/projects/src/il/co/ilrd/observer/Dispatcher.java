package il.co.ilrd.observer;

import java.util.LinkedList;
import java.util.List;
import java.util.function.Consumer;

public class Dispatcher<T> {
	private List<Callback<T>> callbackList = new LinkedList<>();
	
	public void register(Callback<T> callback) {
		callback.dispatcher = this;
		callbackList.add(callback);
	}
	
	public void stopAll() {
		for(Callback<T> call: callbackList) {
			call.notifyDeath();
		}
		
		callbackList.clear();
	}
	
	public void updateAll(T msg) {
		for(Callback<T> call : callbackList) {
			call.update(msg);
		}
	}
	
//	public void unregister(Callback cb) {}
	
	public static class Callback <T>{
		private Consumer<T> consumer;
		private Runnable runnable;
		private Dispatcher<T> dispatcher;
		
		public Callback(Consumer<T> consumer, Runnable runnable) {
			this.consumer = consumer;
			this.runnable = runnable;
		}
		
		private void update(T msg) { 
			consumer.accept(msg);
		}	
		
		private void notifyDeath() {  
			runnable.run();
			dispatcher = null;
		}
		
		public void stopService() {
			try {
				dispatcher.callbackList.remove(this);	
			} catch (NullPointerException e) {
				System.out.println("You're not signed to the serice");
			}
			
			dispatcher = null;
		}
	}
}
