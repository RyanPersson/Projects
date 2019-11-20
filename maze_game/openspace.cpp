/*******************************************************************************************************************************************************************************
 ** Program: openspace.cpp
 ** Author: Ryan Persson 
 ** Date Created: 3/12/2018
 ** Description: implementation of openspace object
 *******************************************************************************************************************************************************************************/
#include "openspace.hpp"
#include "mazelocation.hpp"
#include <iostream>

/*******************************************************************************************************************************************************************************
 ** Function: is_occupiable
 ** Description: returns true for openspace
 ** Parameters: none
 ** Preconditions: checking if space is occupiable
 ** Postconditions: true returned
*******************************************************************************************************************************************************************************/

bool Openspace::is_occupiable() {
	return true;
}

/*******************************************************************************************************************************************************************************
 ** Function: get_display_character()
 ** Description: gets display character depending on what bools are in openspace
 ** Parameters: none
 ** Preconditions: printing maze
 ** Postconditions: returns char depending on what's in openspace
*******************************************************************************************************************************************************************************/

char Openspace::get_display_character() {
	int count = 0;
	if(this->is_empty())
		return ' ';
	if(this->has_explorer)
		count++;
	if(this->is_start)
		count++;
	if(this->is_end)
		count++;
	if(this->has_ta)
		count++;
	if(this->has_skill)
		count++;
	if(count >=2)
		return '2';	
	if(this->is_instructor)
		return '%';
	if(this->is_start)
		return '@';
	if(this->is_end)
		return '^';
	if(this->has_explorer)
		return '*';
	if(this->has_ta)
		return 'T';
	if(this->has_skill)
		return '$';
}

/*******************************************************************************************************************************************************************************
 ** Function: set_has_explorer
 ** Description: setter
 ** Parameters: bool in
 ** Preconditions: need to chagne
 ** Postconditions: changed
*******************************************************************************************************************************************************************************/

void Openspace::set_has_explorer(bool in) {
	this->has_explorer = in;
}

/*******************************************************************************************************************************************************************************
 ** Function: det_has_explorer
 ** Description: getter
 ** Parameters: none
 ** Preconditions: need to get
 ** Postconditions: got
*******************************************************************************************************************************************************************************/

bool Openspace::get_has_explorer() {
	return this->has_explorer;
}

/*******************************************************************************************************************************************************************************
 ** Function: set_is_start
 ** Description: setter
 ** Parameters: bool in
 ** Preconditions: nneds to change
 ** Postconditions: changed
*******************************************************************************************************************************************************************************/

void Openspace::set_is_start(bool in) {
	this->is_start = in;
}

/*******************************************************************************************************************************************************************************
 ** Function: get_is_start
 ** Description: getter
 ** Parameters: none
 ** Preconditions: gets has start
 ** Postconditions: gets has start
*******************************************************************************************************************************************************************************/

bool Openspace::get_is_start() {
	return this->is_start;
}

/*******************************************************************************************************************************************************************************
 ** Function: set_has_instructor
 ** Description: setter
 ** Parameters: bool in
 ** Preconditions: instructor deleted
 ** Postconditions: instructor changed
*******************************************************************************************************************************************************************************/

void Openspace::set_has_instructor(bool in) {
	this->is_instructor = in;
}

/*******************************************************************************************************************************************************************************
 ** Function: get_has instructor
 ** Description: getter
 ** Parameters: none
 ** Preconditions: check if has instructor
 ** Postconditions: returns is_instructor
*******************************************************************************************************************************************************************************/

bool Openspace::get_has_instructor() {
	return this->is_instructor;
}

/*******************************************************************************************************************************************************************************
 ** Function: set_has_ta
 ** Description: sets has tao
 ** Parameters: bool in
 ** Preconditions: ta moves
 ** Postconditions: has ta changed
*******************************************************************************************************************************************************************************/

void Openspace::set_has_ta(bool in) {
	this->has_ta = in;
}

/*******************************************************************************************************************************************************************************
 ** Function: get_has_skill
 ** Description: getter
 ** Parameters: none
 ** Preconditions: hasta needed
 ** Postconditions: hasta returned
*******************************************************************************************************************************************************************************/

bool Openspace::get_has_ta() {
	return this->has_ta;
}

/*******************************************************************************************************************************************************************************
 ** Function: set_has_skill
 ** Description: setter
 ** Parameters: bool in
 ** Preconditions: changes has skill
 ** Postconditions:changed has skill
*******************************************************************************************************************************************************************************/

void Openspace::set_has_skill(bool in) {
	this->has_skill = in;
}

/*******************************************************************************************************************************************************************************
 ** Function: get_has_skill
 ** Description: getter
 ** Parameters: none
 ** Preconditions: has skill needed
 ** Postconditions: returns has_skill
*******************************************************************************************************************************************************************************/

bool Openspace::get_has_skill() {
	return this->has_skill;
}

/*******************************************************************************************************************************************************************************
 ** Function: set_is_end
 ** Description: setter
 ** Parameters: bool in
 ** Preconditions: is end needs to be changed
 ** Postconditions: is end changed
*******************************************************************************************************************************************************************************/

void Openspace::set_is_end(bool in) {
	this->is_end = in;
}

/*******************************************************************************************************************************************************************************
 ** Function: get_is_end
 ** Description: getter for is end
 ** Parameters: none
 ** Preconditions: called to check if tile is end
 ** Postconditions: is end returned
*******************************************************************************************************************************************************************************/

bool Openspace::get_is_end() {
	return this->is_end;
}

/*******************************************************************************************************************************************************************************
 ** Function: clear
 ** Description: clears oopenspace
 ** Parameters: none
 ** Preconditions: used by reset level
 ** Postconditions: openspace cleared
*******************************************************************************************************************************************************************************/

void Openspace::clear() {
	this->has_ta = false;
	this->has_skill = false;
	this->has_explorer = false;
}

/*******************************************************************************************************************************************************************************
 ** Function: is_empty
 ** Description: checks if empty and returns
 ** Parameters: none
 ** Preconditions: needed in various functiosn
 ** Postconditions: returns whether is empty
*******************************************************************************************************************************************************************************/

bool Openspace::is_empty() {
	if(!(is_instructor || has_explorer || is_start || is_end || has_ta || has_skill))
		return true;
	else
		return false;
}

/*******************************************************************************************************************************************************************************
 ** Function: Openspace
 ** Description: defualt constructor
 ** Parameters: none 
 ** Preconditions: none, not used
 ** Postconditions: default openspace created
*******************************************************************************************************************************************************************************/

Openspace::Openspace() : has_ta(false), has_skill(false), is_instructor(false), has_explorer(false), is_start(false), is_end(false) {
}


