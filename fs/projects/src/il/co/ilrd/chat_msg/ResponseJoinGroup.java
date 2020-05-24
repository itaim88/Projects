package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;
import il.co.ilrd.chat_server.Status;

public class ResponseJoinGroup extends Response {
	/**
	 * 
	 */
	private static final long serialVersionUID = 740161959953103624L;
	private int userId;
	private String groupName;
	private String senderName;
	private static final ChatOps opId = ChatOps.JOIN_GROUP;

	public ResponseJoinGroup(int requestMsgID, int userId, String groupName, String senderName, Status status) {
		super(opId, requestMsgID, status);
		this.userId = userId;
		this.groupName = groupName;
		this.senderName = senderName;
	}

	public int getUserId() {
		return userId;
	}

	public String getGroupName() {
		return groupName;
	}
	public String getSenderName() {
		return senderName;
	}
}
