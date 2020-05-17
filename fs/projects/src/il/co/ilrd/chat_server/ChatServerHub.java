package il.co.ilrd.chat_server;

import java.awt.Color;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Random;

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
		//is user exist??
		User u = users.get(userId);
		Group newGroup = new Group(u.name, u);
		groups.put(newGroup.id, newGroup);
		
		u.peer.sendCreateGroup(newGroup.id, newGroup.name);
	}

	@Override
	public void joinGroup(Integer userId, Integer groupId) {
		User u = users.get(userId);
		Group g = groups.get(groupId);
		if (u == null || g == null ) {
			u.peer.sendAddToGRoup(false);	
		}
		for(Integer i : g.usersInGroup.keySet()) {
			users.get(i).peer.sendNewGroupMember(groupId, userId);
	
		}
		g.usersInGroup.put(u.id, new ColorUsrProperties());
		u.peer.sendAddToGRoup(true);	
		
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
		private Map<Integer, UsrProperties> usersInGroup = new HashMap<Integer, UsrProperties>();
		private String name;
		private int id;
		private static int counterGroup = 1000;
		
		public Group(String name, User user) {
			this.name = name;
			this.id = ++counterGroup;
			usersInGroup.put(user.id, new ColorUsrProperties());
			
		}	
	}
	private static class ColorUsrProperties implements UsrProperties{
		private Color color;
		private Random rand;
		
		public ColorUsrProperties() {
			rand = new Random();
			float r = rand.nextFloat();
			float g = rand.nextFloat();
			float b = rand.nextFloat();
			this.color = new Color(r, g, b);
		}
	}
}
