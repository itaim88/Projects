package il.co.ilrd.chat_server;

public interface Peer {
	public void sendMessage(String senderName, int groupID, UsrProperties prop, String message);
	public void sendAddToGRoup(int status);
	public void sendNewGroupMember(int newUsrID);
	public void sendLogin(int userID, int... groupID);
	public void sendCreateGroup(int groupID, int groupName);
	public void sendLeaveGroup(int status);

}
