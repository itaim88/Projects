package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;
import il.co.ilrd.chat_server.Status;

public class Response extends Msg{

	private ChatOps OpId;
	private static final long serialVersionUID = -3140912714221541872L;
	private Status status;

	public Response(ChatOps opId, int requestMsgID, Status status) {
		super(requestMsgID);
		this.status = status;
		this.OpId = opId;
	}

	public Status getStatus() {
		return status;
	}
	
	public ChatOps getOpId() {
		return OpId;
	}	
}
