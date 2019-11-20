/*******************************************************************************************************************************************************************************
 ** Program: mazelocation.hpp 
 ** Author: Ryan Persson
 ** Date Created: 3/12/2018
 ** Description: virtual interface for Mazelocation class..
*******************************************************************************************************************************************************************************/

#ifndef _MAZELOCATION_CPP
#define _MAZELOCATION_CPP
class Mazelocation {
	protected:
	public:
		virtual bool is_occupiable() =0;
		virtual char get_display_character() = 0;
	
			/* These functions are only used in openspace class.
			 *  They had to be declared as virtual in order for me to call them on mazelocation
			 *  pointers in mazelevel. They are not implemented for the subclass wall. */
	
		virtual void set_has_explorer(bool in){}
		virtual bool get_has_explorer(){ return false;}
		virtual bool get_is_instructor(){return false;}
		virtual void set_has_ta(bool){}
		virtual bool get_has_ta() { return false;}
		virtual void set_has_skill(bool){}
		virtual bool get_has_skill() {return false;}
		virtual void set_is_start(bool in){}
		virtual bool get_is_start(){return false;}
		virtual void set_is_end(bool in){}
		virtual void set_has_instructor(bool in){}
		virtual bool get_is_end(){return false;}
		virtual bool is_empty() {return true;}
		virtual void clear() {}
};

#endif
