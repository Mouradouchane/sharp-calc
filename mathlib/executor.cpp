

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

#ifndef _string 
	#define  _string
	#include <string>
#endif

/*
	note :	all the math functions here "preforme math" logic "on numbers as strings"
			in that way we can handle big integers and float's
*/

std::string add( std::string &number1 , std::string &number2 ) {

	std::string result = "";

	size_t len = ((number1.size() > number2.size()) ? number1.size() : number2.size());

	// variabls to operate on digits in numbers
	short carry  = 0;
	short digit1 = 0;
	short digit2 = 0;
	short sub_result = 0;

	for (size_t i = 0; i < len ; i++ ) {

		// process digit from n1
		if (i < number1.size()) {
			digit1 = (short)(number1[i] - '0');
		}
		else digit1 = 0;

		// process digit from n2
		if (i < number2.size()) {
			digit2 = (short)(number2[i] - '0');
		}
		else digit2 = 0;

		// calcualte result sub digit
		sub_result = (digit1 + digit2 + carry);

		// rest digits
		digit1 = 0;
		digit2 = 0;

		if (sub_result > 9) {
			carry = 1;
			result.push_back( (std::to_string(sub_result)[1]) );
		}
		else {
			carry = 0;
			result.push_back( (std::to_string(sub_result)[0]) );
		}

	}

	if(carry > 0) result.push_back( (std::to_string(carry)[0]) );

	std::reverse(result.begin(), result.end());
	return result;
}

std::string sub( std::string& number1, std::string& number2 ) {
	return "";
}

std::string mult( std::string& number1, std::string& number2 ) {
	return "";
}

std::string pow( std::string& number1, std::string& power ) {
	return "";
}

std::string div( std::string& number1, std::string& number2 ) {
	return "";
}

std::string rem( std::string& number1, std::string& number2 ) {
	return "";
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
