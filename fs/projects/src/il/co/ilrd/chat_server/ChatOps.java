package il.co.ilrd.chat_server;

import java.nio.channels.SocketChannel;

public enum ChatOps {
	LOGIN {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
		}
	},
	CREATE_GROUP {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
		}
	},
	JOIN_GROUP {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
		}
	},
	LEAVE_GROUP {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
		}
	},
	SEND_MSG {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
		}
	},

	LOGOUT {
		@Override
		public void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun) {
			
		}
	};

	public abstract void handleMsg(Request msg,  SocketChannel clientSocket, TCPCommunication commun);
	
}
