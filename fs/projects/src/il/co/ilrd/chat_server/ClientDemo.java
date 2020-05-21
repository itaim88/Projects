package il.co.ilrd.chat_server;

import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.nio.channels.SocketChannel;
import java.util.Scanner;

public class ClientDemo {

	public static void main(String[] args) throws IOException, ClassNotFoundException {
		Socket clientSocket = new Socket("localhost", 55555);

		for (int i = 0; i < 10; ++i) {
			ByteArrayOutputStream bos = new ByteArrayOutputStream();
			OutputStream outToServer = clientSocket.getOutputStream();
			ObjectOutputStream out = null;
			Scanner myObj = new Scanner(System.in); 
			System.out.println("Enter operation");
			String operation = myObj.nextLine(); 

			Request req = ClientOps.valueOf(operation).handleMsg(new Scanner(System.in)); 

			out = new ObjectOutputStream(bos);   
			out.writeObject(req);
			out.flush();
			byte[] yourBytes = bos.toByteArray();
			outToServer.write(yourBytes);

			ObjectInputStream ois = new ObjectInputStream(new DataInputStream(clientSocket.getInputStream()));
			Response rep = (Response) ois.readObject();
			System.out.println(rep.getMsgID());
			System.out.println(rep.getStatus());
			System.out.println(rep.getOpId());
		}
		try {
			Thread.sleep(10000);
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
				String userID = s.nextLine(); 
				System.out.println("Enter groupName");
				String groupName = s.nextLine();
				return new RequestCreateGroup(Integer.parseInt(userID), groupName);
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
}
