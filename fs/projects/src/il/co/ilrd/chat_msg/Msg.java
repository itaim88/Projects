package il.co.ilrd.chat_msg;

import java.io.Serializable;

public class Msg implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = -9094319427169171676L;
	private static int msgIdCounter = 0;
	private int msgID;


	public Msg() {
		msgID = ++msgIdCounter;
	}

	public Msg(int requestMsgID) {
		this.msgID = requestMsgID;
	}

	public int getMsgID() {
		return msgID;
	}
}

