//Filename: PiFinder.java
//Author: Ryan Persson
//Created: 10/19/2017
//Just for fun

public class PiFinder
{
	public static void main (String [] args)
	{
		//terms to be used in the recursive series sum
		double zn, sn, an, sum;
		int n;

		sn=1; //s1 = side of a hexagon inscribed in the unit circle.
		an=3; //a1 = area of a 12-gon inscribed in the unit circle.
		n=1; //n = index of current term in series
		double test1=1, test2=2;
		while( (test2-test1)>11e-14) { //Keeps summing the series untill number of significant digits in float is filled.
			n++;
			sn = Math.sqrt( Math.pow((1 - Math.sqrt(1-(Math.pow(sn,2)/4))),2) + (Math.pow(sn,2)/4)); // Sn+1(Sn)

			zn = (1 - Math.sqrt(1-(Math.pow(sn,2)/4))); //Part of function an+1(sn,an) Split into 2 to simplyify somewhat.
			test1 = an; 
			an = (an + 3*((Math.pow(2,n-1))*zn*sn))// an+1(sn,an)
		}//end of iteration loop.

	System.out.println("The series ran for " + n + " terms.");
	System.out.println(an + " Is aproximately the value of pi, \n as determined by exhausting the unit circle with 3*2^24 right triangles.");

	}//Method main
}//Class Pifinder










































































