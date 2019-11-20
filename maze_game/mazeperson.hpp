/*******************************************************************************************************************************************************************************
 ** Filename: mazeperson.hpp
 ** Author: Ryan Persson
 ** Date Created: 3/17/2018
 ** Description: interface for mazeperson class
*******************************************************************************************************************************************************************************/
#ifndef _MAZEPERSON_HPP
#define _MAZEPERSON_HPP
class Mazeperson {
	private:
		int row,col;

	public:
		Mazeperson();
		Mazeperson(int, int);
		int get_row();
		int get_col();
		void set_location(int, int);
		
		virtual char get_move() = 0;
};
#endif
