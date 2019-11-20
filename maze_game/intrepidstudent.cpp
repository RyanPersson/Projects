/*******************************************************************************************************************************************************************************
 ** filename: intrepidstudent.cpp
 ** Author: Ryan Persson
 ** Date Created: 3/12/2018
 ** Description: interface for intrepidstudent class
*******************************************************************************************************************************************************************************/
#include "intrepidstudent.hpp"
#include "template_functions.hpp"
#include <iostream>

/*******************************************************************************************************************************************************************************
 ** Function: intrepid student
 ** Description: default constructor
 ** Parameters: none
 ** Preconditions: none, never used
 ** Postconditions: new intrepid student constructed
*******************************************************************************************************************************************************************************/

Intrepidstudent::Intrepidstudent() : Mazeperson(-1,-1), programming_skills(0) {}

/*******************************************************************************************************************************************************************************
 ** Function: Intrepidstudent
 ** Description: parametarized constructor
 ** Parameters: int row, int col
 ** Preconditions: called when intrepid student is created
 ** Postconditions: creates intrepid student at location
*******************************************************************************************************************************************************************************/

Intrepidstudent::Intrepidstudent(int row, int col) : Mazeperson(row,col), programming_skills(0) {}

/*******************************************************************************************************************************************************************************
 ** Function: get_move()
 ** Description: returns move
 ** Parameters: none
 ** Preconditions: called when student move needed
 ** Postconditions: returns move from valid chars
*******************************************************************************************************************************************************************************/

char Intrepidstudent::get_move() {
	char choice[] = {'W','A','S','D','P','U','w','a','s','d'};
	std::cout << "get move" << std::endl;
	char move = get_char(choice, 10);	
	//add code here to check functionalliy of edge detection
}

/*******************************************************************************************************************************************************************************
 ** Function: get_programming_skills
 ** Description: returns programmins skills
 ** Parameters: none
 ** Preconditions: getter for programming skills
 ** Postconditions: programming skills returned
*******************************************************************************************************************************************************************************/

int Intrepidstudent::get_programming_skills() {
	return this->programming_skills;
}

/*******************************************************************************************************************************************************************************
 ** Function: set_programming_skills
 ** Description: sets programming skills
 ** Parameters:  int new_skills
 ** Preconditions: called when new level is moved to
 ** Postconditions: new level has previous programming skills
*******************************************************************************************************************************************************************************/

void Intrepidstudent::set_programming_skills(int new_skills) {
	this->programming_skills = new_skills;
}

/*******************************************************************************************************************************************************************************
 ** Function: 
 ** Description: 
 ** Parameters: 
 ** Preconditions: 
 ** Postconditions:
*******************************************************************************************************************************************************************************/

