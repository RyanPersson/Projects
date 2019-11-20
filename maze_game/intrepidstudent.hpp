/*******************************************************************************************************************************************************************************
 ** filename: intrepidstudent.hpp
 ** Author: Ryan Persson
 ** Date Created: 3/12/2018
 ** Description: interface for intrepidstudent class
*******************************************************************************************************************************************************************************/
#ifndef _INTREPIDSTUDENT_HPP
#define _INTREPIDSTUDENT_HPP

#include "mazeperson.hpp"
#include "template_functions.hpp"


class Intrepidstudent : public Mazeperson {
	private:
		int programming_skills;
			
	public:
		Intrepidstudent();
		Intrepidstudent(int,int);
		char get_move();
		int get_programming_skills();
		void set_programming_skills(int);
		 
};



#endif
