package il.co.ilrd.chat_client;

import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.JFrame;


public class LoginFrame extends JFrame {
	
	private static final long serialVersionUID = -582593631733082271L;
	LoginDetailPanel panel;
	ClientDemo client;
	
	public LoginFrame(String title, ClientDemo client) {
		super(title);
		this.client = client;
		
		// set layout manager
		setLayout(new BorderLayout());
		
		// Create swing component
		panel = new LoginDetailPanel(client);
		
		// add swing components to content pane
		Container c = getContentPane();
		
		c.add(panel, BorderLayout.WEST);
	}
	
}
