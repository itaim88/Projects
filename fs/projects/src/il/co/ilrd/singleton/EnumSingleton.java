package il.co.ilrd.singleton;

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
	        
	        for (int i = 0; i < 100_000; ++i) {
	        	Animals max2 = Animals.DOG;
	        	if (max != max2) {
					System.out.println("Not singleton");
					return;
				}
			}
	        
			System.out.println("singleton");	 
	    }
	}
	


