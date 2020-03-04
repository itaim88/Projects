import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Arraylist { 

    public static void main(String[] args) 
    { 
      int num_of_ints = 100000; 
      int num_of_arrays = 1000;

     	Runtime run = Runtime.getRuntime();  
 	
		ArrayList<int[]> list = new ArrayList<int[]>();

		while(true)
		{
	 		for(int i = 0; i < num_of_arrays; ++i)
	 		{
	 			//list.add(new int[num_of_ints]);

	 			System.out.println("Free Memory: " +run.freeMemory()); 
	  			System.out.println("Total Memory: " +run.totalMemory());
	        }
    	}

   }
}