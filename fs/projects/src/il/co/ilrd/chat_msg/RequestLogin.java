package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;

public class RequestLogin extends Request {
	/**
	 * 
	 */
	private static final long serialVersionUID = -2309362424242713828L;
	private String email;
	private String userName;
	private static final ChatOps opId = ChatOps.LOGIN;

	public RequestLogin(String email, String userName) {
		super(opId);
		this.email = email;
		this.userName = userName;
	}

	public String getEmail() {
		return email;
	}

	public String getUserName() {
		return userName;
	}
}
