

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

#define NEGATIVE_VALUE 0
#define POSITIVE_VALUE 1 
#define UNSPECIFIED_VALUE 2

#define NUMBERS_ARE_EQUAL 0
#define NUMBER_1_BIGGER  1
#define NUMBER_2_BIGGER  2

// def's
std::string add(std::string& number1, std::string& number2 , bool dont_reverse );
std::string sub(std::string& number1, std::string& number2 , bool dont_reverse );
std::string mult(std::string& number1, std::string& number2);
std::string pow(std::string& number1, std::string& power);
std::string div(std::string& number1, std::string& number2);
std::string rem(std::string& number1, std::string& number2);
short compare(std::string const& number1, std::string const& number2);


/*
	note :	all the math functions here "preforme math" logic "on numbers as strings"
			in that way we can handle big integers and float's
*/


std::string add( std::string &number1 , std::string &number2 , bool dont_reverse = false) {

	short number1_type = (number1[0] == '-') ? NEGATIVE_VALUE : (number1[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;
	short number2_type = (number2[0] == '-') ? NEGATIVE_VALUE : (number2[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;

	// if negative + positive 
	if( number1_type == NEGATIVE_VALUE || number2_type == NEGATIVE_VALUE ){

		if ( number1_type == NEGATIVE_VALUE && number2_type == NEGATIVE_VALUE ) goto keep_process;

		else return sub(number1, number2 , false);

	}

	keep_process :

	if (!dont_reverse) {
		// reverse numbers -> 'easy to deal with em'
		std::reverse(number1.begin(), number1.end());
		std::reverse(number2.begin(), number2.end());
	}

	std::string result = "";

	size_t len = ((number1.size() > number2.size()) ? number1.size() : number2.size());

	// variables to operate on digits in numbers
	short carry  = 0;
	short digit1 = 0;
	short digit2 = 0;
	short sub_result = 0;


	for (size_t i = 0 ; i < len ; i++ ) {

		// process digit from n1
		if (i < number1.size()) {
			digit1 = (short)(number1[i] - '0');
			digit1 = (digit1 < 0 || digit1 > 9) ? 0 : digit1;
		}
		else digit1 = 0;

		// process digit from n2
		if (i < number2.size()) {
			digit2 = (short)(number2[i] - '0');
			digit2 = (digit2 < 0 || digit2 > 9) ? 0 : digit2;
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

	// negative + negative = negative
	if (number1_type == NEGATIVE_VALUE && number2_type == NEGATIVE_VALUE) result.push_back('-');

	// reverse result back to normal look :)
	std::reverse(result.begin(), result.end());
	return result;

} // end of add function



std::string sub( std::string& number1, std::string& number2 , bool dont_reverse = false) {

	// specify numbers operators
	short number1_type = (number1[0] == '-') ? NEGATIVE_VALUE : (number1[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;
	short number2_type = (number2[0] == '-') ? NEGATIVE_VALUE : (number2[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;

	if (!dont_reverse) {
		// reverse numbers -> 'easy to deal with em'
		std::reverse(number1.begin(), number1.end());
		std::reverse(number2.begin(), number2.end());
	}

	short cp = compare(number1 , number2);
	size_t len = (number1.size() > number2.size()) ? number1.size() : number2.size();

	std::string& a = (cp == NUMBER_1_BIGGER) ? number1 : number2;
	std::string& b = (cp == NUMBER_1_BIGGER) ? number2 : number1;

	std::string result = "";

	short carry  = 0;
	short temp   = 0;
	short digit1 = 0;
	short digit2 = 0;

	for (size_t i = 0; i < len; i++) {

		// if( i < b.size() ) if (b[i] == '-' || b[i] == '+') break;

		// cast digit's

		if (i < a.size()) {
			digit1 = (short)(a[i] - '0');
			digit1 = (digit1 < 0 || digit1 > 9) ? 0 : digit1;
		} 
		else digit1 = 0;

		if (i < b.size()) {
			digit2 = (short)(b[i] - '0');
			digit2 = (digit2 < 0 || digit2 > 9) ? 0 : digit2;
		}
		else digit2 = 0;

		// calc

		// a - -b => a + b
		if ( b[ b.size() - 1] == '-' && a[ a.size() - 1] != '-' ) {

			// calcualte result sub digit
			temp = (digit1 + digit2 + carry);

			// rest digits
			digit1 = 0;
			digit2 = 0;

			if (temp > 9) {
				carry = 1;
				result.push_back((std::to_string(temp)[1]));
			}
			else {
				carry = 0;
				result.push_back((std::to_string(temp)[0]));
			}

			temp = 0;
			continue;
		}

		// -a - b => -(a+b)
		if (b[b.size() - 1] != '-' && a[a.size() - 1] == '-') {

			// calcualte result sub digit
			temp = (digit1 + digit2 + carry);

			// rest digits
			digit1 = 0;
			digit2 = 0;

			if (temp > 9) {
				carry = 1;
				result.push_back((std::to_string(temp)[1]));
			}
			else {
				carry = 0;
				result.push_back((std::to_string(temp)[0]));
			}

			temp = 0;
			continue;
		}

		// -a - -b => -(a-b)


		// default case

		if (carry == 1) {
			digit2 += 1;
			carry = 0;
		}
			
		if (digit1 < digit2) {
			temp = (digit1 + 10) - digit2;
			carry = 1;
		}
		else temp = digit1 - digit2;
		
		result.push_back(std::to_string(temp)[0]);
		
		temp = 0;
	}

	if (number1_type == NEGATIVE_VALUE && number2_type == NEGATIVE_VALUE) {

		if( cp == NUMBER_1_BIGGER ) result.push_back('-');

	}
	else {
		if (cp == NUMBER_2_BIGGER || a[a.size() - 1] == '-') result.push_back('-');
	}

	// reverse result back to normal look :)
	std::reverse(result.begin(), result.end());
	return result;

} // end of sub function



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

// Note : numbers reversed !!!
short compare(std::string const& number1, std::string const& number2) {

	short digit1 = 0;
	short digit2 = 0;

	short cp = 0;
	// final answer will be here
	short state = NUMBERS_ARE_EQUAL; 

	size_t size = (number1.size() > number2.size()) ? number1.size() : number2.size();

	for ( size_t i = 0; i < size ; i++ ) {

		// cast digit's

		if (i < number1.size()) {
			digit1 = (short)(number1[i] - '0');
			digit1 = (digit1 < 0 || digit1 > 9) ? 0 : digit1;
		}
		else digit1 = 0;

		if (i < number2.size()) {
			digit2 = (short)(number2[i] - '0');
			digit2 = (digit2 < 0 || digit2 > 9) ? 0 : digit2;
		}
		else digit2 = 0;

		// compare digit's 
		cp = digit1 - digit2;

		// cp == 0 mean digits equal
		if (cp == 0) continue;
		// otherwise
		else state = ( cp > 0 ) ? NUMBER_1_BIGGER : NUMBER_2_BIGGER;

	}

	return state;

} // end of compare function



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
