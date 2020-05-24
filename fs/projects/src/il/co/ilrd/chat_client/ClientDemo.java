package il.co.ilrd.chat_client;

import java.awt.Color;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.HashSet;
import java.util.Set;

import il.co.ilrd.chat_msg.*;


public class ClientDemo {
	int clientId;
	Set<String> groups;
	Socket clientSocket;
	
	MainDetailPanel panel;
	
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
					ResponseOps.valueOf(rep.getOpId().toString()).handleResponse(this, rep, panel);
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
			public void handleResponse(ClientDemo c, Response res, MainDetailPanel panel) {
				ResponseLogin resp = (ResponseLogin) res;
				
				c.clientId = resp.getUserId();
				c.groups = resp.getGroups();

				panel.printToTextArea("welcom to chat hub!",  Color.BLACK);
				panel.printToTextArea("your client id is: " + c.clientId,  Color.BLACK);
				
				panel.getGroups(c.groups);
			}
		},

		CREATE_GROUP {
			@Override
			public void handleResponse(ClientDemo c, Response res, MainDetailPanel panel) {
				ResponseCreateGroup resp = (ResponseCreateGroup) res;
				String newGroup = resp.getGroupName();
				c.groups.add(newGroup);
				panel.addGroup(newGroup);
				
				panel.printToTextArea("You've created group " + newGroup,  Color.BLACK);
			}
		},
		JOIN_GROUP {
			@Override
			public void handleResponse(ClientDemo c, Response res, MainDetailPanel panel) {
				ResponseJoinGroup resp = (ResponseJoinGroup) res;
				int userId = resp.getUserId();
				String newGroup = resp.getGroupName();
				String sender = resp.getSenderName();

				if (userId == c.clientId) {
					c.groups.add(newGroup);
					panel.addGroup(newGroup);
					panel.printToTextArea("Welcom to group " + newGroup,  Color.BLACK);
				}
				else {
					panel.printToTextArea(sender + " has joined group " + newGroup,  Color.BLACK);
					panel.printToTextArea("Say hello!",  Color.BLACK);
				}
			}
		},
		LEAVE_GROUP {
			@Override
			public void handleResponse(ClientDemo c, Response res, MainDetailPanel panel) {
				ResponseLeaveGroup resp = (ResponseLeaveGroup) res;
				int userId = resp.getUserId();
				String group = resp.getGroupName();
				String sender = resp.getSenderName();

				if (userId == c.clientId) {
					c.groups.remove(group);
					panel.removeGroup(group);
					panel.printToTextArea("You just left group " + group,  Color.BLACK);
				}
				else {
					panel.printToTextArea(sender + " has left group " + group, Color.BLACK);
				}
			}
		},
		SEND_MSG {
			@Override
			public void handleResponse(ClientDemo c, Response res, MainDetailPanel panel) {
				ResponseSend resp = (ResponseSend) res;
				int userId = resp.getUserId();
				String group = resp.getGroupName();
				String sender = resp.getSenderName();
				String msg = resp.getMsg();

				if (userId != c.clientId) {
					panel.printToTextArea(sender + " in group " + group + " says:", resp.getProp().getColor());
					panel.printToTextArea(msg, Color.BLACK);
				}
			}
		};

		public abstract void handleResponse(ClientDemo c, Response res, MainDetailPanel panel);
	}
}

