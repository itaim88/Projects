package il.co.ilrd.chat_client;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.BorderFactory;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.ListModel;

public class MainDetailPanel extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = -338415732415014061L;
	ClientDemo client;
	JTextArea textArea;
	
	MainDetailPanel(ClientDemo client) {
		Dimension size = getPreferredSize();
		size.width = 500;
		size.height = 700;
		setPreferredSize(size);
		this.client = client;

		setBorder(BorderFactory.createTitledBorder("Type your massege: "));
		JLabel groupNameLabel = new JLabel("Group name: ");
		
		
		textArea = new JTextArea();
		final JTextField groupField = new JTextField(15);
		final JTextField msgField = new JTextField(15);
		final JButton sendButton = new JButton("send");
		final JTextField newGroupField = new JTextField(15);
		final JButton newGroupButton = new JButton("new grp");
		final JButton leaveGroupButton = new JButton("leave grp");
		final JButton joinGroupButton = new JButton("join grp");
		JComboBox groups = new JComboBox(client.groups.toArray());
		
		groups.
		setLayout(null);
		
		textArea.setBounds(20, 200, 470, 450);
		add(textArea);
		
		groupNameLabel.setBounds(20, 30, 100, 30);
		add(groupNameLabel);
		
		groupField.setBounds(130, 30, 300, 25);
		add(groupField);

		newGroupButton.setBounds(70, 70, 100, 25);
		add(newGroupButton);
		
		leaveGroupButton.setBounds(200, 70, 100, 25);
		add(leaveGroupButton);
		
		joinGroupButton.setBounds(330, 70, 100, 25);
		add(joinGroupButton);
		
		msgField.setBounds(20, 120, 350, 30);
		add(msgField);
		
		sendButton.setBounds(380, 120, 100, 30);
		add(sendButton);
		
		sendButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {

				try {
					textArea.append(msgField.getText());
					client.sendMsg(client.clientId, newGroupField.getText(), msgField.getText());
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		
		joinGroupButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {

				try {
					client.createGroup(client.clientId, groupField.getText());
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		
		newGroupButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {

				try {
					client.createGroup(client.clientId, groupField.getText());
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		
		leaveGroupButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {

				try {
					client.leaveGroup(client.clientId, groupField.getText());
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
	}
}
