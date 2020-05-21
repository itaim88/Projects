package il.co.ilrd.chat_server;

public interface ChatServer {
	/**
	 * @param email the user's email
	 * @param name the user's name
	 * @param peer represents the communicating peer
	 */
	public void logIn(int msgId, String email, String name, Peer peer);
	
	/**
	 * @param userId 
	 * @param groupName name of the group to be created.
	 */
	void createNewGroup(int msgId, Integer userId, String groupName);
	
	/**
	 * @param userId
	 * @param groupId a unique id that each group has, given at creation.
	 */
	public void joinGroup(int msgId, Integer userId, String groupName);
	
	/**
	 * @param userId
	 * @param groupId a unique id that each group has, given at creation.
	 */
	public void leaveGroup(int msgId, Integer userId, String groupName);

	/**
	 * @param userId
	 * @param groupId a unique id that each group has, given at creation.
	 * @param msg the message sent by the user
	 */
	public void sendMsg(int msgId, Integer userId, String groupName, String msg);

	
}
