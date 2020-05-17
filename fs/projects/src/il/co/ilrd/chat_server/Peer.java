package il.co.ilrd.chat_server;

import java.util.List;

public interface Peer {
	public void sendMessage(String senderName, int groupID, UsrProperties prop, String message);
	public void sendAddToGRoup(int status);
	public void sendNewGroupMember(int newUsrID);
	public void sendLogin(int userID, List<Integer> groupID);
	public void sendCreateGroup(int groupID, int groupName);
	public void sendLeaveGroup(int status);

}
