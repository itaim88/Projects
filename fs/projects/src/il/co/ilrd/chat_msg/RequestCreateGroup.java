package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;

public class RequestCreateGroup extends Request {
	/**
	 * 
	 */
	private static final long serialVersionUID = -63878996156234175L;
	private int userId;
	private String groupName;
	private static final ChatOps opId = ChatOps.CREATE_GROUP;

	public RequestCreateGroup(int userId, String groupName) {
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
