package il.co.ilrd.chat_msg;

import java.io.Serializable;

import il.co.ilrd.chat_server.*;

public class Msg implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = -9094319427169171676L;
	private static int msgIdCounter = 0;
	private int msgID;
	private ChatOps OpId;

	public Msg(ChatOps opId) {
		msgID = ++msgIdCounter;
		this.OpId = opId;
	}

	public Msg(ChatOps opId, int requestMsgID) {
		this.msgID = requestMsgID;
		this.OpId = opId;
	}

	public int getMsgID() {
		return msgID;
	}

	public ChatOps getOpId() {
		return OpId;
	}	
}

