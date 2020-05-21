package il.co.ilrd.chat_server;

import java.io.Serializable;
import java.util.Set;

import il.co.ilrd.chat_server.ChatOps;

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

class Request extends Msg{
    public Request(ChatOps opId) {
        super(opId);
    }
}

class Response extends Msg{
    private Status status;
    
    public Response(ChatOps opId, int requestMsgID, Status status) {
        super(opId, requestMsgID);
        this.status = status;
    }
    
    public Status getStatus() {
        return status;
    }
}

class RequestLogin extends Request {
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

class RequestCreateGroup extends Request {
	/**
	 * 
	 */
	private static final long serialVersionUID = -63878996156234175L;
	private int userId;
	private String groupName;
	private static final ChatOps opId = ChatOps.CREATE_GROUP;
	
	public RequestCreateGroup(int userId, String groupName) {
		super(opId);
		this.userId = userId;
		this.groupName = groupName;
	}
	
	public int getUserId() {
		return userId;
	}
	
	public String getGroupName() {
		return groupName;
	}
}

class RequestJoinGroup extends Request {
	/**
	 * 
	 */
	private static final long serialVersionUID = -6996446904646899058L;
	private int userId;
	private String groupName;
	private static final ChatOps opId = ChatOps.JOIN_GROUP;
	
	public RequestJoinGroup(int userId, String groupName) {
		super(opId);
		this.userId = userId;
		this.groupName = groupName;
	}
	
	public int getUserId() {
		return userId;
	}

	public String getGroupName() {
		return groupName;
	}
}

class RequestLeaveGroup extends Request {
	/**
	 * 
	 */
	private static final long serialVersionUID = -2400967658850667596L;
	private int userId;
	private String groupName;
	private static final ChatOps opId = ChatOps.LEAVE_GROUP;
	
	public RequestLeaveGroup(int userId, String groupName) {
		super(opId);
		this.userId = userId;
		this.groupName = groupName;
	}
	
	public int getUserId() {
		return userId;
	}
	
	public String getGroupName() {
		return groupName;
	}
}

class RequestSend extends Request {
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

class ResponseLogin extends Response {
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

class ResponseCreateGroup extends Response {
	/**
	 * 
	 */
	private static final long serialVersionUID = -838016303129502199L;
	private int userId;
	private String groupName;
	private static final ChatOps opId = ChatOps.CREATE_GROUP;
	
	public ResponseCreateGroup(int requestMsgID, String groupName, Status status) {
		super(opId, requestMsgID, status);
		this.userId = userId;
		this.groupName = groupName;
	}

	public int getUserId() {
		return userId;
	}

	public String getGroupName() {
		return groupName;
	}
}

class ResponseJoinGroup extends Response {
	/**
	 * 
	 */
	private static final long serialVersionUID = 740161959953103624L;
	private int userId;
	private String groupName;
	private String senderName;
	private static final ChatOps opId = ChatOps.JOIN_GROUP;
	
	public ResponseJoinGroup(int requestMsgID, int userId, String groupName, String senderName, Status status) {
		super(opId, requestMsgID, status);
		this.userId = userId;
		this.groupName = groupName;
		this.senderName = senderName;
	}

	public int getUserId() {
		return userId;
	}

	public String getGroupName() {
		return groupName;
	}
	public String getSenderName() {
	    return senderName;
	}
}

class ResponseLeaveGroup extends Response {
	/**
	 * 
	 */
	private static final long serialVersionUID = -246542286706772128L;
	private int userId;
	private String groupName;
	private String senderName;
	private static final ChatOps opId = ChatOps.LEAVE_GROUP;
	
	public ResponseLeaveGroup(int requestMsgID, int userId, String groupName, String senderName, Status status) {
		super(opId, requestMsgID, status);
		this.userId = userId;
		this.groupName = groupName;
		this.senderName = senderName;
	}

	public int getUserId() {
		return userId;
	}

	public String getGroupName() {
		return groupName;
	}
	
	public String getSenderName() {
	    return senderName;
	}
} 

class ResponseSend extends Response {
	
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