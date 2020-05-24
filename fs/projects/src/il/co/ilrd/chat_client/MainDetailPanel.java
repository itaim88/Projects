package il.co.ilrd.chat_client;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.TextArea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.Arrays;
import java.util.Set;

import javax.swing.BorderFactory;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.ListSelectionModel;
import javax.swing.text.AttributeSet;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyleContext;

public class MainDetailPanel extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = -338415732415014061L;
	ClientDemo client;
	JTextArea textArea;
	JList<String> groups;
	DefaultListModel<String> demoList;
	
	MainDetailPanel(ClientDemo client) {
		Dimension size = getPreferredSize();
		size.width = 1000;
		size.height = 1000;
		setPreferredSize(size);
		this.client = client;
		client.panel = this;

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
					textArea.append(msgField.getText() + "\n");
					msgField.setText("");
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
					groupField.setText("");
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
					groupField.setText("");
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
					groupField.setText("");
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		
	}

	public void printToTextArea(String str, Color color) {
		textArea.setForeground(color);
	    textArea.append(str + "\n");
	}
	
	public void getGroups(Set<String> groupsList) {
		demoList = new DefaultListModel<>();

		for (String s : groupsList) {
			demoList.addElement(s);
		}
		
		groups = new JList<String>(demoList);
		
		
		groups.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		add(new JScrollPane(groups));
		groups.setVisible(true);
		groups.setBounds(600, 30, 150, 600);
		this.add(groups);

	}
	
	public void addGroup(String group) {
		demoList.addElement(group);
		groups = new JList<String>(demoList);
	}
	
	public void removeGroup(String group) {
		demoList.removeElement(group);
		groups = new JList<String>(demoList);
	}
}
