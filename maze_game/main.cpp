/****************************************************************************************************************************************************************************** 
 ** Program FileName: main.cpp
 ** Author: Ryan Persson
 ** Date Created: 3/13/2018
 ** Description: Main file for Escape from CS 162 game
******************************************************************************************************************************************************************************/


#include "mazelocation.hpp"
#include "wall.hpp"
#include "openspace.hpp"
#include "mazelocation.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "maze.hpp"
#include <cstdlib>
#include "mazeperson.hpp"
#include "intrepidstudent.hpp"
#include "ta.hpp"
#include "instructor.hpp"


int main(int argc, char* argv[]) {
//	std::ios_base::sync_with_stdio(false);
	std::ifstream input;
	input.open(argv[1]);
	if(input.fail()) {
		std::cout << "Program was unable to open .txt file. Please specify a valid .txt file as the 2nd command line argument to pull the maze data from." << std::endl;
	return 0;
	}
	srand(time(0));
	Maze newgame(input);	
	newgame.display_mazes();	
	newgame.run_game();



	return 0;
}


