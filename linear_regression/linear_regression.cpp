/****************************************************************************************************************************************************************************** 
 ** Program FileName: linear_regression.cpp
 ** Author: Ryan Persson
 ** Date Created: 11/11/2018
 ** Description: Performs linear regression on a randomly generated data set
******************************************************************************************************************************************************************************/
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include <vector>


/* Function declarations: */


std::vector<float> lin_reg(std::vector<float> *, std::vector<float> *, int num); 
std::vector<float>  mult(std::vector<float> *,std::vector<float> *, int num);
std::vector<float> square(std::vector<float> *, int num);
float square(float);
float sum(std::vector<float> *, int num);


/*******************************************************************************************************************************************************************************
 ** Function: lin_reg
 ** Description: Takes in 2 dimensional information & performs linear regression on it.
 ** Parameters: Vector<floats xs, vector<floats> ys, int num (length of both vectors)
 ** Preconditions: 2 vectors of equal size containing float data pairs and an int representing their size
 ** Postconditions: a vector of 3 floats. 1st is the slope, 2nd is b or y_shift and 3rd is R^2
*******************************************************************************************************************************************************************************/



std::vector<float> lin_reg(std::vector<float> * xs, std::vector<float> * ys, int num) {
		
	std::vector<float> x(num),y(num),xy(num),x_2(num),y_2(num);

	
	for(int i = 0; i < num; i++) {
		x[i] = (*xs)[i];
		y[i] = (*ys)[i];
	}

	xy = mult(&x,&y,num);
	
	x_2 = square(&x,num);
       	y_2 = square(&y,num);


	float sum_x = sum(&x,num);
	float sum_y = sum(&y,num);
	float sum_x_2 = sum(&x_2,num);
	float sum_xy = sum(&xy,num);

	/* Below code is:
	 *
	 *             	(sum_y * sum_x_2) - (sum_x * sum_xy)
	 *  y_shift =    _______________________________________
	 *	 	 num(sum_x_2) - (sum_x)^2
	 *
	 *			num(sum_xy) - (sum_x * sum_y)	
	 *  slope        =   ______________________________
	 *  		       num(sum_x_2) - (sum_x)^2
	 *
	 */   //had to invert these two operations, unsure why?

	float denom = num*sum_x_2 - square(sum_x);
	float y_shift = ((sum_y * sum_x_2)-(sum_x*sum_xy))/denom;
	float slope = (num*sum_xy - sum_x*sum_y)/denom;
	
	
	std::vector<float> output(3);
	output[0] = slope;
	output[1] = y_shift;
	output[2] = 0;//Do r squared later

	return output;
}


/*******************************************************************************************************************************************************************************
 ** Function: mult
 ** Description: multiplies all elements of 2 equally sized vectors together & returns a new vector containing these elements.
 ** Parameters: vector<float> x, vector<float> 7, int num (The length of x & y)
 ** Preconditions: 2 vector pointers of equal size & the int representing their size
 ** Postconditions: a vector of equal size containing x & y's elements multiplied together.
*******************************************************************************************************************************************************************************/

std::vector<float>  mult(std::vector<float> * x, std::vector<float> * y, int num) {
	std::vector<float> xy(num);
	for(int i = 0;i < num; i++) {
		xy[i] = (*x)[i] * (*y)[i];
	}
	return xy;
}

/*******************************************************************************************************************************************************************************
 ** Function: square
 ** Description: Squares all elements of a vector, returns a new vector containing the squared elements.
 ** Parameters: vector<float> in, & int num (size of in)
 ** Preconditions: A valid input vector & int equal to it's size.
 ** Postconditions: a vector containing the squared values of in.
*******************************************************************************************************************************************************************************/

std::vector<float>  square(std::vector<float> * in, int num) {
	std::vector<float> in_2(num);
	for(int i =0; i < num; i++) {
		in_2[i] = pow((*in)[i],2);
	}
	return in_2;
}

/*******************************************************************************************************************************************************************************
 ** Function: square
 ** Description: takes in a float & squares it. (wasn't really nescessary)
 ** Parameters: float in
 ** Preconditions: valid input float
 ** Postconditions: in squared
*******************************************************************************************************************************************************************************/

float square(float in) {
	return pow(in,2);
}

/*******************************************************************************************************************************************************************************
 ** Function: sum
 ** Description: Takes in a vector & sums its elements.
 ** Parameters: vector<float> in & int num (length of in)
 ** Preconditions: valid input vector of floats & int equal to its size
 ** Postconditions: float sum equal to the sum of in's elements.
*******************************************************************************************************************************************************************************/

float sum(std::vector<float> * in, int num) {
	float sum = 0;
	for(int i = 0;i<num;i++) {
		sum = (*in)[i] + sum;
	}
	return sum;
}


