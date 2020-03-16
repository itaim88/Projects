package singelton;

//Enum singleton//
	enum Animals {
		DOG(1),
		CAT(2),
		TIGER(3);
		
	    private int animalType;
		 
	    private Animals(int animalType) {
	        this.animalType = animalType;
	    }
	 
	    @Override
	    public String toString() {
	        return String.valueOf(this.animalType);
	    }
	}
	
	public class EnumSingleton {
	    public static void main(String[] args) {
	        Animals max = Animals.DOG;
	        Animals max2 = Animals.DOG;
	 
	        System.out.println(max == max2); // return true
	    }
	}
	


