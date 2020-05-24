package homeTests;

public class test {
   int FindMaxSum(int arr[], int n) 
    { 
        int incl = arr[0]; 
        int excl = 0; 
        int excl_new; 
        int i; 
  
        for (i = 1; i < n; i++) 
        { 
            /* current max excluding i */
            excl_new = (incl > excl) ? incl : excl; 
  
            /* current max including i */
            incl = excl + arr[i]; 
            excl = excl_new; 
        } 
  
        /* return max of incl and excl */
        return ((incl > excl) ? incl : excl); 
    } 
  
    // Driver program to test above functions 
    public static void main(String[] args) 
    { 
        test sum = new test(); 
        int arr[] = new int[]{5, 2, 3, 6, 2, 1, 5, 8, 2, 4, 3, 3, 6, 1}; 
        System.out.println(sum.FindMaxSum(arr, arr.length)); 
    } 
} 
