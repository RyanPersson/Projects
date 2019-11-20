/*******************************************************************************************************************************************************************************
 ** Program: maze.cpp 
 ** Author: Ryan Persson
 ** Date Created: 3/17/2018
 ** Description: implementation of maze class
*******************************************************************************************************************************************************************************/

#include "maze.hpp"
#include <fstream>
#include "mazelevel.hpp"
#include <vector>
#include <iostream>



/*******************************************************************************************************************************************************************************
 ** Function: Maz()
 ** Description: constructor for maze object
 ** Parameters: ifstream& input
 ** Preconditions: called from main
 ** Postconditions: maze object created
*******************************************************************************************************************************************************************************/

Maze::Maze(std::ifstream& input) {
	input >> this->num_levels >> this->height >> this->width;
	levels.resize(this->num_levels);
	for(int i = 0; i < num_levels; i++) {
		this->levels[i] = new Mazelevel(input, this->height, this->width);
	}
	std::cout << "Welcome to Escape from CS 162!\n\nRules:\nUse WASD or wasd to move\nU to go to the next level when on a '^' character\nP to use a programming skill (will set timer to 10 turns.)\nAdjacent means anything within 1 block, crosswise or diagonal\na '2' means two sprites are on the same space.\n\nEnter any char to continue.." << std::endl;
	char in = get_char();
}

/*******************************************************************************************************************************************************************************
 ** Function: ~Maze
 ** Description: destructor for maze objects
 ** Parameters: none
 ** Preconditions: called automatically at end of main
 ** Postconditions: deletes mazelevels and associated dynamic memory
*******************************************************************************************************************************************************************************/

Maze::~Maze() {
	for(int i = 0; i < this->num_levels; i++) {

		delete levels[i];
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: display maze
 ** Description: unused function, was used for testing early on
 ** Parameters: none
 ** Preconditions: none
 ** Postconditions: none
*******************************************************************************************************************************************************************************/

void Maze::display_mazes() {
}

/*******************************************************************************************************************************************************************************
 ** Function: run_game
 ** Description: runs entire game
 ** Parameters: none
 ** Preconditions: called from main
 ** Postconditions: game ran
*******************************************************************************************************************************************************************************/

void Maze::run_game() {
	int won = -1;
	do {
		int programming_skills = 0;
		for(int i = 0; i < this->num_levels; i++) {
			this->levels[i]->set_programming_skills(programming_skills);
			won = this->run_loop(i);
			programming_skills = this->levels[i]->get_programming_skills();
		}
	}while(this->replay(won));
	return;
}

/*******************************************************************************************************************************************************************************
 ** Function: replay
 ** Description: resets game if instructor fails student
 ** Parameters: int won
 ** Preconditions: called once per loop, depends on int won
 ** Postconditions: if int won = -1, resets whole game
*******************************************************************************************************************************************************************************/

bool Maze::replay(int won) {
	if(won == 0) 
		return false;
	if(won == 1) {
		return false;
	}
	if(won == -1) {
		for(int i = 0; i < this->num_levels; i++) {
			this->levels[i]->reset_level();
		}
		std::cout << "GAME restarted." << std::endl;
		return true;
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: run_loop()
 ** Description: runs loop for one round of maze game
 ** Parameters: int current
 ** Preconditions: called repeatedly by run maze
 ** Postconditions: one loop ran, data updated
*******************************************************************************************************************************************************************************/

int Maze::run_loop(int current) {
	int won;
	this->levels[current]->display_maze();
	while(this->levels[current]->get_continue()) {
		this->levels[current]->pick_up_skills();
		this->levels[current]->iterate_appeased();
		this->levels[current]->get_moves();	
		this->levels[current]->display_maze();
		this->levels[current]->test_skills();
		won = this->levels[current]->check_if_won();
	}
	return won;
}

/*******************************************************************************************************************************************************************************
 ** Function: 
 ** Description: 
 ** Parameters: 
 ** Preconditions: 
 ** Postconditions:
 *******************************************************************************************************************************************************************************/

