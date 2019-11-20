/*******************************************************************************************************************************************************************************
 ** Program: mazelevel.hpp
 ** Author: Ryan Persson
 ** Date Created: 3/12/2018
 ** Description: Creates a single level in the maze.
*******************************************************************************************************************************************************************************/
#ifndef _MAZELEVEL_HPP
#define _MAZELEVEL_HPP

#include "mazelocation.hpp"
#include "wall.hpp"
#include "openspace.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "mazeperson.hpp"
#include "intrepidstudent.hpp"
#include "ta.hpp"
#include "instructor.hpp"
#include <cstdlib>

class Mazelevel {
	protected:
		std::vector<std::vector<Mazelocation*> > locations;
		int width;
		int height;
		int programming_skills;
		int appeased;
		bool continue_level;
		std::vector<Mazeperson*> players;
		int instructorx, instructory;
		int startx, starty;
	public:
		Mazelevel(std::ifstream&, int, int);
		~Mazelevel();
		void set_types(char, int, int);
		Mazelocation * get_location(int, int);
		void display_maze();
		char get_display_char(int);
		void set_players();
		void end_level();
		void move(int, int, int);
		void get_moves();
		void set_programming_skills(int);
		bool get_continue();
		int get_programming_skills();
		void pick_up_skills();
		void iterate_appeased();
		void test_skills();
		void reset_level();
		int check_if_won();
};

#endif
