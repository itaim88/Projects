package il.co.ilrd.chat_client;

import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import il.co.ilrd.chat_msg.Request;
import il.co.ilrd.chat_msg.RequestCreateGroup;
import il.co.ilrd.chat_msg.RequestJoinGroup;
import il.co.ilrd.chat_msg.RequestLeaveGroup;
import il.co.ilrd.chat_msg.RequestLogin;
import il.co.ilrd.chat_msg.RequestSend;
import il.co.ilrd.chat_msg.Response;

public class ChatClient {
	private Socket clientSocket = null;
	private Set<String> groupNames = new HashSet<>();
	int clientId = 0;

	public ChatClient() {
		try {
			this.clientSocket = new Socket("localhost", 55555);
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void responseThread() {
		new Thread(() -> {ObjectInputStream ois = null;
		try {
			ois = new ObjectInputStream(new DataInputStream(clientSocket.getInputStream()));
		} catch (IOException e) {
			e.printStackTrace();
		}
		Response res = null;
		try {
			res = (Response) ois.readObject();
			ResponseOps.valueOf(res.getOpId().toString());
		} catch (ClassNotFoundException | IOException e) {
			e.printStackTrace();
		}
		System.out.println(res.getMsgID());
		System.out.println(res.getStatus());
		System.out.println(res.getOpId());}).start();
	}

	public void other() {
		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		OutputStream outToServer = null;
		try {
			outToServer = clientSocket.getOutputStream();
		} catch (IOException e) {
			e.printStackTrace();
		}
		ObjectOutputStream out = null;

		Scanner myObj = new Scanner(System.in); 
		System.out.println("Enter operation");
		String operation = myObj.nextLine(); 

		try {
			out = new ObjectOutputStream(bos);
			Request req = ClientOps.valueOf(operation).handleMsg(myObj);
			out.writeObject(req);
			out.flush();
			byte[] yourBytes = bos.toByteArray();
			outToServer.write(yourBytes);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		ChatClient chatClient = new ChatClient();
		chatClient.responseThread();
		chatClient.other();
		try {
			Thread.sleep(100000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public enum ClientOps {
		LOGIN {
			@Override
			public Request handleMsg(Scanner s) {
				System.out.println("Enter username");
				String userName = s.nextLine(); 
				System.out.println("Enter mail");
				String mail = s.nextLine();
				return new RequestLogin(mail,userName);
			}
		},

		CREATE_GROUP {
			@Override
			public Request handleMsg(Scanner s) {
				System.out.println("Enter userID");
				Integer userID = Integer.parseInt(s.nextLine()); 
			
				System.out.println("Enter groupName");
				String groupName = s.nextLine();
				return new RequestCreateGroup(userID, groupName);
			}
		},
		
		JOIN_GROUP {
			@Override
			public Request handleMsg(Scanner s) {
				System.out.println("Enter userID");
				String userID = s.nextLine(); 
				System.out.println("Enter groupName");
				String groupName = s.nextLine();
				return new RequestJoinGroup(Integer.parseInt(userID), groupName);
			}
		},
		LEAVE_GROUP {
			@Override
			public Request handleMsg(Scanner s) {
				System.out.println("Enter userID");
				String userID = s.nextLine(); 
				System.out.println("Enter groupName");
				String groupName = s.nextLine();
				return new RequestLeaveGroup(Integer.parseInt(userID), groupName);
			}
		},
		SEND_MSG {
			@Override
			public Request handleMsg(Scanner s) {
				System.out.println("Enter userID");
				String userID = s.nextLine(); 
				System.out.println("Enter groupName");
				String groupName = s.nextLine();
				System.out.println("Enter msg");
				String msg = s.nextLine();
				return new RequestSend(Integer.parseInt(userID),groupName,msg);

			}
		};
		/*
			LOGOUT {
				@Override
				public Request handleMsg(Scanner s) {
					System.out.println("Enter userID");
					String userID = s.nextLine(); 
					System.out.println("Enter groupName");
					String groupName = s.nextLine();
					System.out.println("Enter msg");
					String msg = s.nextLine();
					return new Reques(Integer.parseInt(userID),groupName,msg);

				}
			};
		 */


		public abstract Request handleMsg(Scanner s);
	}

	public enum ResponseOps {
		LOGIN {
			@Override
			public void handleResponse(Response response) {
				// TODO Auto-generated method stub

			}
		},
		CREATE_GROUP {
			@Override
			public void handleResponse(Response response) {
				// TODO Auto-generated method stub

			}
		},
		JOIN_GROUP {
			@Override
			public void handleResponse(Response response) {
				// TODO Auto-generated method stub

			}
		},
		LEAVE_GROUP {
			@Override
			public void handleResponse(Response response) {
				// TODO Auto-generated method stub

			}
		},
		SEND_MSG {
			@Override
			public void handleResponse(Response response) {
				// TODO Auto-generated method stub

			}
		};

		public abstract void handleResponse(Response response);
	}
}
