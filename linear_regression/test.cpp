/****************************************************************************************************************************************************************************** 
 ** Program FileName: test.cpp
 ** Author: Ryan Persson
 ** Date Created: 11/12/2018
 ** Purpose/Description: to test linear_regression & dependecies / headers.
 ** Input:
 ** Output:
******************************************************************************************************************************************************************************/

#include "functions.hpp"
#include "linear_regression.hpp"
#include "matplotlibcpp.h"


#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

namespace plt = matplotlibcpp;


/* Intitialize functions here: */
/* Main function */

int main () {

	//input data
	/*The following just declares test data. */
	srand(time(0));
	std::cout << "Please enter the slope for the random numbers. " << std::endl;
	int slopein = get_int();
	std::cout << "Please enter the number of data points " << std::endl;	
	int num = get_int(); 
	std::vector<float>  xs(num),ys(num);
	
	for(int i = 0; i < num; i++) {
		xs[i] = (i);
		ys[i] = (slopein*(i)+(rand()%(slopein*num/3 + i/5)));
	}
	// int num = ; from user
	
	std::vector<float> values = lin_reg(&xs, &ys, num);

	float slope = values[0];
	float y_shift = values[1];

	std::cout << "The equation for the line of best fit is: " << slope << "x + " << y_shift << " \n The R^2 value is: " << std::endl; 
	

	std::vector<float> line_fit(num),x(num);
	
	for(int i=0; i < num; i++) {
		line_fit[i] = (slope * i) + y_shift;
		x[i] = i;
	}	

	plt::plot(x,line_fit,"r-");
	plt::plot(xs,ys,"s");

	plt::title("Linear Regression Attempt");
	plt::show();

	return 0;
}
/* Define functions down here: */

//Empty default function header:


/*******************************************************************************************************************************************************************************
 ** Function:
 ** Description:
 ** Parameters:
 ** Preconditions:
 ** Postconditions:
*******************************************************************************************************************************************************************************/

