package il.co.ilrd.chat_server;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.ByteChannel;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.rmi.server.SocketSecurityException;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;
import java.nio.channels.SelectionKey;

public class TCPCommunication implements Communication {
	private ChatServer server;
	private int port;
	//private Selector selector = null;
	private boolean openClientServer = true;

	public TCPCommunication(ChatServer server, int port) {
		this.port = port;
		this.server = server;
	}

	public enum ChatOperation {
		LOG_IN (1) {
			@Override
			void functionHandler(StringTokenizer str, SocketChannel client, TCPCommunication communication) {

				communication.server.logIn(str.nextToken(), str.nextToken(), new SocketPeer(client));
			}
		},
		
		CREATE_GROUP (2) {
			@Override
			void functionHandler(StringTokenizer str, SocketChannel client, TCPCommunication communication) {
				communication.server.createNewGroup(Integer.parseInt(str.nextToken()), str.nextToken());
			}
		},
		
		JOIN (3) {
			@Override
			void functionHandler(StringTokenizer str, SocketChannel client, TCPCommunication communication) {
				communication.server.joinGroup(Integer.parseInt(str.nextToken()), Integer.parseInt(str.nextToken()));
			}
		},
	
		SEND (4) {
			@Override
			void functionHandler(StringTokenizer str, SocketChannel client, TCPCommunication communication) {
				communication.server.sendMsg(Integer.parseInt(str.nextToken()), Integer.parseInt(str.nextToken()), str.nextToken());
			}	
			
		},

		LEAVE (5) {
			@Override
			void functionHandler(StringTokenizer str, SocketChannel client, TCPCommunication communication) {
				communication.server.leaveGroup(Integer.parseInt(str.nextToken()), Integer.parseInt(str.nextToken()));
			}	
			
		},
		
		LOGOUT (6) {
			@Override
			void functionHandler(StringTokenizer str, SocketChannel client, TCPCommunication communication) {
				//openClientServer = false;

				}	
		
		};
					
		private int opNum;
		
		private ChatOperation(int opNum)  {
			this.opNum = opNum;
			
		}
		
		abstract void functionHandler(StringTokenizer str, SocketChannel client, TCPCommunication communication);
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
						SocketChannel crunchifyClient = serverSocket.accept();
	 
						// Adjusts this channel's blocking mode to false
						crunchifyClient.configureBlocking(false);
	 
						// Operation-set bit for read operations
						crunchifyClient.register(selector, SelectionKey.OP_READ);
						System.out.println(("Connection Accepted: " + crunchifyClient.getLocalAddress() + "\n"));
	 
						// Tests whether this key's channel is ready for reading
					} else if (myKey.isReadable()) {
						SocketChannel socketclient = (SocketChannel) myKey.channel();
						ByteBuffer crunchifyBuffer = ByteBuffer.allocate(256);
						socketclient.read(crunchifyBuffer);
						String result = new String(crunchifyBuffer.array()).trim();
	 
						System.out.println("Message received: " + result);
					
						StringTokenizer st = new StringTokenizer(result,"[]");
						
						 ChatOperation.valueOf(st.nextToken()).functionHandler(st, socketclient, this);
						
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
		public void sendMessage(String senderName, int groupID, UsrProperties prop, String message) {
			// TODO Auto-generated method stub	
		}

		@Override
		public void sendAddToGRoup(int status) {}

		@Override
		public void sendNewGroupMember(int newUsrID) {}
		
		@Override
		public void sendLogin(int userID, List<Integer> groupID) {
			StringBuilder str = new StringBuilder();
			str.append("LOG_IN[");
			str.append(userID);
			str.append("]");
			
			for (Integer i : groupID) {
				str.append("[");
				str.append(i);
				str.append("]");
			}
			
			System.out.println(str);
			byte[] message = new String(str).getBytes();
			ByteBuffer buffer = ByteBuffer.wrap(message);
			try {
				clientSocket.write(buffer);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
		}
		
		@Override
		public void sendCreateGroup(int groupID, int groupName) {}
		
		@Override
		public void sendLeaveGroup(int status) {}
	}
	
	public static void main(String[] args) throws IOException {
		TCPCommunication t = new TCPCommunication(new ChatServerHub(), 55555);
		t.Init();
		
	}
}
