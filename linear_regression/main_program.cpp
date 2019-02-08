
#include "functions.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

int main () {
	


	while(true) {

		std::cout << "What would you like to do? enter 1 to input a float, 2 to input a string, 3 to input an int." << std::endl;
		int choices[3] = {1, 2, 3};
		int choice = get_int(1,3);
		if(choice == 1) {
			std::cout <<"Please enter a float" << std::endl;
			float float_output = get_float();
			std::cout << "you entered the float: " << float_output << std::endl;
		}
		else if(choice == 2) {
			std::cout << "Please enter a string " << std::endl;
			std::string str_input = get_string();
			std::cout << " You entered the string " << str_input << std::endl;
		}
		else if(choice == 3) {
			std::cout << "Please enter an int " << std::endl;
			int int_choice = get_int();
			std::cout << "You entered the int : " << int_choice << std::endl;
		}
		std::cout << "would you like to continue? " << std::endl;
		bool continue_running = get_bool();
		if(!continue_running)
			break;
	
	}
	return 0;
}
