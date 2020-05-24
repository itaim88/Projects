package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;
import il.co.ilrd.chat_server.Status;

public class ResponseLeaveGroup extends Response {
	/**
	 * 
	 */
	private static final long serialVersionUID = -246542286706772128L;
	private int userId;
	private String groupName;
	private String senderName;
	private static final ChatOps opId = ChatOps.LEAVE_GROUP;

	public ResponseLeaveGroup(int requestMsgID, int userId, String groupName, String senderName, Status status) {
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
