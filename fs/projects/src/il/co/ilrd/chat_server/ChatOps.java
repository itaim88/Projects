package il.co.ilrd.chat_server;

import java.nio.channels.SocketChannel;

import il.co.ilrd.chat_msg.Msg;
import il.co.ilrd.chat_msg.Request;
import il.co.ilrd.chat_msg.RequestCreateGroup;
import il.co.ilrd.chat_msg.RequestJoinGroup;
import il.co.ilrd.chat_msg.RequestLeaveGroup;
import il.co.ilrd.chat_msg.RequestLogin;
import il.co.ilrd.chat_msg.RequestSend;

public enum ChatOps {
	LOGIN {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
			RequestLogin request = (RequestLogin)msg;
			commun.server.logIn(request.getMsgID(), request.getEmail(), request.getUserName(), commun.new SocketPeer(clientSocket));
		}
	},
	CREATE_GROUP {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
			RequestCreateGroup request = (RequestCreateGroup)msg;
			commun.server.createNewGroup(request.getMsgID(), request.getUserId(), request.getGroupName());
		}
	},
	JOIN_GROUP {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
			RequestJoinGroup request = (RequestJoinGroup)msg;
			commun.server.joinGroup(request.getMsgID(), request.getUserId(), request.getGroupName());
		}
	},
	LEAVE_GROUP {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
			RequestLeaveGroup request = (RequestLeaveGroup)msg;
			commun.server.leaveGroup(request.getMsgID(), request.getUserId(), request.getGroupName());
		}
	},
	SEND_MSG {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
			RequestSend request = (RequestSend)msg;
			commun.server.sendMsg(request.getMsgID(), request.getUserId(), request.getGroupName(), request.getMsg());
		}
	};



	public abstract void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun);
	
}
