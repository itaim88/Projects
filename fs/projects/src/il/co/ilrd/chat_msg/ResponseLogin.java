package il.co.ilrd.chat_msg;

import java.util.Set;

import il.co.ilrd.chat_server.ChatOps;
import il.co.ilrd.chat_server.Status;

public class ResponseLogin extends Response {
	/**
	 * 
	 */
	private static final long serialVersionUID = -5773082868149152439L;
	private int userId;
	private Set<String> groups;
	private static final ChatOps opId = ChatOps.LOGIN;

	public ResponseLogin(int requestMsgID, int userId, Set<String> groups, Status status) {
		super(opId, requestMsgID, status);
		this.userId = userId;
		this.groups = groups;
	}

	public int getUserId() {
		return userId;
	}

	public Set<String> getGroups() {
		return groups;
	}
}