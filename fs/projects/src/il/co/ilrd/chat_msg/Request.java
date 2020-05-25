package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;

public class Request extends Msg{
	
	private ChatOps OpId;
	private static final long serialVersionUID = -2650992229049971411L;

	public Request(ChatOps opId) {
		this.OpId = opId;
	}
	
	public ChatOps getOpId() {
		return OpId;
	}	
}
