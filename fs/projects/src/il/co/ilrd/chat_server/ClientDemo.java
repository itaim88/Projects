package il.co.ilrd.chat_server;

import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.channels.SocketChannel;
import java.util.Scanner;
import java.util.Set;

import il.co.ilrd.chat_msg.RequestCreateGroup;
import il.co.ilrd.chat_msg.RequestLeaveGroup;
import il.co.ilrd.chat_msg.RequestLogin;
import il.co.ilrd.chat_msg.RequestSend;
import il.co.ilrd.chat_msg.Response;
import il.co.ilrd.chat_msg.ResponseCreateGroup;
import il.co.ilrd.chat_msg.ResponseJoinGroup;
import il.co.ilrd.chat_msg.ResponseLeaveGroup;
import il.co.ilrd.chat_msg.ResponseLogin;
import il.co.ilrd.chat_msg.ResponseSend;


public class ClientDemo {
	int clientId;
	Set<String> groups;
	Socket clientSocket;

	public ClientDemo(String hostName, int port) {
		try {
			clientSocket = new Socket(hostName, port);
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

		Thread responseThread = new Thread(() -> {

			while (true) {
				try {
					ObjectInputStream ois = new ObjectInputStream(new DataInputStream(clientSocket.getInputStream()));
					Response rep = (Response) ois.readObject();
					ResponseOps.valueOf(rep.getOpId().toString()).handleResponse(this, rep);
				} catch (IOException | ClassNotFoundException e) {
					e.printStackTrace();
				}
			}
		});
		responseThread.start();
	}

	public void login(String email, String userName) throws IOException {
		RequestLogin req = new RequestLogin(email, userName);

		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		OutputStream outToServer = clientSocket.getOutputStream();
		ObjectOutputStream out = null;

		out = new ObjectOutputStream(bos);   
		out.writeObject(req);
		out.flush();
		byte[] yourBytes = bos.toByteArray();
		outToServer.write(yourBytes);
	}

	public void createGroup(int usrId, String groupName) throws IOException {
		RequestCreateGroup req = new RequestCreateGroup(usrId, groupName);

		System.out.println("new group " + groupName + " id " + usrId);
		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		OutputStream outToServer = clientSocket.getOutputStream();
		ObjectOutputStream out = null;

		out = new ObjectOutputStream(bos);   
		out.writeObject(req);
		out.flush();
		byte[] yourBytes = bos.toByteArray();
		outToServer.write(yourBytes);
	}

	public void leaveGroup(int usrId, String groupName) throws IOException {
		RequestLeaveGroup req = new RequestLeaveGroup(usrId, groupName);

		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		OutputStream outToServer = clientSocket.getOutputStream();
		ObjectOutputStream out = null;

		out = new ObjectOutputStream(bos);   
		out.writeObject(req);
		out.flush();
		byte[] yourBytes = bos.toByteArray();
		outToServer.write(yourBytes);
	}

	public void sendMsg(int userID, String groupName, String msg) throws IOException {

		RequestSend req = new RequestSend(userID, groupName, msg);

		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		OutputStream outToServer = clientSocket.getOutputStream();
		ObjectOutputStream out = null;

		out = new ObjectOutputStream(bos);   
		out.writeObject(req);
		out.flush();
		byte[] yourBytes = bos.toByteArray();
		outToServer.write(yourBytes);

	}

	public enum ResponseOps {
		LOGIN {
			@Override
			public void handleResponse(ClientDemo c, Response res) {
				ResponseLogin resp = (ResponseLogin) res;
				c.clientId = resp.getUserId();
				c.groups = resp.getGroups();

				System.out.println("welcom to chat hub!");
				System.out.println("your client id is: " + c.clientId);
				if (c.groups.size() == 0) {
					System.out.println("You can now join groups and start chatting");
				}
				else {
					System.out.println("you are member in " + c.groups.size() + " groups:");
					for (String group : c.groups) {
						System.out.println(group);
					}
				}
				System.out.println("Enter any operation...");
			}
		},

		CREATE_GROUP {
			@Override
			public void handleResponse(ClientDemo c, Response res) {
				ResponseCreateGroup resp = (ResponseCreateGroup) res;
				String newGroup = resp.getGroupName();
				c.groups.add(newGroup);

				System.out.println("Welcome to group " + newGroup);
				System.out.println("Enter any operation...");
			}
		},
		JOIN_GROUP {
			@Override
			public void handleResponse(ClientDemo c, Response res) {
				ResponseJoinGroup resp = (ResponseJoinGroup) res;
				int userId = resp.getUserId();
				String newGroup = resp.getGroupName();
				String sender = resp.getSenderName();

				if (userId == c.clientId) {
					c.groups.add(newGroup);
					System.out.println("Welcom to group " + newGroup);
				}
				else {
					System.out.println(sender + " has joined group " + newGroup);
					System.out.println("Say hello!");
				}
				System.out.println("Enter any operation...");
			}
		},
		LEAVE_GROUP {
			@Override
			public void handleResponse(ClientDemo c, Response res) {
				ResponseLeaveGroup resp = (ResponseLeaveGroup) res;
				int userId = resp.getUserId();
				String group = resp.getGroupName();
				String sender = resp.getSenderName();

				if (userId == c.clientId) {
					c.groups.remove(group);
					System.out.println("You just left group " + group);
				}
				else {
					System.out.println(sender + " has left group " + group);
				}
				System.out.println("Enter any operation...");
			}
		},
		SEND_MSG {
			@Override
			public void handleResponse(ClientDemo c, Response res) {
				ResponseSend resp = (ResponseSend) res;
				int userId = resp.getUserId();
				String group = resp.getGroupName();
				String sender = resp.getSenderName();
				String msg = resp.getMsg();
				//Color color = resp.getProp().getColor();

				if (userId != c.clientId) {
					System.out.println(sender + " in group " + group + " says:");
					System.out.println(msg);
				}
				System.out.println("Enter any operation...");
			}
		};

		public abstract void handleResponse(ClientDemo c, Response res);
	}
}

