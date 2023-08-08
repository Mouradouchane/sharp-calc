

/*

	- executor file contain functions who dealing with math "+ - %"...
	- also this file contain the main function for calculation -> "execute" 
*/

#pragma once

#include "pch.h"
#include "framework.h"

#ifndef _storage 
	#define _storage 
	#include "storage.hpp"
#endif

#ifndef _defs
	#define _defs
	#include "defs.hpp"
#endif

#ifndef _node
	#define _node
	#include "node.cpp"
#endif

#ifndef _function
	#define _function
	#include "function.cpp"
#endif

#ifndef _variables
	#define _variables
	#include "variables.cpp"
#endif

/*
	note :	all the math functions here "preforme math" logic "on numbers as strings"
			in that way we can handle big integers and float's
*/
std::string add( std::string &number1 , std::string &number2 ) {

}

std::string sub( std::string& number1, std::string& number2 ) {

}

std::string mult( std::string& number1, std::string& number2 ) {

}

std::string pow( std::string& number1, std::string& power ) {

}

std::string div( std::string& number1, std::string& number2 ) {

}

std::string rem( std::string& number1, std::string& number2 ) {

}



/*
	recursive function used to compute the "math expression"
	after parsed to binary-tree
*/
std::string execute(node* target_node) {

	//	compute left and right nodes first
	std::string left_value  = (target_node->left  != nullptr) ? execute(target_node->left)  : EMPTY_STRING;
	std::string right_value = (target_node->right != nullptr) ? execute(target_node->right) : EMPTY_STRING;

	// to store final value
	std::string value = EMPTY_STRING;
	
	// based on type chose what to do 
	switch (target_node->type) {

		case UNDEFINED : {
			value = EMPTY_STRING;
		} break;

		case OPERATOR : {

			

		} break;

		case INT : {

		} break;

		case FLOAT : {

		} break;

		case VARIABLE : {

		} break;

		case FUNCTION : {

		} break;

		case PARAMETER : {

		} break;

	}

	return value;

} // end of execute function
