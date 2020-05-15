package il.co.ilrd.chat_server;

import java.awt.Color;
import java.util.Collection;
import java.util.Map;

public class ChatServerHub implements ChatServer{
	
	private Map<Integer, User> users;
	private Map<Integer, Group> groups;
	
	@Override
	public void logIn(String email, String name, Peer p) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void createNewGroup(String userId, String groupName) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void joinGroup(String userId, String groupId) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void leaveGroup(String userId, String groupId) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void sendMsg(String userId, String groupId, String msg) {
		// TODO Auto-generated method stub
		
	}
	
	private static class User {
		private String name;
		private String email;
		private int id;
		private Peer peer;
		private static int counter;
		
		public User(String name, String email, Peer peer) {
			this.name = name;
			this.email = email;
			this.id = 007; //generate..;
			this.peer = peer;
		}	
	}
	
	private static class Group {
		Map<Integer, UsrProperties> users;
	
	}
	
	private static class ColorUsrProperties implements UsrProperties{
		Color color;
	}
}
