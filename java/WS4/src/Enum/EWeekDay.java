package Enum;

public enum EWeekDay {
	SUNDAY(1){
		@Override 
		public String game() {
			
			return SUNDAY.toString().toLowerCase();
		}
	},
	MONDAY(2){
		@Override
		public String game() {
			return MONDAY.toString().toLowerCase() + " hello";
		}
		
	},
	TUESDAY(3){
		@Override
		public String game() {
			return TUESDAY.toString().toLowerCase() +" "+ TUESDAY.toString().toUpperCase();
		}
	},
	WEDNESDAY(4){
		@Override
		public String game() {
			return WEDNESDAY.toString().toLowerCase();
		}
	},
	THURSDAY(5){
		@Override
		public String game() {
			return THURSDAY.toString().toLowerCase();
		}
	},
	FRIDAY(6){
		@Override
		public String game() {
			return FRIDAY.toString().toLowerCase();
		}
	},
	SATURDAY(7){
		@Override
		public String game() {
			return SATURDAY.toString().toLowerCase();
		}
	};
	
	private int dayValue;
	
	private EWeekDay (int dayValue){
		
		this.dayValue = dayValue;
	}
	
	public int getDay() {
		
		return dayValue;
	}
	
	public abstract String game();
	
}

	
	

	