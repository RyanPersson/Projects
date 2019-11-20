/*******************************************************************************************************************************************************************************
 ** Program: maze.cpp 
 ** Author: Ryan Persson
 ** Date Created: 3/17/2018
 ** Description: Interface for maze class
*******************************************************************************************************************************************************************************/
#ifndef _MAZE_HPP
#define _MAZE_HPP

#include <fstream>
#include "mazelevel.hpp"
#include <vector>
#include <iostream>

class Maze {
	private:
		std::vector<Mazelevel*> levels;
		int height, width, num_levels;
	public:
		Maze(std::ifstream&);
		~Maze();
		void display_mazes();
		void run_game();
		int run_loop(int);
		bool replay(int);

};

#endif
