package il.co.ilrd.chat_client;

import java.util.Collection;

public class ChatClient implements Client {

	private int userId;
	private Collection<String> groups;
	
	@Override
	public void logIn(int msgId, String email, String name, Peer peer) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void createNewGroup(int msgId, Integer userId, String groupName) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void joinGroup(int msgId, Integer userId, String groupName) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void leaveGroup(int msgId, Integer userId, String groupName) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void sendMsg(int msgId, Integer userId, String groupName, String msg) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void display() {
		// TODO Auto-generated method stub
		
	}

}
