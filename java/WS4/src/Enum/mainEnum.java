package Enum;

public class mainEnum {

	public EWeekDay fromValue(int day){
		EWeekDay[] days = EWeekDay.values();
		return days[day - 1];
	}
	
	public static void main(String[] args) {	
		EWeekDay[] days = EWeekDay.values();
		
		for(EWeekDay aDay : days) {
			System.out.println(aDay);
		}
		
		mainEnum m = new mainEnum();
		System.out.println(m.fromValue(7) + " is the day");
		
		EWeekDay day1 = EWeekDay.valueOf("MONDAY");
	
		System.out.println(day1.getDay());
		
		System.out.println(day1.SUNDAY.game());
		System.out.println(day1.MONDAY.game());
		System.out.println(day1.TUESDAY.game());	
	}	
}
