package il.co.ilrd.ws3;


public class shape {

		String color;
		boolean filled;
		
		public shape () {
			
			color = "Green";
			filled = true;
		
		}
		
		public shape (String color, boolean filled) {
			
			this.color = color;
			this.filled = filled;
		}
		
		public String getcolor() {
			
			return color;
		}
		
		public String getfilled() {
			
			if (filled)
			{
				return "filled";
			}
			
			return "not filled";
		}
		
		public String toString() {
			 
			return (getcolor()+" "+getfilled());
		}
}
