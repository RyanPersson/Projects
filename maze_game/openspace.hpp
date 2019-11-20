/*******************************************************************************************************************************************************************************
 ** Program: openspace.hpp 
 ** Author: Ryan Persson
 ** Date Created: 3/12/2018
 ** Description: interface for openspace object.
*******************************************************************************************************************************************************************************/

#ifndef _OPENSPACE_HPP
#define _OPENSPACE_HPP

#include "mazelocation.hpp"

class Openspace : public Mazelocation {
	protected:
		bool is_instructor;
		bool has_explorer;
		bool is_start;
		bool is_end;
		bool has_ta;
		bool has_skill;
	public:
		Openspace();
		virtual bool is_occupiable();
		virtual char get_display_character();
		void set_has_explorer(bool in);
		bool get_has_explorer();
		bool get_has_instructor();
		void set_has_ta(bool);
		bool get_has_ta();
		void set_has_skill(bool);
		bool get_has_skill();
		void set_is_start(bool in);
		bool get_is_start();
		void set_is_end(bool in);
		void set_has_instructor(bool in);
		bool get_is_end();
		bool is_empty();
		void clear();
};

#endif
