package il.co.ilrd.chat_server;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;
import java.util.ArrayList;

import org.junit.jupiter.api.Test;

class Cilent {

	public static void main(String[] args) throws IOException, InterruptedException {
		try {
			InetSocketAddress crunchifyAddr = new InetSocketAddress("localhost", 55555);
			SocketChannel socketChannel = SocketChannel.open(crunchifyAddr);
			socketChannel.configureBlocking(false);
	 
			log("Connecting to Server on port 55555...");
	 
			//ArrayList<String> operation = new ArrayList<String>();
	 
			// create a ArrayList with companyName list
			
			//operation.add("LOG_IN[itaim88@gmail.com][ITAI]");
			//operation.add("LOG_IN[other@gmail.com][hello]");
			//operation.add("CREATE_GROUP[1][blueGroup]");
			//operation.add("JOIN[2][1001]");
			
			//for (String op : operation) {
			
			RequestLogin request1 = new RequestLogin(ChatOps.LOGIN, "itaim88@gmail.com", "itai");
			ObjectOutputStream out = new ObjectOutputStream(socketChannel.socket().getOutputStream());
			out.writeObject(request1);
			
			} catch (Exception e) {
				// TODO: handle exception
			}
			//Msg s = new Msg(opId);
			
			
			//	byte[] message = new String(op).getBytes();
			//	ByteBuffer buffer = ByteBuffer.wrap(message);
			//	socketChannel.write(buffer);
	 
			//	log("sending: " + op);
			//	buffer.clear();
 
			// wait for 2 seconds before sending next message
			Thread.sleep(2000);
	
		
		Thread.sleep(1000);
		//crunchifyClient.close();
	}
 
	private static void log(String str) {
		System.out.println(str);
	}
}

