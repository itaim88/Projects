package il.co.ilrd.chat_client;

public enum Status {
	SUCCESS(0),
	CLIENT_NOT_FOUND(1),
	GROUP_NOT_FOUND(2),
	NOT_IN_GROUP(3),
	ALREADY_IN_GROUP(4),
	GROUP_ALREADY_EXISTS(5);
	
	private int code;
	private Status(int code) {
		this.code = code;
	}
		public int getCode() {
		return this.code;
	}
}

