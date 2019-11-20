/*******************************************************************************************************************************************************************************
 ** filename: instructor.hpp
 ** Author: Ryan Persson
 ** Date Created: 3/12/2018
 ** Description: interface for instructor class
*******************************************************************************************************************************************************************************/
#ifndef _INSTRUCTOR_HPP
#define _INSTRUCTOR_HPP

#include "mazeperson.hpp"
#include "template_functions.hpp"


class Instructor : public Mazeperson {
	private:
	public:
		Instructor();
		Instructor(int,int);
		char get_move();
		 
};



#endif
