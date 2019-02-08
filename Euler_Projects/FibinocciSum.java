// Filename FibinocciSum
// Author: Ryan Persson
// Project Euler, Problem 2
// Created: 10/24/2017

public class FibinocciSum
{
   public static void main (String [] args)
   {
   
   int sum=0, n=1, fn=0,zn;
   
   while (fn<4000000)
      {     
      zn=fn;
      
      fn=fn+n;
      
      n=zn;
      
      if (fn%2==0)
         {
         sum=sum+fn;
         }// End if statement
      
      }// End while loop
      
      System.out.println("fn is " + fn + ". Sum is " + sum);

      
   }// method main
}// class FibinocciSum