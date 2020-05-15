package il.co.ilrd.PingPong;

import java.net.*;
import java.util.Date;
import java.io.*;

public class UDPPingClient {
	private static final int MAX_TIMEOUT = 1000;	// milliseconds
	
	public static void main(String[] args) throws Exception {
		int MESSAGE_SIZE = 4;
	// Port number to access
			int port = 44444;
			// Server to Ping (has to have the PingServer running)
			InetAddress server = InetAddress.getByName("localhost");

			// Create a datagram socket for sending and receiving UDP packets
			// through the port specified on the command line.
			DatagramSocket socket = new DatagramSocket(port);

			int sequence_number = 0;
			// Processing loop.
			while (sequence_number < 10) {
				// Timestamp in ms when we send it
				Date now = new Date();
				long msSend = now.getTime();
				// Create string to send, and transfer i to a Byte Array
				String str = "PING " + sequence_number + " " + msSend;
				byte[] buf = new byte[1024];
				buf = str.getBytes();
				// Create a datagram packet to send as an UDP packet.
				DatagramPacket ping = new DatagramPacket(buf, MESSAGE_SIZE, server, 55555);

				// Send the Ping datagram to the specified server
				socket.send(ping);
				// Try to receive the packet - but it can fail (timeout)
				try {
					// Set up the timeout 1000 ms = 1 sec
					socket.setSoTimeout(MAX_TIMEOUT);
					// Set up an UPD packet for recieving
					DatagramPacket response = new DatagramPacket(new byte[1024], 1024);
					// Try to receive the response from the ping
					socket.receive(response);
					// If the response is received, the code will continue here, otherwise it will continue in the catch
					
					// timestamp for when we received the packet
					now = new Date();
					long msReceived = now.getTime();
					// Print the packet and the delay
					printData(response, msReceived - msSend);
				} catch (IOException e) {
					// Print which packet has timed out
					System.out.println("Timeout for packet " + sequence_number);
				}
				// next packet
				sequence_number ++;
			}
		}

	   /* 
	    * Print ping data to the standard output stream.
	    * slightly changed from PingServer
	    */
	   private static void printData(DatagramPacket request, long delayTime) throws Exception
	   {
	      // Obtain references to the packet's array of bytes.
	      byte[] buf = request.getData();

	      // Wrap the bytes in a byte array input stream,
	      // so that you can read the data as a stream of bytes.
	      ByteArrayInputStream bais = new ByteArrayInputStream(buf);

	      // Wrap the byte array output stream in an input stream reader,
	      // so you can read the data as a stream of characters.
	      InputStreamReader isr = new InputStreamReader(bais);

	      // Wrap the input stream reader in a bufferred reader,
	      // so you can read the character data a line at a time.
	      // (A line is a sequence of chars terminated by any combination of \r and \n.) 
	      BufferedReader br = new BufferedReader(isr);

	      // The message data is contained in a single line, so read this line.
	      String line = br.readLine();

	      // Print host address and data received from it.
	      System.out.println(
	         "Received from " + 
	         request.getAddress().getHostAddress() + 
	         ": " +
	         new String(line) + " Delay: " + delayTime );
	   }
}
