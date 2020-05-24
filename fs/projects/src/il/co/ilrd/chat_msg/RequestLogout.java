package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;

class RequestLogout extends Request {
	/**
	 * 
	 */
	private static final long serialVersionUID = -4038599863487136690L;
	private int userId;
	private String groupName;
	private String msg;
	private static final ChatOps opId = ChatOps.LOGOUT;

	public RequestLogout(int userId, String groupName) {
		super(opId);
		this.userId = userId;
		this.groupName = groupName;
	}

	public int getUserId() {
		return userId;
	}

	public String getMsg() {
		return msg;
	}
}


