package il.co.ilrd.chat_server;

import static org.junit.jupiter.api.Assertions.*;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;
import java.util.ArrayList;
import java.util.Scanner;

import org.junit.jupiter.api.Test;

class Cilent {

	public static void main(String[] args) throws IOException, InterruptedException {
		 
		InetSocketAddress crunchifyAddr = new InetSocketAddress("localhost", 55555);
		SocketChannel crunchifyClient = SocketChannel.open(crunchifyAddr);
 
		log("Connecting to Server on port 1111...");
 
		ArrayList<String> companyDetails = new ArrayList<String>();
 
		// create a ArrayList with companyName list
		
		companyDetails.add("LOG_IN[itaim88@gmail.com][ITAI]");
		companyDetails.add("LOG_IN[other@gmail.com][hello]");

		for (String companyName : companyDetails) {
 
			byte[] message = new String(companyName).getBytes();
			ByteBuffer buffer = ByteBuffer.wrap(message);
			crunchifyClient.write(buffer);
 
			log("sending: " + companyName);
			buffer.clear();
 
			// wait for 2 seconds before sending next message
			Thread.sleep(2000);
		}
		
		//Thread.sleep(10000);
		//crunchifyClient.close();
	}
 
	private static void log(String str) {
		System.out.println(str);
	}
}

