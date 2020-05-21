package il.co.ilrd.chat_server;

public interface Communication {
	/**
	 * takes the stream and parses it to the right data.
	 * @return Integer that tells the server which method it should execute. 
	 */
	public void Init();
	
	
}
