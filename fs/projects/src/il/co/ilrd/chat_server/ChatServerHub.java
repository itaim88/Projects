package il.co.ilrd.chat_server;

import java.awt.Color;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

public class ChatServerHub implements ChatServer{
	private Map<Integer, User> users = new HashMap<>();
	private Map<String, Group> groups = new HashMap<>();

	@Override
	public void logIn(int msgId, String email, String name, Peer peer) {
		Collection<User> usersCollection = users.values();
		User user = null;
		Status status = Status.SUCCESS;
		if (email == null || name == null || peer == null) {
			peer.responseLogin(msgId, 0, null, Status.BAD_INPUT);
			return;
		}

		for (User u : usersCollection) {
			if (u.email.equals(email)) {
				user = u;
				user.peer = peer;
				status = Status.ALREADY_IN_GROUP;
			}
		}

		if (user == null) {
			user = new User(name, email, peer);
			users.put(user.id, user);
		}

		peer.responseLogin(msgId, user.id, user.groupNames, status);
	}

	@Override
	public void createNewGroup(int msgId, Integer userId, String groupName) {
		User user = users.get(userId);
		if (groups.containsKey(groupName)) {
			user.peer.responseCreateGroup(msgId, groupName, Status.GROUP_ALREADY_EXISTS);
			return;	
		}
		System.out.println("new group print " +  user);
		Group g = new Group(groupName,user);
		groups.put(groupName,g);
		user.groupNames.add(groupName);
		user.peer.responseCreateGroup(msgId, groupName, Status.SUCCESS); 	
	}
	
	@Override
	public void joinGroup(int msgId, Integer userId, String groupName) {
		User user = users.get(userId);
		if (!groups.containsKey(groupName)) {
			user.peer.responseCreateGroup(msgId, groupName, Status.GROUP_NOT_FOUND);
			return;	
		}

		Group group = groups.get(groupName);
		if (group.usersInGroup.containsKey(user.id)) {
			user.peer.responseJoinGroup(msgId, userId, user.userName, groupName, Status.ALREADY_IN_GROUP);
		}
		group.usersInGroup.put(userId, new ColorUsrProperties());
		for(Integer id : group.usersInGroup.keySet()) {
			users.get(id).peer.responseJoinGroup(msgId, userId, user.userName, groupName, Status.SUCCESS);
		}
	}

	@Override
	public void leaveGroup(int msgId, Integer userId, String groupName) {
		User user = users.get(userId);
		Group group = groups.get(groupName);

		if (null != group) {
			if (group.usersInGroup.containsKey(userId)) {
				group.usersInGroup.remove(userId);
				for(Integer id : group.usersInGroup.keySet()) {
					users.get(id).peer.responseLeaveGroup(msgId, userId, user.userName, groupName, Status.SUCCESS);
				}
			}

			user.peer.responseLeaveGroup(msgId, userId, user.userName, groupName, Status.NOT_IN_GROUP);				
		}
		user.peer.responseLeaveGroup(msgId, userId, user.userName, groupName, Status.GROUP_NOT_FOUND);		
	}

	@Override
	public void sendMsg(int msgId, Integer userId, String groupName, String msg) {
		/*User user = users.get(userId);
		Group group = groups.get(groupName);
		UsrProperties p;
		if (group != null) {
			p = group.usersInGroup.get(user.id);
			for (Integer id : group.usersInGroup.keySet()) {
				users.get(id).peer.responseMessage(msgId, userId, user.userName, groupName, p, msg, Status.SUCCESS);
			}
		}
		user.peer.responseMessage(msgId, userId, user.userName, groupName, new ColorUsrProperties(), msg, Status.GROUP_NOT_FOUND);*/
		Status status;
		User user = users.get(userId);
		Group group = groups.get(groupName);
		if(user == null) { status = Status.CLIENT_NOT_FOUND; }
		else if(group == null) { status = Status.GROUP_NOT_FOUND; }
		else if(!user.groupNames.contains(groupName)) { status = Status.NOT_IN_GROUP; }
		else{
			status = Status.SUCCESS;
			for(Entry<Integer, UsrProperties> member : group.usersInGroup.entrySet()) { 
				users.get(member.getKey()).peer.responseMessage(msgId, userId, user.userName, groupName, member.getValue() , msg, status);
			}
			return;
		}
		user.peer.responseMessage(msgId, userId, user.userName, groupName, null , msg, status);
	}
	
	
	private static class User {
		private String userName;
		private String email;
		private int id;
		private Peer peer;
		private static int counter;
		private Set<String> groupNames = new HashSet<>(); 

		public User(String name, String email, Peer peer) {
			this.userName = name;
			this.email = email;
			this.id = ++counter;
			this.peer = peer;

		}	
	}

	private static class Group {
		private Map<Integer, UsrProperties> usersInGroup = new HashMap<Integer, UsrProperties>();
		private String groupName;

		public Group(String name, User user) {
			this.groupName = name;
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

		@Override
		public Color getColor() {
			return color;
		}
	}
}