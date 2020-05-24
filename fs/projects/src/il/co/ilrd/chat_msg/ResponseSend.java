package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;
import il.co.ilrd.chat_server.Status;
import il.co.ilrd.chat_server.UsrProperties;

public class ResponseSend extends Response {

	/**
	 * 
	 */
	private static final long serialVersionUID = -8256573155482333074L;
	private int userId;
	private String groupName;
	private String msg;
	private String senderName;
	private UsrProperties prop;
	private static final ChatOps opId = ChatOps.SEND_MSG;

	public ResponseSend(int requestMsgID, int userId, String groupName, String msg, String senderName, UsrProperties prop, Status status) {
		super(opId, requestMsgID, status);
		this.userId = userId;
		this.groupName = groupName;
		this.msg = msg;
		this.senderName = senderName;
		this.prop = prop;
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
	public String getSenderName() {
		return senderName;
	}
	public UsrProperties getProp() {
		return prop;
	}
}