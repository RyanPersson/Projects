/*******************************************************************************************************************************************************************************
 ** filename: ta.hpp
 ** Author: Ryan Persson
 ** Date Created: 3/12/2018
 ** Description: interface for ta class
*******************************************************************************************************************************************************************************/
#ifndef _TA_HPP
#define _TA_HPP

#include "mazeperson.hpp"
#include "template_functions.hpp"


class Ta : public Mazeperson {
	private:
	public:
		Ta();
		Ta(int,int);
		char get_move();
		 
};



#endif
