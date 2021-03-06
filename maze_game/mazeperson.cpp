/*******************************************************************************************************************************************************************************
 ** filename: mazeperson.cpp
 ** Author: Ryan Persson
 ** Date Created: 3/12/2018
 ** Description: implementation of mazeperson class
*******************************************************************************************************************************************************************************/
#include "mazeperson.hpp"

/*******************************************************************************************************************************************************************************
 ** Function: mazeperson
 ** Description: default constructor
 ** Parameters: none
 ** Preconditions: none, not used
 ** Postconditions: default mazeperson created
*******************************************************************************************************************************************************************************/

Mazeperson::Mazeperson() : row(-1), col(-1) {}

/*******************************************************************************************************************************************************************************
 ** Function: Mazeperson
 ** Description: parameterized constructor
 ** Parameters: int row, int col
 ** Preconditions: mazeperson needed at location
 ** Postconditions: mazeperson created at location
*******************************************************************************************************************************************************************************/

Mazeperson::Mazeperson(int row, int col) : row(row), col(col) {}

/*******************************************************************************************************************************************************************************
 ** Function: get_row
 ** Description: getter for ro
 ** Parameters: none
 ** Preconditions: row needed
 ** Postconditions:row returned
*******************************************************************************************************************************************************************************/

int Mazeperson::get_row() {
	return this->row;
}

/*******************************************************************************************************************************************************************************
 ** Function: get_col
 ** Description: getter for col
 ** Parameters: none
 ** Preconditions: col needed
 ** Postconditions:col returned
*******************************************************************************************************************************************************************************/

int Mazeperson::get_col() {
	return this->col;
}

/*******************************************************************************************************************************************************************************
 ** Function: set_location
 ** Description: changes mazeperson location
 ** Parameters: int nrow, int ncol
 ** Preconditions: when a mazeperson is moved
 ** Postconditions: mazeperson moved
*******************************************************************************************************************************************************************************/

void Mazeperson::set_location(int nrow, int ncol) {
	this->row = nrow;
	this->col = ncol;
}

