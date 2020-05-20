package il.co.ilrd.chat_server;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.ByteChannel;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;
import java.nio.channels.SelectionKey;

public class TCPCommunication implements Communication {
	private ChatServer server;
	private int port;
	private boolean openClientServer = true;

	public TCPCommunication(ChatServer server, int port) {
		this.port = port;
		this.server = server;
	}

	@Override
	public void Init() {
		//thread????
		
		try {
			Selector selector = Selector.open(); 
			ServerSocketChannel serverSocket = ServerSocketChannel.open();
			InetSocketAddress SocketAdd = new InetSocketAddress("localhost", port);
			serverSocket.bind(SocketAdd);
			serverSocket.configureBlocking(false);
			int ops = serverSocket.validOps();
			SelectionKey selectKy = serverSocket.register(selector, ops, null);
	 
			System.out.println(("i'm a server and i'm waiting for new connection and buffer select..."));
			
			while (openClientServer) {
				while (selector.selectNow() == 0); //select?
				
				Set<SelectionKey> selectKey = selector.selectedKeys();
				Iterator<SelectionKey> keyIter = selectKey.iterator();
				
				while (keyIter.hasNext()) {
					SelectionKey myKey = keyIter.next();
	 
					// Tests whether this key's channel is ready to accept a new socket connection
					if (myKey.isAcceptable()) {
						SocketChannel clientChanel = serverSocket.accept();
	 
						// Adjusts this channel's blocking mode to false
						clientChanel.configureBlocking(false);
	 
						// Operation-set bit for read operations
						clientChanel.register(selector, SelectionKey.OP_READ);
						System.out.println(("Connection Accepted: " + clientChanel.getLocalAddress() + "\n"));
	 
						// Tests whether this key's channel is ready for reading
					} else if (myKey.isReadable()) {
						SocketChannel socketclient = (SocketChannel) myKey.channel();
						ByteBuffer buffer = ByteBuffer.allocate(256);
						try {
							socketclient.read(buffer);
						} catch (IOException e) {
							//ChatOps.LOGOUT.functionHandler(null, socketclient, this);
							break;
						}
						
						String result = new String(buffer.array()).trim();
						System.out.println("Message received: " + result);
						StringTokenizer st = new StringTokenizer(result,"[]");
						
						//ChatOps.valueOf(st.nextToken()).functionHandler(st, socketclient, this);
						
						if (result.equals("Crunchify")) {
							socketclient.close();
							System.out.println("\nIt's time to close connection as we got last company name 'Crunchify'");
							System.out.println("\nServer will keep running. Try running client again to establish new connection");
						}
					}
					
					keyIter.remove();
			}
		}
		
		} catch(IOException e) {
			e.printStackTrace();
		} 
	}
	
	private static class SocketPeer implements Peer {
		private SocketChannel clientSocket;

		public SocketPeer(SocketChannel clientSocket) {
			this.clientSocket = clientSocket;
		}

		@Override
		public void responseMessage(int msgID, int userID, String userName, String groupName, UsrProperties prop,
				String message, Status status) {
				ResponseSend response = new ResponseSend(msgID, status, userID, groupName, message, userName, prop);
			try {
				ObjectOutputStream out = new ObjectOutputStream(clientSocket.socket().getOutputStream());
				out.writeObject(response);
			} catch (IOException e) {
				e.printStackTrace();
			}
			
		}
	
		@Override
		public void responseJoinGroup(int msgID, int userID, String userName, String groupName, Status status) {
			ResponseJoinGroup response = new ResponseJoinGroup(userID, status, userID, groupName, userName);
			try {
				ObjectOutputStream out = new ObjectOutputStream(clientSocket.socket().getOutputStream());
				out.writeObject(response);
			} catch (IOException e) {
				e.printStackTrace();
			}
			
		}

		@Override
		public void responseLogin(int msgID, int userID, Set<String> groupNames, Status status) {
			ResponseLogin response = new ResponseLogin(userID, status, userID, groupNames);
			try {
				ObjectOutputStream out = new ObjectOutputStream(clientSocket.socket().getOutputStream());
				out.writeObject(response);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		@Override
		public void responseCreateGroup(int msgID, String groupName, Status status) {
			ResponseCreateGroup response = new ResponseCreateGroup(msgID, status, groupName);
			try {
				ObjectOutputStream out = new ObjectOutputStream(clientSocket.socket().getOutputStream());
				out.writeObject(response);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
			
		

		@Override
		public void responseLeaveGroup(int msgID, int userID, String userName, String groupName, Status status) {
			// TODO Auto-generated method stub
			
		}

	}
	
	public static void main(String[] args) throws IOException {
		TCPCommunication t = new TCPCommunication(new ChatServerHub(), 55555);
		t.Init();
		
	}
}
