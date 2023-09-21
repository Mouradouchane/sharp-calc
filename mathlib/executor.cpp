

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

#ifndef _vector
	#define _vector
	#include <vector>
#endif

#define NEGATIVE_VALUE 0
#define POSITIVE_VALUE 1 
#define UNSPECIFIED_VALUE 2

#define NUMBERS_ARE_EQUAL 0
#define NUMBER_1_BIGGER  1
#define NUMBER_2_BIGGER  2

#define MAX_DIVISION_LOOP 128

// main functions
std::string execute(node* target_node);
std::string add( std::string& number1, std::string& number2 , bool );
std::string sub( std::string& number1, std::string& number2 , bool );
std::string mult(std::string& number1, std::string& number2);
std::string pow( std::string& number1, std::string& power);
std::string div( std::string& number1, std::string& number2);
std::string rem( std::string& number1, std::string& number2);

// assistance functions
short compare(std::string const& number1, std::string const& number2);
void setup_numbers(std::string& number1, std::string& number2);

size_t calc_float_position(std::string const& number1, std::string const& number2);

// std::string setup_for_division(std::string& number1, std::string& number2);
std::pair<std::string, std::string> how_much_in( std::string& target_number , std::string& used_number);

std::string remove_zeros(std::string& target_number);
bool still_not_zero(std::string const& target_number);
/*
	note :	all the math functions here "preforme math" logic "on numbers as strings"
			in that way we can handle big integers and float's
*/


std::string add( std::string &number1 , std::string &number2 , bool dont_setup = false) {

	short number1_type = (number1[0] == '-') ? NEGATIVE_VALUE : (number1[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;
	short number2_type = (number2[0] == '-') ? NEGATIVE_VALUE : (number2[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;

	bool negative_plus_positive = ((!number1_type && number2_type) || (number1_type && !number2_type)) ? true : false;

	if (!dont_setup) {
		setup_numbers(number1, number2);
	}

	short cp = compare(number1, number2);
	size_t len = (number1.size() > number2.size()) ? number1.size() : number2.size();

	std::string& a = (cp == NUMBER_1_BIGGER) ? number1 : number2;
	std::string& b = (cp == NUMBER_1_BIGGER) ? number2 : number1;

	std::string str_result = "";

	// variables to operate on digits in numbers
	short carry  = 0;
	short digit1 = 0;
	short digit2 = 0;
	short n_result = 0;
	bool float_activated = false;

	for (size_t i = 0 ; i < len ; i++ ) {

		// process digit from n1
		if (i < a.size()) {

			if (a[i] == '.') {
				str_result.push_back('.');
				float_activated = true;
				continue;
			}

			digit1 = (short)(a[i] - '0');
			digit1 = (digit1 < 0 || digit1 > 9) ? 0 : digit1;
		}
		else digit1 = 0;

		// process digit from n2
		if (i < b.size()) {
			
			if (b[i] == '.') {
				str_result.push_back('.');
				float_activated = true;
				continue;
			}

			digit2 = (short)(b[i] - '0');
			digit2 = (digit2 < 0 || digit2 > 9) ? 0 : digit2;
		}
		else digit2 = 0;

		// if -a + b || a + -b
		if ( negative_plus_positive ) {

			if (carry == 1) {
				digit2 += 1;
				carry = 0;
			}

			if (digit1 < digit2) {
				n_result = (digit1 + 10) - digit2;
				carry = 1;
			}
			else n_result = digit1 - digit2;

			str_result.push_back(std::to_string(n_result)[0]);

		}
		else {

			// calcualte result sub digit
			n_result = (digit1 + digit2 + carry);

			// rest digits
			digit1 = 0;
			digit2 = 0;

			if (n_result > 9) {
				carry = 1;
				str_result.push_back((std::to_string(n_result)[1]));
			}
			else {
				carry = 0;
				str_result.push_back((std::to_string(n_result)[0]));
			}

		}

		n_result = 0;
	}

	if(carry > 0) str_result.push_back( (std::to_string(carry)[0]) );

	// if -a + -b = -x
	// if (number1_type == NEGATIVE_VALUE && number2_type == NEGATIVE_VALUE) str_result.push_back('-');
	
	// if the bigger number is negative result gonna be negative
	if ( a[ a.size() - 1] == '-' ) str_result.push_back('-');

	if (!dont_setup) {
		std::reverse(str_result.begin(), str_result.end());
	}

	return str_result;

} // end of add function



std::string sub( std::string& number1, std::string& number2 , bool dont_setup = false) {

	// specify numbers operators
	short number1_type = (number1[0] == '-') ? NEGATIVE_VALUE : (number1[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;
	short number2_type = (number2[0] == '-') ? NEGATIVE_VALUE : (number2[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;

	if (!dont_setup) {
		setup_numbers(number1, number2);
	}

	short cp = compare(number1 , number2);
	size_t len = (number1.size() > number2.size()) ? number1.size() : number2.size();

	std::string& a = (cp == NUMBER_1_BIGGER) ? number1 : number2;
	std::string& b = (cp == NUMBER_1_BIGGER) ? number2 : number1;

	std::string str_result = "";

	short carry  = 0;
	short digit1 = 0;
	short digit2 = 0;
	short n_result = 0;

	for (size_t i = 0; i < len; i++) {

		// if( i < b.size() ) if (b[i] == '-' || b[i] == '+') break;

		// cast digit's

		if (i < a.size()) {

			if (a[i] == '.') {
				str_result.push_back('.');
				continue;
			}

			digit1 = (short)(a[i] - '0');
			digit1 = (digit1 < 0 || digit1 > 9) ? 0 : digit1;
		} 
		else digit1 = 0;

		if (i < b.size()) {

			if (b[i] == '.') {
				str_result.push_back('.');
				continue;
			}

			digit2 = (short)(b[i] - '0');
			digit2 = (digit2 < 0 || digit2 > 9) ? 0 : digit2;
		}
		else digit2 = 0;

		// calc

		// a - -b => a + b
		if ( b[ b.size() - 1] == '-' && a[ a.size() - 1] != '-' ) {

			// calcualte result sub digit
			n_result = (digit1 + digit2 + carry);

			// rest digits
			digit1 = 0;
			digit2 = 0;

			if (n_result > 9) {
				carry = 1;
				str_result.push_back((std::to_string(n_result)[1]));
			}
			else {
				carry = 0;
				str_result.push_back((std::to_string(n_result)[0]));
			}

			n_result = 0;
			continue;
		}

		// -a - b => -(a+b)
		if (b[b.size() - 1] != '-' && a[a.size() - 1] == '-') {

			// calcualte result sub digit
			n_result = (digit1 + digit2 + carry);

			// rest digits
			digit1 = 0;
			digit2 = 0;

			if (n_result > 9) {
				carry = 1;
				str_result.push_back((std::to_string(n_result)[1]));
			}
			else {
				carry = 0;
				str_result.push_back((std::to_string(n_result)[0]));
			}

			n_result = 0;
			continue;
		}

		// -a - -b => -(a-b)


		// default case

		if (carry == 1) {
			digit2 += 1;
			carry = 0;
		}
			
		if (digit1 < digit2) {
			n_result = (digit1 + 10) - digit2;
			carry = 1;
		}
		else n_result = digit1 - digit2;
		
		str_result.push_back(std::to_string(n_result)[0]);
		
		n_result = 0;
	}

	if ( cp != NUMBER_2_BIGGER && number1_type == NEGATIVE_VALUE ) str_result.push_back('-');
	if ( cp == NUMBER_2_BIGGER && number2_type ) str_result.push_back('-');

	if (!dont_setup) {
		std::reverse(str_result.begin(), str_result.end());
	}

	return str_result;

} // end of sub function



std::string mult( std::string& number1, std::string& number2 ) {

	short number1_type = (number1[0] == '-') ? NEGATIVE_VALUE : (number1[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;
	short number2_type = (number2[0] == '-') ? NEGATIVE_VALUE : (number2[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;

	// if -a * b or -b * a ==> -result
	bool negative_result = (number1_type > 0 && number2_type == 0) || (number1_type == 0 && number2_type > 0) ? true : false;

	// reverse numbers -> 'easy to deal with em'
	std::reverse(number1.begin(), number1.end());
	std::reverse(number2.begin(), number2.end());

	// final result string 
	std::string str_result;

	// this vector will contain all the result of all sub multiplication , we have to add them later
	std::vector<std::string> results;
	std::string temp_result;

	size_t float_position = calc_float_position( number1 , number2 );

	short digit1 = 0;
	short digit2 = 0;
	short carry  = 0;
	short n_result = 0; // temp result 

	// multiplication process
	for (size_t i = 0 , z = 0; i < number1.size(); i++ , z++ ) {

		if (number1[i] == '.') continue;
		
		temp_result = std::string(z,'0');

		digit1 = (short)(number1[i] - '0');
		digit1 = (digit1 < 0 || digit1 > 9) ? 0 : digit1 ;

		for (size_t u = 0; u < number2.size(); u++) {

			if (number2[u] == '.') continue;
			
			digit2 = (short)(number2[u] - '0');
			digit2 = (digit2 < 0 || digit2 > 9) ? 0 : digit2 ;

			n_result = digit1 * digit2 + carry;

			if (n_result > 9) {
				carry = (short)(std::to_string(n_result)[0] - '0');
				temp_result.push_back(std::to_string(n_result)[1]);
			}
			else {
				carry = 0;
				temp_result.push_back(std::to_string(n_result)[0]);
			}

		}

		if (carry > 0) temp_result.push_back( std::to_string(carry)[0] );
		carry = 0;
		results.push_back(temp_result);

	}

	// add results 
	str_result = results[0];
	for (size_t i = 1; i < results.size(); i++) {

		str_result = add( str_result , results[i] , true);

	}

	if (float_position > 0) str_result.insert(float_position, ".");
	if (negative_result) str_result.push_back('-');

	std::reverse(str_result.begin(), str_result.end());
	return str_result;

} // end of mult function



std::string pow( std::string& number1, std::string& power ) {
	return "";
} // end of pow function


// note : number1 divided by number2
std::string div( std::string& number1, std::string& number2 ) {

	std::string str_result = "";
	std::pair<std::string, std::string> count_object; // used by "how_much_in" 
	
	bool float_point_active = false;

	std::string number  = remove_zeros(number1);
	std::string diviser = remove_zeros(number2);
	
	std::string counter_number = "0";

	// if small / big , result will be "0,..."
	if (diviser.size() > number.size()) {

		float_point_active  = true;
		size_t needed_zeros = diviser.size() - number.size();

		str_result += "0.";
		number.push_back('0');

		for ( size_t i = 1; i < needed_zeros; i++ ) {
			number.push_back('0');
			str_result.push_back('0');
		}

	}
	

	// division cycle

	size_t loop = 0; 
	while ( still_not_zero(number) && loop < MAX_DIVISION_LOOP ) {

		// setup values 
		size_t i = diviser.size(); 
		while (1) {

			if ( i <= number.size() ) {

				// if number >= diviser
				if ( compare(number.substr(0, i), diviser) < NUMBER_2_BIGGER ) {
					counter_number = number.substr(0, i);
					break;
				}

			}
			else {

				size_t f = 0;

				while (count_object.second == "0") {

					number.push_back('0');

					if (f > 0) {
						str_result.push_back('0');
					}

					/*
					if (!float_point_active) {
						float_point_active = true;
						str_result += "0.";
					}
					*/

					count_object = how_much_in(number, diviser);
					f++;
				}

			}

			i++;
		}
				
		// count how many in 
		count_object = how_much_in( counter_number , diviser );

		// just round the numbers range for good "sub"
		if ( count_object.first.size() < number.size() ) {

			for (size_t i = 0; i < (number.size() - count_object.first.size()); i++) {
				count_object.first.push_back('0');
			}

		}

		// subtract counted value from number for next cycle
		number = sub( number , count_object.first );

		loop++;
	}

	return str_result;
} // end of div function



std::string rem( std::string& number1, std::string& number2 ) {
	return "";
}


/*

		assistance functions

*/


// Note : numbers should be reversed !!!
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

// function to setup numbers and make them ready for the calculation
void setup_numbers(std::string& number1, std::string& number2) {

	short numbers_case = 0;

	long int number1_float_range = -1;
	long int number2_float_range = -1;

	// check number1 if float
	for (size_t i = 0; i < number1.size(); i++) {

		if (number1[i] == '.') {
			number1_float_range = number1.size() - i - 1;
			numbers_case += 1;
			break;
		}

	}

	// check number2 if float
	for (size_t i = 0; i < number2.size(); i++) {

		if (number2[i] == '.') {
			number2_float_range = number2.size() - i - 1;
			numbers_case += 1;
			break;
		}

	}

	switch (numbers_case) {
		
		case 1 : { // when one number is float

			std::string& int_number = (number1_float_range <  0) ? number1 : number2;
			int_number.push_back('.');

			size_t range_to_fill = (number1_float_range >= 0) ? number1_float_range : number2_float_range;

			for (size_t i = 0; i < range_to_fill; i++) {
				int_number.push_back('0');
			}

		} break;

		case 2 : { // when tow numbers is float

			if (number1_float_range != number2_float_range) {

				std::string& short_number = (number1_float_range < number2_float_range) ? number1 : number2;

				size_t range_to_fill = (number1_float_range > number2_float_range) ? number1_float_range - number2_float_range : number2_float_range - number1_float_range;

				for (size_t i = 0; i < range_to_fill; i++) {
					short_number.push_back('0');
				}

			}

		} break;

	}

	std::reverse(number1.begin(), number1.end());
	std::reverse(number2.begin(), number2.end());

} // end of setup_numbers function

// this function used by mult to now where index should it put " float point '.' "
size_t calc_float_position(std::string const& number1, std::string const& number2) {

	size_t index = 0;

	for (size_t i = 0; i < number1.size(); i++) {
		if (number1[i] == '.') {
			index += i;
			break;
		}
	}

	for (size_t i = 0; i < number2.size(); i++) {
		if (number2[i] == '.') {
			index += i;
			break;
		}
	}

	return index;

} // end of calc_float_position function

// function to remove no needed zero's from numbers
std::string remove_zeros(std::string& target_number) {

	std::string new_str_number = "";

	size_t i = 0;
	for ( ; i < (target_number.size() - 1) ; i++) {
		if (target_number[i] != '0') break;
	}

	for (; i < target_number.size(); i++) {
		new_str_number.push_back(target_number[i]);
	}

	return new_str_number;
} // end of remove_zeros

bool still_not_zero(std::string const& target_number) {

	for ( size_t i = 0; i < target_number.size(); i++ ) {
		if (target_number[i] != '0' || target_number[i] != '.') return true;
	}

	return false;
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
