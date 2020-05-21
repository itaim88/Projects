package il.co.ilrd.chat_server;

import il.co.ilrd.chat_server.ChatServerHub;
import il.co.ilrd.chat_server.TCPCommunication;

public class ServerDemo {
	public static void main(String[] args) {
		new Thread (() -> {new TCPCommunication(new ChatServerHub()).Init(); }).start();
	}
}
