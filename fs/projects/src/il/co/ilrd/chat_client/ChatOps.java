package il.co.ilrd.chat_client;

import java.nio.channels.SocketChannel;

import il.co.ilrd.chat_server.Msg;

public enum ChatOps {
	LOGIN {
		@Override
		public void handleMsg(Response msg,  SocketChannel clientSocket) {
			ResponseLogin reply = (ResponseLogin)msg;
			commun.server.logIn(reply.getMsgID(), reply.getEmail(), reply.getUserName());
		}
	},
	CREATE_GROUP {
		@Override
		public void handleMsg(Response msg,  SocketChannel clientSocket) {
			ResponseCreateGroup reply = (ResponseCreateGroup)msg;
			commun.server.createNewGroup(reply.getMsgID(), reply.getUserId(), reply.getGroupName());
		}
	},
	JOIN_GROUP {
		@Override
		public void handleMsg(Response msg,  SocketChannel clientSocket) {
			ResponseJoinGroup reply = (ResponseJoinGroup)msg;
			commun.server.joinGroup(reply.getMsgID(), reply.getUserId(), reply.getGroupName());
		}
	},
	LEAVE_GROUP {
		@Override
		public void handleMsg(Response msg,  SocketChannel clientSocket) {
			ResponseLeaveGroup reply = (ResponseLeaveGroup)msg;
			commun.server.leaveGroup(reply.getMsgID(), reply.getUserId(), reply.getGroupName());
		}
	},
	SEND_MSG {
		@Override
		public void handleMsg(Response msg,  SocketChannel clientSocket) {
			ResponseSend reply = (ResponseSend)msg;
			commun.server.sendMsg(reply.getMsgID(), reply.getUserId(), reply.getGroupName(), reply.getMsg());
		}
	},

	LOGOUT {
		@Override
		public void handleMsg(Response msg,  SocketChannel clientSocket) {
//			RequestLogout reply = (RequestLogin)msg;
//			commun.server.logIn(reply.getMsgID(), reply.getEmail(), reply.getUserName(), commun. new SocketPeer(clientSocket));
		}
	};

	public abstract void handleMsg(Response msg,  SocketChannel clientSocket);
	
}
