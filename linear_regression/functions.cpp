/****************************************************************************************************************************************************************************** 
 ** Program FileName: functions.cpp
 ** Author: Ryan Persson
 ** Date Created: 11/7/2018
 ** Description: Default user I/O & validation functions to be included with my CS 161 .cpp programs using a header
******************************************************************************************************************************************************************************/

/* I found that I was rewriting the same few I/O & validation functions for every CS 161 assignment.
 * So I created this file to hold a few default functions to use with my CS 161 projects.
 * The functions in this file can be included in other .cpp files by compiling them both & including this file's header "functions.h" .
 * They have been tested for all possible user input & should perform as specified. 
 * -Ryan Persson */

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>



/*******************************************************************************************************************************************************************************
 ** Function: get_string()
 ** Description: Gets a string from the user
 ** Parameters: none
 ** Preconditions: none
 ** Postconditions: returns a string
*******************************************************************************************************************************************************************************/
std::string get_string() {
	std::string output;
	std::cin.clear();
	std::cin.sync();
	std::getline(std::cin >> std::ws, output);
	return output;
}
/*******************************************************************************************************************************************************************************
 ** Function: get_int()
 ** Description: takes a string from a user, converts to an int, repeats if not valid int
 ** Parameters: none
 ** Preconditions: none
 ** Postconditions: Returns a valid integer.
*******************************************************************************************************************************************************************************/
int get_int() {
	
	while(true) {
		std::string input = get_string();
		int output;
		std::stringstream convert(input);
		if(convert >> output && !(convert >> input))
				return output;
		else
			std::cout << "\n" << input << " is not a valid integer. Please reenter a valid integer." << std::endl;
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: get_int(int min)
 ** Description: get_int overloaded to only return ints above a min value. Calls get_int() recursively & validates.
 ** Parameters: int min
 ** Preconditions: a valid input min
 ** Postconditions: returns a valid integer above min
*******************************************************************************************************************************************************************************/
int get_int(int min) {
	while(true) {
		int input;
		input = get_int();
		if(input < min) {
			std::cout << input << " is above the allowed min " << min << " Please enter an integer above " << min << std::endl;
		}
		else
			return input;
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: get_int(int min, int max)
 ** Description: get_int overloaded to only accept an integer between a min & max
 ** Parameters: int min & int max
 ** Preconditions: 2 valid integers that don't equal eachother.
 ** Postconditions: a valid int between min & max
*******************************************************************************************************************************************************************************/
int get_int(int min, int max) {
	while(true) {
		int input;
		input = get_int();
		if(input < min || input > max) {
			std::cout << input << " is not in the allowed range. Please enter an integer between " << min << " and " << max << std::endl;
		}
		else
			return input;
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: get_int(int choices[], num_choices)
 ** Description: overloads get_int() to get an integer in an allowed set of values which is input as an int array.
 ** Parameters: an array of integer choices, and an int representing the length of the array
 ** Preconditions: a valid, non_null input array & its size (must be accurate)
 ** Postconditions: a valid user chosen integer that matches a member of the input array.
*******************************************************************************************************************************************************************************/
int get_int(int choices[], int num_choices) {
	while(true) {
		int input;
		input = get_int();
		bool includes = false;
		for(int i = 0; i < num_choices; i++) {
			if(input == choices[i])
				includes = true;
		}
		if(includes)
			return input;
		else {
			std::cout << input << " is not an allowed input. Please input an integer in the set: {" ;
			for(int i = 0; i < num_choices; i++) {
				std::cout << choices[i] << " ";
			}
			std::cout << "}" << std::endl;
		}
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: get_float()
 ** Description: gets a valid float from the user
 ** Parameters: none
 ** Preconditions: none
 ** Postconditions: a valid float
*******************************************************************************************************************************************************************************/
float get_float() {
	while(true) {
		float output;
		std::string input = get_string();
		std::stringstream convert(input);

		if(convert >> output && !(convert >> input)) {
			return output;
		}
		else
			std::cout << input << " is not a valid float. Please enter a valid float. " << std::endl;
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: get_bool()
 ** Description: gets a boolean value from the user
 ** Parameters: none
 ** Preconditions: none
 ** Postconditions: a true or false bool input by the user
*******************************************************************************************************************************************************************************/
bool get_bool() {
	int choices[2] = {0,1};
	while(true) {
		std::cout << "Please enter 1 for yes or 0 for no. " << std::endl;
		int input = get_int(choices,2);
		if(input == 1)
			return true;
		else if(input == 0)
			return false;
	}
}
/*******************************************************************************************************************************************************************************
 ** Function: get_char()
 ** Description: Gets & validates a char from the user.
 ** Parameters: none
 ** Preconditions: none
 ** Postconditions: outputs a valid char
 ******************************************************************************************************************************************************************************/
char get_char() {
	while(true) {
		std::string output = get_string();
		if(output.length()==1&&(output.at(0) >= '!'&&output.at(0) <= '~'))
			return output.at(0);
		else {
			std::cout << output << " is not a valid char. Please enter a valid char. " << std::endl;
		}
	}
}
/*******************************************************************************************************************************************************************************
 ** Function: get_char(char choices[], int num_choices)
 ** Description: overloads get_char to only take a char from a set of choices
 ** Parameters: an array of allowed cars & the length of that array
 ** Preconditions: valid input array & int that equals the size of that array
 ** Postconditions: a valid char from the user
*******************************************************************************************************************************************************************************/
char get_char(char choices[], int num_choices) {
	while(true) {
		char input = get_char();
		bool includes = false;
		for(int i = 0; i < num_choices; i++) {
			if(input == choices[i])
				includes = true;
		}
		if(includes)
			return input;
		else{
			std::cout << input << " Is not an allowed char. Please input a char included in the set: { " ;
			for(int i = 0; i < num_choices; i++ )
				std::cout << choices[i] << " " ;
			std::cout << "}" << std::endl;
		}
	}
}
