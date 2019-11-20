/****************************************************************************************************************************************************************************** 
 ** Program FileName: template_functions.hpp
 ** Author: Ryan Persson
 ** Date Created: 1/31/2019
 ** Description: Interface for template_functions.cpp (Default user I/O functions to use in c++ projects.)
******************************************************************************************************************************************************************************/
#ifndef __TEMPLATE_FUNCTIONS_HPP
#define __TEMPLATE_FUNCTIONS_HPP



#include <iostream>
#include <string>
#include <cmath>
#include <sstream>


/* default user i/o functions: */
std::string get_string();
int get_int();
int get_int(int min);
int get_int(int min, int max);
int get_int(int choices[], int num_choices);
float get_float();
bool get_bool();
char get_char();
char get_char(char choices[], int num_choices);

#endif 
