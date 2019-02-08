#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

/*default user i/o functions: */
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

