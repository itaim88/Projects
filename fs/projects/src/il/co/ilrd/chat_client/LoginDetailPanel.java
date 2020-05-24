package il.co.ilrd.chat_client;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class LoginDetailPanel extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = -7048977961845005738L;
	ClientDemo client;
	
	LoginDetailPanel(ClientDemo client) {
		this.client = client;
		Dimension size = getPreferredSize();
		size.width = 500;
		setPreferredSize(size);
		
		setBorder(BorderFactory.createTitledBorder("Login details"));
		
		JLabel nameLabel = new JLabel("Name: ");
		JLabel emailLabel = new JLabel("Email: ");
		
		final JTextField nameField = new JTextField(15);
		final JTextField emailField = new JTextField(15);
		
		JButton loginButton = new JButton("Login");
		
		loginButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String name = nameField.getText();
				String email = emailField.getText();
				
				try {
					client.login(email, name);
				} catch (IOException e1) {
					e1.printStackTrace();
				}
				
				JFrame frame = new MainFrame("ChatApp", client, nameField.getText());
				frame.setSize(500, 700);
				frame.setVisible(true);  
				frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			}
			
		});
		
		setLayout(null);
		
		// first column
		nameLabel.setBounds(10, 10, 80, 25);
		add(nameLabel);
		
		nameField.setBounds(100, 10, 160, 25);
		add(nameField);
		
		emailLabel.setBounds(10, 40, 80, 25);
		add(emailLabel);
		
		emailField.setBounds(100, 40, 160, 25);
		add(emailField);
		
		loginButton.setBounds(10, 80, 80, 25);
		add(loginButton);
	}
}
