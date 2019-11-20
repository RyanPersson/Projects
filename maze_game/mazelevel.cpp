/*******************************************************************************************************************************************************************************
 ** Program: mazelevel.cpp
 ** Author: Ryan Persson
 ** Date Created: 3/12/2018
 ** Description: implementaion of mazelevel objcet
 *******************************************************************************************************************************************************************************/
#include "mazelevel.hpp"
#include <cstdlib>
#include "mazeperson.hpp"
#include "intrepidstudent.hpp"
#include "ta.hpp"
#include "instructor.hpp"


#include "mazelocation.hpp"
#include "wall.hpp"
#include "openspace.hpp"
#include <fstream>
#include <vector>
#include <iostream>

/*******************************************************************************************************************************************************************************
 ** Function: mazelevel
 ** Description: constructor for mazelevel object
 ** Parameters: ifsteram& input, int nheight, int nwidth
 ** Preconditions: called in beginning of game by maze constructor
 ** Postconditions: mazelevel object created
*******************************************************************************************************************************************************************************/

Mazelevel::Mazelevel(std::ifstream& input, int nheight, int nwidth) : instructorx(-1), instructory(-1), continue_level(true), height(nheight), width(nwidth), appeased(0) {
	this->locations.resize(height);
	for(int j = 0; j < height; j++) {
		this->locations[j].resize(width);
	}
	char c;
	for(int i = 0; i < height; i++) {
		input.get(c);//gets rid of leading "\n"
		for(int j = 0; j < width; j++) {
			input.get(c);
			this->set_types(c,i,j);
		}
	}
	this->set_players();
}

/*******************************************************************************************************************************************************************************
 ** Function: destructor for mazelevel object
 ** Description: deletes dynamic memory in mazelevel
 ** Parameters: none
 ** Preconditions: called at end of game
 ** Postconditions: dynamic memory cleared
*******************************************************************************************************************************************************************************/

Mazelevel::~Mazelevel() {
	for(int i = 0 ; i < this->height; i++) {
		for(int j = 0; j < this->width; j++) {
			delete this->locations[i][j];
		}
	}
	for(int i = 0; i < 4; i++) {
		delete this->players[i];
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: get_continue
 ** Description: returns continue_level bool
 ** Parameters: none
 ** Preconditions: called to check if level should continue
 ** Postconditions: returns bool
*******************************************************************************************************************************************************************************/

bool Mazelevel::get_continue() {
	return this->continue_level;
}

/*******************************************************************************************************************************************************************************
 ** Function: set_types
 ** Description: called in mazelevel constructor loop. takes in char and creates new mazelocation object depending on what char is
 ** Parameters: char this_char, int height, int width
 ** Preconditions: called in mazelevel constructor
 ** Postconditions: new mazelocation created
*******************************************************************************************************************************************************************************/

void Mazelevel::set_types(char this_char, int height, int width) {
	if(this_char == '#') {
		this->locations[height][width] = new Wall();
	}
	if(this_char == ' '){
		this->locations[height][width] = new Openspace();
	}
	if(this_char == '@'){
		this->locations[height][width] = new Openspace();
		this->startx = width;
		this->starty = height;
		this->locations[height][width]->set_is_start(true);
		this->locations[height][width]->set_has_explorer(true);
	}
	if(this_char == '^'){
		this->locations[height][width] = new Openspace();	
		this->locations[height][width]->set_is_end(true);
	}
	if(this_char == '%'){ 
		this->locations[height][width] = new Openspace();
		this->instructorx = width;
		this->instructory = height;
		this->locations[height][width]->set_has_instructor(true);
		this->locations[height][width]->set_is_end(true);
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: get_location
 ** Description: returns mazelocation object
 ** Parameters: int height int width
 ** Preconditions: mazelocation needed
 ** Postconditions: mazelocation pointer returned 
*******************************************************************************************************************************************************************************/

Mazelocation * Mazelevel::get_location(int height, int width) {
	return this->locations[height][width];
}

/*******************************************************************************************************************************************************************************
 ** Function: display_maze()
 ** Description: prints maze to screen
 ** Parameters: none
 ** Preconditions: called once per loop 
 ** Postconditions: maze printed to cout
*******************************************************************************************************************************************************************************/

void Mazelevel::display_maze() {
//	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	if(this->appeased !=0)
		std::cout << "TA's appeased for " << this->appeased << " more rounds. " << std::endl;
	std::cout << "Programming skills: " << this->programming_skills << std::endl;
	for(int i = this->height-1; i >= 0; i--) {
		for(int j = 0; j < this->width; j++) {
			std::cout << this->locations[i][j]->get_display_character();
		}
		std::cout << "\n";
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: test_skills()
 ** Description: checks if player is by a TA and if not appeased, resets level
 ** Parameters: none
 ** Preconditions: checked once per game loop
 ** Postconditions: if player has not appeased tas, restes level
*******************************************************************************************************************************************************************************/

void Mazelevel::test_skills() {
	int prow = this->players[0]->get_row();
	int pcol = this->players[0]->get_col();
	int TArow;
	int TAcol;

	for(int i = 1; i < 3; i++) {
		TArow = this->players[i]->get_row();
		TAcol = this->players[i]->get_col();
		if(prow - TArow <= 1 && prow-TArow >= -1 && pcol - TAcol <= 1 && pcol-TAcol >= -1&&this->appeased==0) {
			std::cout << "You have been caught by a TA & did not demonstrate any skills..." << std::endl;
			this->reset_level();			
			std::cout << "enter any char to continue." << std::endl;
			char next = get_char();
			return;
		}
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: check_if_won()
 ** Description:  checks if player is range of instructor and has sufficient collected skills
 ** Parameters: none
 ** Preconditions: called once per loop
 ** Postconditions: if player is by instructor, either ends or resets game.
*******************************************************************************************************************************************************************************/

int Mazelevel::check_if_won() {
	int prow = this->players[0]->get_row();
	int pcol = this->players[0]->get_col();
	int INrow;
	int INcol;
	if(this->players[3]==nullptr)
		return 0;
	INrow = this->players[3]->get_row();
	INcol = this->players[3]->get_col();
	if(prow - INrow <= 1 && prow-INrow >= -1 && pcol - INcol <= 1 && pcol-INcol >= -1) {
		std::cout << "YOU APPROUCH THE INSTRUCTOR" << "\n";
		if(this->programming_skills >= 3) {
			std::cout << "You have passed CS 162!" << std::endl;
			this->continue_level = false;
			return 1;
		}
		else{
			std::cout << "You have NOT passed CS 162! " << std::endl;
			this->continue_level = false;
			std::cout << "enter any char to continue" << std::endl;
			char newc = get_char();
			return -1;
		}
	}
	return 0; //If not at end
}

/*******************************************************************************************************************************************************************************
 ** Function: reset_level()
 ** Description: resets level by deleting and respawning sprites and mazeperson objects
 ** Parameters: none
 ** Preconditions: called when TA catches player or when demonstrating skills to instructor fails
 ** Postconditions: level reset
*******************************************************************************************************************************************************************************/

void Mazelevel::reset_level() {
	std::cout << "Level is being reset: *******************************************************************************" << std::endl;
	this->programming_skills = 0;
	for(int i = 0; i < 4; i++) {
		delete this->players[i];
	}
	for(int i = 0; i < this->height; i++) {
		for(int j = 0; j < this->width; j++) {
			this->locations[i][j]->clear();
		}
	}
	this->set_players();
	this->continue_level = true;
	this->display_maze();
}

/*******************************************************************************************************************************************************************************
 ** Function: set_players()
 ** Description: calls all player constructors and randomly (Or in specific locations) spawns them
 ** Parameters: none
 ** Preconditions: called after levels are constructed
 ** Postconditions: mazelevels populated with players
*******************************************************************************************************************************************************************************/

void Mazelevel::set_players() {
	this->players.resize(4);
	this->players[0] = new Intrepidstudent(this->starty, this->startx);
	for(int i = 0; i < 2; i++) {
		int choicex,choicey;
		while(true) {
			choicex = std::rand() % this->width;
			choicey = std::rand() % this->height;
			if(this->locations[choicey][choicex]->is_empty()&&this->locations[choicey][choicex]->is_occupiable())
				break;
		}
		this->players[i+1] = new Ta(choicey,choicex);
		this->players[i+1]->set_location(choicey,choicex);
		this->locations[choicey][choicex]->set_has_ta(true);
	}
	this->players[3] = nullptr;
	if(this->instructorx!=-1) {
		this->players[3] = new Instructor(this->instructory,this->instructorx);
	}
	for(int i = 0; i < 3; i++) {
		int choicex,choicey;
		while(true) {
			choicex = std::rand() % this->width;
			choicey = std::rand() % this->height;
			if(this->locations[choicey][choicex]->is_empty()&&this->locations[choicey][choicex]->is_occupiable())
				break;
		}
		this->locations[choicey][choicex]->set_has_skill(true);
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: get_programming_skills
 ** Description: returns current programming skills
 ** Parameters: none
 ** Preconditions: called when moving to next level
 ** Postconditions: programming skills returned 
*******************************************************************************************************************************************************************************/

int Mazelevel::get_programming_skills() {
	return this->programming_skills;
}

/*******************************************************************************************************************************************************************************
 ** Function: iterate_appeased()
 ** Description: iterates appeased
 ** Parameters: none
 ** Preconditions: called once per loop
 ** Postconditions: appeased iterated
*******************************************************************************************************************************************************************************/

void Mazelevel::iterate_appeased() {
	if(this->appeased!=0)
		this->appeased--;
}

/*******************************************************************************************************************************************************************************
 ** Function: pick_up_skills()
 ** Description: picks up skill if player is on
 ** Parameters: none
 ** Preconditions: called once per loop
 ** Postconditions: skills picked up
*******************************************************************************************************************************************************************************/

void Mazelevel::pick_up_skills() {
	int rowa = this->players[0]->get_row();
	int cola = this->players[0]->get_col();
	if(this->locations[rowa][cola]->get_has_skill()){
		this->programming_skills++;
		this->locations[rowa][cola]->set_has_skill(false);
		std::cout << "You picked up a programming skill!" << std::endl;
	}
}

/*******************************************************************************************************************************************************************************
 ** Function: get_moves
 ** Description: moves all players
 ** Parameters: none
 ** Preconditions: called once per loop
 ** Postconditions: all movable players moved
*******************************************************************************************************************************************************************************/

void Mazelevel::get_moves() {
	char move;
	int row,col;
	for(int i = 0; i < 3; i++) {
		while(true) {
			row = this->players[i]->get_row();
			col = this->players[i]->get_col();
			move = this->players[i]->get_move();
			if(move== 'P') {
				if(this->programming_skills==0)
					std::cout << "You are out of programming skills. Please choose another move." << std::endl;
				else{
					this->programming_skills--;
					this->appeased = 10;
					break;
				}
			}
			if(move=='U'){
				if(this->locations[row][col]->get_is_end()){
					this->end_level();
					return;
				}
				else
					std::cout << "You are not at the end of the level. Please choose another move." << std::endl;
			}
			if(move=='W' || move=='w' || move=='A'||move=='a'||move=='S'||move=='s'||move=='D'||move=='d'){

				if(move=='W'||move=='w')
					row++;
				if(move=='A'||move=='a')
					col--;
				if(move=='S'||move=='s')
					row--;
				if(move=='D'||move=='d')
					col++;
				if(this->locations[row][col]->is_occupiable()){//fflow of control broken here
					break;
				}
				if(i==0)
					std::cout << " you cannot move there, Please choose another direction." << std::endl;
			}
		}//End while loop
		if(move!='P' && move!= 'U')
			this->move(i,row,col);
	}//End for loop
}

/*******************************************************************************************************************************************************************************
 ** Function: move
 ** Description:  moves the player to the new location
 ** Parameters: int player int row int col
 ** Preconditions: called everytime a player is moved
 ** Postconditions: player moved
*******************************************************************************************************************************************************************************/

void Mazelevel::move(int player, int row, int col) {
	int oldcol,oldrow;
	oldcol = this->players[player]->get_col();
	oldrow = this->players[player]->get_row();
	if(player==0){
		this->locations[oldrow][oldcol]->set_has_explorer(false);
		this->locations[row][col]->set_has_explorer(true);
	}
	if(player!=0){
		this->locations[oldrow][oldcol]->set_has_ta(false);
		this->locations[row][col]->set_has_ta(true);
	}
	this->players[player]->set_location(row,col);
}

/*******************************************************************************************************************************************************************************
 ** Function: end_level
 ** Description: changes continue level bool
 ** Parameters: none
 ** Preconditions: called by moving up
 ** Postconditions: level not ran again in loop
*******************************************************************************************************************************************************************************/

void Mazelevel::end_level() {
	this->continue_level = false;
	return;
}

/*******************************************************************************************************************************************************************************
 ** Function: se_programming_skills 
 ** Description: sets programming skills
 ** Parameters: int amount
 ** Preconditions: resets prpgromming skills once per l00p
 ** Postconditions: programming skills changed
*******************************************************************************************************************************************************************************/

void Mazelevel::set_programming_skills(int amount) {
	this->programming_skills = amount;
}
