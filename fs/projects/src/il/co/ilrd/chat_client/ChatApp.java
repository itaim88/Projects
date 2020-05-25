package il.co.ilrd.chat_client;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class ChatApp {
	public ChatApp(String titel) {
		
		ClientDemo client = new ClientDemo("localhost", 55555);
		
		SwingUtilities.invokeLater(new Runnable() {
		
			public void run() {
				JFrame frame = new LoginFrame("Login to ChatApp", client);
				frame.setSize(300, 150);
				frame.setVisible(true);  
				frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			}	
		});	
	}
	
	public static void main(String[] args) {
		ChatApp c = new ChatApp("Login");
	}
}
