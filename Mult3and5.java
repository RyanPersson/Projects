// Filename: Mult3and5
// Author: Ryan Persson
// 1st Euler problem
// Created 10/24/2017

public class Mult3and5
{
   public static void main (String [] args)
   {
   
   int x=0, x1, n=0, n1, sum=0;
   
   while (5*x<1000)
      {
      x1=5*x;
      sum=sum+x1;
      System.out.println("Sum is " + sum);
      x++;
      }// End while loop
   System.out.println("Sum after all 5's is " + sum);
   
   while (3*n<1000)
      {
      
      if ((n%5==0))
         {
         n++;
         }// End if statement
      else
         {
         n1=3*n;
         sum=sum+n1;
         System.out.println("Sum is " + sum);
         n++;
         }// End else statement  
      }// End while statement
      System.out.println("Total sum is " + sum);
      
   String out="The sum of all multiples of 3 and 5 under 1000 is: " + sum;  
       
   System.out.println(out);
   }// method main
}//class Mult3&5
  