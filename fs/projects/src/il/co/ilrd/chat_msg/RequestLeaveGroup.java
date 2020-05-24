package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;

public class RequestLeaveGroup extends Request {
	/**
	 * 
	 */
	private static final long serialVersionUID = -2400967658850667596L;
	private int userId;
	private String groupName;
	private static final ChatOps opId = ChatOps.LEAVE_GROUP;

	public RequestLeaveGroup(int userId, String groupName) {
		super(opId);
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
