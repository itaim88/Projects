package il.co.ilrd.chat_server;

import java.util.Set;

public interface Peer {
	public void responseMessage(int msgID, int userID, String userName, String groupName, UsrProperties prop, String message, Status status);
	public void responseJoinGroup(int msgID, int userID, String userName, String groupName, Status status);
	public void responseLogin(int msgID, int userID, Set<String> groupNames,  Status status);
	public void responseCreateGroup(int msgID, String groupName,  Status status);
	public void responseLeaveGroup(int msgID, int userID, String userName, String groupName, Status status);
}
