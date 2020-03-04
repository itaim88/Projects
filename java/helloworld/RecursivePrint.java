class PrintNum {
    public static void main(String[] args) {

    	RecursivePrint(100);   	
	}

	public static void RecursivePrint(int num) {

		if (0 == num)
		{
			return;
		}

     	System.out.println(num); 
     	RecursivePrint(--num);	
    }
}