package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;
import il.co.ilrd.chat_server.Status;

public class ResponseCreateGroup extends Response {
	/**
	 * 
	 */
	private static final long serialVersionUID = -838016303129502199L;
	private int userId;
	private String groupName;
	private static final ChatOps opId = ChatOps.CREATE_GROUP;

	public ResponseCreateGroup(int requestMsgID, String groupName, Status status) {
		super(opId, requestMsgID, status);
		this.userId = userId;
		this.groupName = groupName;
	}

	public int getUserId() {
		return userId;
	}

	public String getGroupName() {
		return groupName;
	}
}