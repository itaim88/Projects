package il.co.ilrd.chat_server;

import java.awt.Color;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Map;
import java.util.Map.Entry;

import il.co.ilrd.hashmap.HashMap;

public class ChatServerHub implements ChatServer{
	
	private Map<Integer, User> users = new HashMap<>();
	private Map<Integer, Group> groups = new HashMap<>();
	
	@Override
	public void logIn(String email, String name, Peer peer) {
		Collection<User> u = users.values();
		User user = null;
		for (User i : u) {
			if(i.email.equalsIgnoreCase(email)) {
				i.peer = peer;
				peer.sendLogin(i.id, i.groupID);
				return;
			}
		}
		user = new User(name, email, peer);
		peer.sendLogin(user.id, user.groupID);
	} 

	@Override
	public void createNewGroup(Integer userId, String groupName) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void joinGroup(Integer userId, Integer groupId) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void leaveGroup(Integer userId, Integer groupId) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void sendMsg(Integer userId, Integer groupId, String msg) {
		// TODO Auto-generated method stub
		
	}
	
	private static class User {
		private String name;
		private String email;
		private int id;
		private Peer peer;
		private static int counter;
		private ArrayList<Integer> groupID = new ArrayList<Integer>(); 
		
		public User(String name, String email, Peer peer) {
			this.name = name;
			this.email = email;
			this.id = ++counter;
			this.peer = peer;
			
		}	
	}
	
	private static class Group {
		Map<Integer, UsrProperties> users;
		private String name;
		private int id;
		private static int counterGroup = 1000;
		
	}
	
	private static class ColorUsrProperties implements UsrProperties{
		Color color;
	}
}
