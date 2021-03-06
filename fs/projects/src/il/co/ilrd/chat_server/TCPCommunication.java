package il.co.ilrd.chat_server;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.Channels;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.Set;

import il.co.ilrd.chat_msg.Request;
import il.co.ilrd.chat_msg.ResponseCreateGroup;
import il.co.ilrd.chat_msg.ResponseJoinGroup;
import il.co.ilrd.chat_msg.ResponseLeaveGroup;
import il.co.ilrd.chat_msg.ResponseLogin;
import il.co.ilrd.chat_msg.ResponseSend;

public class TCPCommunication implements Communication {

	public ChatServer server;
	private int port = 55555;
	private Selector selector;
	private ServerSocketChannel serverChannel;
	private ServerSocket serverSocket;
	private SocketChannel channel;

	public TCPCommunication(ChatServer server) {
		this.server = server;
	}
	{
		try {
			selector = Selector.open();
			serverChannel = ServerSocketChannel.open();
			serverSocket =  serverChannel.socket();
			serverSocket.bind(new InetSocketAddress("localhost", port));
			serverChannel.configureBlocking(false);
			serverChannel.register(selector, SelectionKey.OP_ACCEPT);

		} catch (IOException e) {
			System.err.println(e.getMessage());
			e.printStackTrace();
		}
	}

	@Override
	public void Init() {
		
			while(true) {
				
				try {
					selector.select();
				} catch (IOException e) {
					e.printStackTrace();
				}
				
				Iterator<SelectionKey> keyIterator = selector.selectedKeys().iterator();

				while(keyIterator.hasNext()) {
					SelectionKey currentKey = keyIterator.next();
					if (currentKey.isAcceptable()) {
						ServerSocketChannel server = (ServerSocketChannel) currentKey.channel();
						SocketChannel client;
						try {
							client = server.accept();
							client.configureBlocking(false);
							client.register(selector, SelectionKey.OP_READ);
						} catch (IOException e) {
							e.printStackTrace();
						}
					}

					else if(currentKey.isReadable()) {
						channel = (SocketChannel) currentKey.channel();
						ByteBuffer buffer =  ByteBuffer.allocate(2048);
						try {
							if (-1 == channel.read(buffer)) {
								currentKey.cancel();
								keyIterator.remove();
								continue;
							}
							Request request = null;
							ByteArrayInputStream bis = new ByteArrayInputStream(buffer.array());
							ObjectInputStream ois;
							ois = new ObjectInputStream(bis);
							Object obj = ois.readObject();
							if (obj instanceof Request) {
								request = (Request)obj;
								request.getOpId().handleMsg(request, channel, this);	
							}
							else { 
								currentKey.cancel();
								keyIterator.remove();
								continue;
							}
							
						} catch (IOException e) {
							currentKey.cancel();
							keyIterator.remove();
							continue;
							
						} catch (ClassNotFoundException e) {
							continue;
						}		
					}

					keyIterator.remove(); 
				}
			}
	}

	class SocketPeer implements Peer {
		private SocketChannel clientSocket = null;

		public SocketPeer(SocketChannel clientSocket) {
			this.clientSocket = clientSocket;
		}

		@Override
		public void responseMessage(int msgID, int userID, String userName, String groupName, UsrProperties prop,
				String message, Status status) {
			try {
				if (status != Status.SUCCESS) {return;}
				
				ResponseSend reply = new ResponseSend(msgID, userID, groupName, message, userName, prop, status);
				ByteArrayOutputStream bos = new ByteArrayOutputStream();
				ObjectOutputStream out = new ObjectOutputStream(bos);
				out.writeObject(reply);
				out.flush();
				ByteBuffer bb = ByteBuffer.wrap(bos.toByteArray());
				clientSocket.write(bb);

			} catch (IOException e) {
				try {
					clientSocket.close();
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		}

		@Override
		public void responseJoinGroup(int msgID, int userID, String userName, String groupName, Status status) {
			try {
				if (status != Status.SUCCESS) {return;}
				
				ResponseJoinGroup reply = new ResponseJoinGroup(msgID, userID, groupName, userName, status);
				ByteArrayOutputStream bos = new ByteArrayOutputStream();
				ObjectOutputStream out = new ObjectOutputStream(bos);
				out.writeObject(reply);
				out.flush();
				ByteBuffer bb = ByteBuffer.wrap(bos.toByteArray());
				clientSocket.write(bb);
			} catch (IOException e) {
				try {
					clientSocket.close();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}		
		}

		@Override
		public void responseLogin(int msgID, int userID, Set<String> groupNames, Status status) {
			try {
				if (status != Status.SUCCESS) {return;}
				
				ResponseLogin reply = new ResponseLogin(msgID, userID, groupNames, status);
				ByteArrayOutputStream bos = new ByteArrayOutputStream();
				ObjectOutputStream out = new ObjectOutputStream(bos);
				out.writeObject(reply);
				out.flush();
				ByteBuffer bb = ByteBuffer.wrap(bos.toByteArray());
				clientSocket.write(bb);
			} catch (IOException e) {
				try {
					clientSocket.close();
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		}

		@Override
		public void responseCreateGroup(int msgID, String groupName, Status status) {
			try {
				if (status != Status.SUCCESS) {return;}
				
				ResponseCreateGroup reply = new ResponseCreateGroup(msgID, groupName, status);
				ByteArrayOutputStream bos = new ByteArrayOutputStream();
				ObjectOutputStream out = new ObjectOutputStream(bos);
				out.writeObject(reply);
				out.flush();
				ByteBuffer bb = ByteBuffer.wrap(bos.toByteArray());
				clientSocket.write(bb);
			} catch (IOException e) {
				try {
					clientSocket.close();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		}

		@Override
		public void responseLeaveGroup(int msgID, int userID, String userName, String groupName, Status status) {
			try {
				if (status != Status.SUCCESS) {return;}
				
				ResponseLeaveGroup reply = new ResponseLeaveGroup(msgID, userID, groupName, userName, status);
				ByteArrayOutputStream bos = new ByteArrayOutputStream();
				ObjectOutputStream out = new ObjectOutputStream(bos);
				out.writeObject(reply);
				out.flush();
				ByteBuffer bb = ByteBuffer.wrap(bos.toByteArray());
				clientSocket.write(bb);
			} catch (IOException e) {
				try {
					clientSocket.close();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		}
	}
}
