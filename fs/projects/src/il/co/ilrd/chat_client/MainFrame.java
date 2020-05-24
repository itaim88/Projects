package il.co.ilrd.chat_client;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.util.concurrent.BrokenBarrierException;

import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.ListModel;
import javax.swing.SwingUtilities;


public class MainFrame extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = -582593631733082271L;
	MainDetailPanel panel;
	ClientDemo client;
	
	public MainFrame(String title, ClientDemo client, String name) {
		super(title);
		this.client = client;
	
		// set layout manager
		setLayout(new BorderLayout());
		
		// Create swing component
		panel = new MainDetailPanel(client);
		panel.setBounds(0, 0, 100, 100);
		JTextArea textArea = new JTextArea("Hello" + name + "Welcome to ChatApp\n", 100, 100);
		
		
		// add swing components to content pane
		Container c = getContentPane();
		c.add(textArea, BorderLayout.CENTER);
		c.add(panel, BorderLayout.NORTH);
	}
	
	

	
}
	
