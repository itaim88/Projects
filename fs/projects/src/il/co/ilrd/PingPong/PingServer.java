package il.co.ilrd.PingPong;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;
public class PingServer {
	private static final int PORT = 50000;
	private static final int MESSAGE_SIZE = 4;
	static boolean flaga = true;
	private static String str = "PONG";
	private static  byte[] message = new byte[1600];

	private static ServerSocket serverSocket;
	private static Socket clientSocket;

	public static void main(String[] args) throws IOException
	{
	    serverSocket = null;
	    try
	    {
	        serverSocket = new ServerSocket(PORT);
	    }
	    catch(IOException e)
	    {
	        System.err.println("Could not listen on port: " + PORT);
	        System.exit(1);
	    }

	    System.out.print("Wating for connection...");

	    clientSocket = null;
	    try
	    {
	        clientSocket = serverSocket.accept();
	        System.out.println("Connection established");
	        flaga = false;
	    }
	    catch(IOException e)
	    {
	        System.err.println("Accept failed.");
	        System.exit(1);
	    }
	    
	    final DataOutputStream out = new DataOutputStream(clientSocket.getOutputStream());
	    final DataInputStream in = new DataInputStream(clientSocket.getInputStream());
	    str = MESSAGE_SIZE + str;
	    message = str.getBytes();
	    byte[] b = new byte[1600];
	    int ret = 0;
	    for (int i = 0; i < 3; ++i) {
	    	int loop = in.read() - 48;
	    	for (int j = 0; j < loop; ++j) {
	    		ret = in.read();
	    		System.out.print((char)ret);
	    	}
	    	System.out.println();
	    	out.write(message); 
	    }
	    
	    out.close();
	    in.close();
	    serverSocket.close();
	}
}