package il.co.ilrd.chat_msg;

import il.co.ilrd.chat_server.ChatOps;
import il.co.ilrd.chat_server.Status;

public class Response extends Msg{
	private Status status;

	public Response(ChatOps opId, int requestMsgID, Status status) {
		super(opId, requestMsgID);
		this.status = status;
	}

	public Status getStatus() {
		return status;
	}
}
