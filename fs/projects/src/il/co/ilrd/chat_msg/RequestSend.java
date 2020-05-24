package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;

public class RequestSend extends Request {
	/**
	 * 
	 */
	private static final long serialVersionUID = -4038599863487136690L;
	private int userId;
	private String groupName;
	private String msg;
	private static final ChatOps opId = ChatOps.SEND_MSG;

	public RequestSend(int userId, String groupName, String msg) {
		super(opId);
		this.userId = userId;
		this.groupName = groupName;
		this.msg = msg;
	}

	public int getUserId() {
		return userId;
	}

	public String getGroupName() {
		return groupName;
	}

	public String getMsg() {
		return msg;
	}
}