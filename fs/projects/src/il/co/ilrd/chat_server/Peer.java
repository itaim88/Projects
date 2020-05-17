package il.co.ilrd.chat_server;

import java.util.List;

public interface Peer {
	public void sendMessage(String senderName, int groupID, UsrProperties prop, String message);
	public void sendAddToGRoup(boolean status);
	public void sendNewGroupMember(Integer groupId,int newUsrID);
	public void sendLogin(int userID, List<Integer> groupID);
	public void sendCreateGroup(int groupID, String groupName);
	public void sendLeaveGroup(boolean status);

}
