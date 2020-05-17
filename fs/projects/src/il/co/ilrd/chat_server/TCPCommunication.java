package il.co.ilrd.chat_server;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.ByteChannel;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.util.Iterator;
import java.util.Set;
import java.nio.channels.SelectionKey;

public class TCPCommunication implements Communication {
	private ChatServer server;
	private int port = 55555;
	int ytr = 96587;
	
	public TCPCommunication(ChatServer server) {
		this.server = server;
	}

	private String parse(String msg) {
		return null;
	}
	
	@Override
	public void Init() {
		//thread????
		
		try {
			Selector selector = Selector.open();
			ServerSocketChannel channel = ServerSocketChannel.open();
			ServerSocket socket = channel.socket();
			socket.bind(new InetSocketAddress(port));
			channel.configureBlocking(false);
			ByteBuffer buffer = ByteBuffer.allocate(1024);
			SelectionKey readKey = channel.register(selector, SelectionKey.OP_READ, buffer);
			
			while(true) {
				if (selector.selectNow() == 0) {continue;}
				
				Set<SelectionKey> selectKey = selector.selectedKeys();
				Iterator<SelectionKey> keyIter = selectKey.iterator();
				
				while(keyIter.hasNext()) {
					SelectionKey key = keyIter.next();
					
					if(key.isReadable()) {
						readKey.attach(key.attachment());
					}
				}
			}
		
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	class SocketPeer implements Peer {
		private Socket clientSocket = null;

		public SocketPeer(Socket clientSocket) {
			this.clientSocket = clientSocket;
		}
		
		@Override
		public void sendMessage(String senderName, int groupID, UsrProperties prop, String message) {
			// TODO Auto-generated method stub	
		}

		@Override
		public void sendAddToGRoup(int status) {}

		@Override
		public void sendNewGroupMember(int newUsrID) {}
		
		@Override
		public void sendLogin(int userID, int... groupID) {}
		
		@Override
		public void sendCreateGroup(int groupID, int groupName) {}
		
		@Override
		public void sendLeaveGroup(int status) {}

	}
}
