/*******************************************************************************************************************************************************************************
 ** Program: wall.hpp
 ** Author: RYan Persson 
 ** Date Created: 3/12/2018
 ** Description: interface for wall object
*******************************************************************************************************************************************************************************/

#ifndef _WALL_HPP
#define _WALL_HPP

#include "mazelocation.hpp"

class Wall : public Mazelocation {

	public:
		Wall();
		bool is_occupiable();
		char get_display_character();
};
#endif
