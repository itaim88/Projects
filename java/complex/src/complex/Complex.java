package complex;

import static java.lang.Math.pow; 

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Complex implements Comparable<Complex> {
	private double real, img;
	
	public Complex(){
		real = 0;
		img = 0;
	}
	
	public Complex(double real, double img) {
		this.real = real;
		this.img = img;
	}
	
	public Complex add(Complex c) {
		
		return new Complex(c.getReal() + real, c.getImg() + img);
	}
	
	public Complex subtract(Complex c) {

		return new Complex(real - c.getReal(), img - c.getImg());	
	}
	
	public Complex multiplyBy(Complex c) {
	
		return (new Complex((real * c.getReal()) - (img * c.getImg()),
						  (real * c.getImg()) + (img * c.getReal())));
	}
	
	public Complex divideBy(Complex c) {
	
		return new Complex(((real * c.getReal()) + (img * c.getImg())) / (pow(c.getReal(), 2) + pow(c.getImg(), 2)), 
							(((img * c.getReal()) - (real * c.getImg()))/ (pow(c.getReal(), 2) + pow(c.getImg(), 2))));
	}

	public double getReal() {
	
		return real;
	}

	public void setReal(double real) {
		this.real = real;
	}

	public double getImg() {
		return img;
	}

	public void setImg(double img) {
		this.img = img;
	}
	
	public void setValue(double real, double img) {
		this.real = real;
		this.img = img;
	} 
	
	public boolean isReal() {
		
		return (0 == img);
	}
	
	public boolean isImg() {
		return (0 == real);
	}
	
	public static Complex parse(String str) {
		Complex c = new Complex();
		
		int endOfReal = str.indexOf("+");
		int endOfImg = str.indexOf("i");
		
		String sreal = str.substring(0, endOfReal);
		String simg = str.substring(endOfReal + 1, endOfImg);

		c.setReal(Double.parseDouble(sreal));
		c.setImg(Double.parseDouble(simg));
		
		return c;
	}
	
	@Override
	public int compareTo(Complex complex) {
		int res = (int)(real - complex.getReal());
		
		if (0 == res)
		{
			 res = (int)(img - complex.getImg());	
		}
		
		return res;
	}
	
	@Override
	public String toString() {
		return "Complex [real=" + real + ", img=" + img + "i]";
	}
	
	@Override 
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		
		if (obj == null) {
			return false;
		}
		
		if (getClass() != obj.getClass()) {
			return false;
		}
		
		Complex other = (Complex) obj;
		
		return (img == other.getImg() && (real == other.getReal()));
	}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		long temp;
		
		temp = Double.doubleToLongBits(img);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		temp = Double.doubleToLongBits(real);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		
		return result;
	}
	

public static Complex regexParse(String c) {

      String numberNoWhiteSpace = c.replaceAll("\\s","");
      Complex comp = new Complex();

      // Matches complex number with BOTH real AND imaginary parts.  
      // Ex: -3-2.0i
      Pattern patternA = Pattern.compile("([-]?[0-9]+\\.?[0-9]?)([-|+]+[0-9]+\\.?[0-9]?)[i$]+");

      // Matches ONLY real number.
      // Ex: 3.145
      Pattern patternB = Pattern.compile("([-]?[0-9]+\\.?[0-9]?)$");

      // Matches ONLY imaginary number.
      // Ex: -10i
      Pattern patternC = Pattern.compile("([-]?[0-9]+\\.?[0-9]?)[i$]");

      Matcher matcherA = patternA.matcher(numberNoWhiteSpace);
      Matcher matcherB = patternB.matcher(numberNoWhiteSpace);
      Matcher matcherC = patternC.matcher(numberNoWhiteSpace);

      if (matcherA.find()) {
          comp.setReal(Double.parseDouble(matcherA.group(1)));
          comp.setImg(Double.parseDouble(matcherA.group(2)));
      } 
      
      else if (matcherB.find()) {
    	  comp.setReal(Double.parseDouble(matcherB.group(1)));
      } 
      
      else if (matcherC.find()) {
    	  comp.setImg(Double.parseDouble(matcherC.group(1)));
      }   
      
      return comp;
}	
}