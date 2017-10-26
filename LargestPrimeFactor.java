// FileName: LargestPrimeFactor
// Author: Ryan Persson
// Euler Problem 3
// 10/24/2017

import java.util.Scanner;

public class LargestPrimeFactor
{
   public static void main (String [] args)
   {
   

   Scanner scan=new Scanner(System.in);
   long n=2L;
   long num= scan.nextLong();
   String primeFactors=new String ("The prime factors of " + num + " are: ");
      
   while (n<num)
      {   
     if (num % n != 0)
         {
         n=n+1;          
         }// End if statement
     else
         {
         num=num/n;
         primeFactors=primeFactors + "\n" + n;        
         }// end else statement
        
      }// End while statement
               
   if (n==num)
      {
      primeFactors=primeFactors + " \n" + num;
      }// end if statement
      
      System.out.println(primeFactors);
   }// method main
}// Class LargestPrimeFactor   