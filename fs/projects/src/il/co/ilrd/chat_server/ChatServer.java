package il.co.ilrd.chat_server;

public interface ChatServer {
	/**
	 * @param email the user's email
	 * @param name the user's name
	 * @param peer represents the communicating peer
	 */
	public void logIn(String email, String name, Peer peer);
	
	/**
	 * @param userId 
	 * @param groupName name of the group to be created.
	 */
	void createNewGroup(String userId, String groupName);
	
	/**
	 * @param userId
	 * @param groupId a unique id that each group has, given at creation.
	 */
	public void joinGroup(String userId, String groupId);
	
	/**
	 * @param userId
	 * @param groupId a unique id that each group has, given at creation.
	 */
	public void leaveGroup(String userId, String groupId);

	/**
	 * @param userId
	 * @param groupId a unique id that each group has, given at creation.
	 * @param msg the message sent by the user
	 */
	public void sendMsg(String userId, String groupId, String msg);

	
}
