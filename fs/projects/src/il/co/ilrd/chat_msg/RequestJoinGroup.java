package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;

public class RequestJoinGroup extends Request {
	/**
	 * 
	 */
	private static final long serialVersionUID = -6996446904646899058L;
	private int userId;
	private String groupName;
	private static final ChatOps opId = ChatOps.JOIN_GROUP;

	public RequestJoinGroup(int userId, String groupName) {
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
