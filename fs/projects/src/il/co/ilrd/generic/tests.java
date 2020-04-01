package il.co.ilrd.generic;

public class tests {
	
	public static <T> void printArray(T[] t){
		for (T i : t) {
			System.out.println(i);
        }
    }
	public static void main(String[] args) {
		
        Integer[] intArray = {1,2,3};
        printArray(intArray);
        
        Character[] charArray = {'a','b','b'};
        printArray(charArray);
        
        
        Integer b = 47;
        Generic<Integer> foo = new Generic<>(b);   
        System.out.println(foo.getT()); 
        
        String s = "hello";
        Generic<String> foo1 = new Generic<>(s); 
        System.out.println(foo1.getT()); 
        
        
        System.out.println(foo.getT().getClass());
        System.out.println(foo1.getT().getClass());
        
    }

}
