package il.co.ilrd.chat_client;

public interface Client {
	public void logIn(int msgId, String email, String name, Peer peer);
	public void createNewGroup(int msgId, Integer userId, String groupName);
	public void joinGroup(int msgId, Integer userId, String groupName);
	public void leaveGroup(int msgId, Integer userId, String groupName);
	public void sendMsg(int msgId, Integer userId, String groupName, String msg);
	public void display();
}
