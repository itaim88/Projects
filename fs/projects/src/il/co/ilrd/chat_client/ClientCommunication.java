package il.co.ilrd.chat_client;

import java.net.InetAddress;
import java.nio.channels.SocketChannel;

public class ClientCommunication {

	private ChatClient client;
	private InetAddress address;
	private SocketChannel socket;
	private Thread response;
	
	class ClientPeer implements Peer {

		@Override
		public void requestMessage(int userId, String groupName, String msg) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void requestJoinGroup(int userId, String groupName) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void requestLogin(String email, String userName) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void requestCreateGroup(int userId, String groupName) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void requestLeaveGroup(int userId, String groupName) {
			// TODO Auto-generated method stub
			
		}
		
	}
}
