

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

#ifndef _analysing
	#define _analysing
	#include "analysing.cpp"
#endif



extern "C" __declspec(dllexport) std::string get_variable(std::string var_name);
extern std::pair<std::string, func> get_function(std::string & function_name);
extern std::vector<std::string>* parse_parameters(std::string& parameters_as_string , bool parse_without_name_check = false );
extern std::pair<std::string, std::vector<std::string>> parse_function_call(std::string& function_call);

#define NEGATIVE_VALUE 0
#define POSITIVE_VALUE 1 
#define UNSPECIFIED_VALUE 2

#define NUMBERS_ARE_EQUAL 0
#define NUMBER_1_BIGGER  1
#define NUMBER_2_BIGGER  2

#define MAX_DIVISION_LOOP 128

// main functions
std::string execute( node* target_node , std::map<std::string, std::string>* function_parameters = nullptr);

std::string add(  std::string& number1  , std::string& number2 , bool dont_setup = false );
std::string sub(  std::string& number1  , std::string& number2 , bool dont_setup = false );
std::string mult( std::string& number1  , std::string& number2 );
std::string pow(  std::string& base     , std::string& power );
std::string div(  std::string& dividend , std::string& _diviser_ , bool catch_reminder = false );
std::string mod(  std::string& dividend , std::string& _diviser_ );

// assistance functions
short compare(std::string & number1, std::string & number2 , bool);

void setup_for_add_or_sub(std::string& number1, std::string& number2);
std::string setup_for_div_or_mult(std::string& target_number , bool remove_sign = true);

size_t calc_float_position(std::string const& number1, std::string const& number2);
std::pair<std::string, std::string> how_much_in( std::string& target_number , std::string& used_number);
void balance_floats(std::string& number1, std::string& number2 , size_t* catch_balance_value_for_reminder = nullptr );
bool still_not_zero(std::string const& target_number);


/*
	note :	all the math functions here "preforme math" logic "on numbers as strings"
			in that way we can handle big integers and float's
*/


std::string add( std::string &number1 , std::string &number2 , bool dont_setup ) {

	short number1_type = (number1[0] == '-') ? NEGATIVE_VALUE : (number1[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;
	short number2_type = (number2[0] == '-') ? NEGATIVE_VALUE : (number2[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;

	bool negative_plus_positive = ((!number1_type && number2_type) || (number1_type && !number2_type)) ? true : false;

	if (!dont_setup) {
		setup_for_add_or_sub(number1, number2);
	}

	short cp = compare(number1, number2 , false);
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

		std::reverse(number1.begin(), number1.end());
		std::reverse(number2.begin(), number2.end());

		std::reverse(str_result.begin(), str_result.end());
	}

	return str_result;

} // end of add function



std::string sub( std::string& number1, std::string& number2 , bool dont_setup ) {

	// specify numbers operators
	short number1_type = (number1[0] == '-') ? NEGATIVE_VALUE : (number1[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;
	short number2_type = (number2[0] == '-') ? NEGATIVE_VALUE : (number2[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;

	if (!dont_setup) {
		setup_for_add_or_sub(number1, number2);
	}

	short cp = compare(number1 , number2 , false);
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

		std::reverse(number1.begin(), number1.end());
		std::reverse(number2.begin(), number2.end());

		std::reverse(str_result.begin(), str_result.end());
	}

	return str_result;

} // end of sub function



std::string mult( std::string& number1, std::string& number2 ) {

	short number1_type = (number1[0] == '-') ? NEGATIVE_VALUE : (number1[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;
	short number2_type = (number2[0] == '-') ? NEGATIVE_VALUE : (number2[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;

	// if -a * b or -b * a ==> -result
	bool negative_result = (number1_type > 0 && number2_type == 0) || (number1_type == 0 && number2_type > 0) ? true : false;

	// filter against well known operations like : x * 0 , x * 1 ; before you start to progress
	number1 = setup_for_div_or_mult(number1);
	number2 = setup_for_div_or_mult(number2);

	// x * 0 or 0 * x ====> 0
	if (number1 == "0" || number1 == "0.0" || number1 == "-0" || number1 == "-0.0") {
		return (negative_result) ? "-0" : "0";
	}
	if (number2 == "0" || number2 == "0.0" || number2 == "-0" || number2 == "-0.0") {
		return (negative_result) ? "-0" : "0";
	}

	// x * 1 or 1 * x ====> x
	if (number1 == "1" || number1 == "1.0" || number1 == "-1" || number1 == "-1.0") {
		return (negative_result) ? "-" + number2 : number2;
	}
	if (number2 == "1" || number2 == "1.0" || number2 == "-1" || number2 == "-1.0") {
		return (negative_result) ? "-" + number1 : number1;
	}

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
	for (size_t i = 0 , z = 0; i < number1.size(); i++ ) {

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
		z += 1;
		results.push_back(temp_result);

	}

	// add results 
	str_result = results[0];
	for (size_t i = 1; i < results.size(); i++) {

		str_result = add( str_result , results[i] , true);

	}

	if (float_position > 0) str_result.insert(float_position, ".");
	if (negative_result) str_result.push_back('-');

	std::reverse(number1.begin(), number1.end());
	std::reverse(number2.begin(), number2.end());

	std::reverse(str_result.begin(), str_result.end());

	return str_result;

} // end of mult function


/*
	note: pow function "only works with integers exponent_power"
*/ 
std::string pow( std::string& base_number , std::string& exponent_power ) {

	short base_type = (base_number[0] == '-')  ? NEGATIVE_VALUE : (base_number[0]  == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;
	short exponent_type = (exponent_power[0] == '-') ? NEGATIVE_VALUE : (exponent_power[0] == '+') ? POSITIVE_VALUE : UNSPECIFIED_VALUE;

	// no float power accepted 
	if (is_float(exponent_power) == VALID_VALUE) return "0";

	// note : different calculations based on the numbers signs => positive or negative .
	// based on this variable we will decide .
	short nums_case = 0;
	nums_case += ( base_type  == NEGATIVE_VALUE) ? 1 : 0;
	nums_case += (exponent_type == NEGATIVE_VALUE) ? 1 : 0;

	std::string number = setup_for_div_or_mult(base_number , false);
	std::string power  = setup_for_div_or_mult(exponent_power);

	/*
		check against the exceptional case like "x**1 , x**0 ,..."
	*/
	
	short base_number_check = (number == "0" || number == "0.0") ? 0 : (number == "-0" || number == "-0.0") ? -0 : (number == "1" || number == "1.0") ? 1 : (number == "-1" || number == "-1.0") ? -1 : 2;
	short power_number_check = (power == "0" || power == "0.0") ? 0 : (power == "-0" || power == "-0.0") ? -0 : (power == "1" || power == "1.0") ? 1 : (power == "-1" || power == "-1.0") ? -1 : 2;

	// 0**0 = 1
	if (base_number_check == 0 && power_number_check == 0) {
		return "1";
	}
	// 0**x = 0
	if (base_number_check == 0) {
		return "0";
	}
	// x**0 = 1
	if (power_number_check == 0) {
		return "1";
	}
	// 1**x = 1
	if (base_number_check == 1) {
		return "1";
	}
	// x**1 = x
	if (power_number_check == 1 && exponent_type == POSITIVE_VALUE) {
		return base_number;
	}

	std::string str_result = "1";

	std::string one = "1"; // just for decreasing "power" in loop

	// power process
	switch (nums_case) {

		case 0 : { // positive ** positive

			while (compare(power, one, true) < NUMBER_2_BIGGER) {

				// multiplay value by the power then decrease power by on
				str_result = mult(str_result, base_number);
				power = sub(power, one, false);

			}

		} 
		break;

		case 1 : { // on of them negative 

			// if base is negative 
			if (base_type == NEGATIVE_VALUE) {

				while (compare(power, one, true) < NUMBER_2_BIGGER) {

					// multiplay value by the power then decrease power by on
					str_result = mult(str_result, number);
					power = sub(power, one, false);

				}

				// str_result.insert(0, "-");
			}
			else { // exponent is negative

				number = div(one, number);

				while (compare(power, one, true) < NUMBER_2_BIGGER) {

					// multiplay value by the power then decrease power by on
					str_result = mult(str_result, number);
					power = sub(power, one, false);

				}

			}

		}
		break;

		case 2 : { // both of them negative

			number = div(one, number);

			while (compare(power, one, true) < NUMBER_2_BIGGER) {

				// multiplay value by the power then decrease power by on
				str_result = mult(str_result, number);
				power = sub(power, one, false);

			}

			// str_result.insert(0, "-");

		}
		break;

	}


	return str_result;

} // end of pow function


// note : number1 divided by number2
std::string div( std::string& number1, std::string& number2 , bool catch_reminder ) {

	std::string str_result = "";
	std::pair<std::string, std::string> count_object; // used by "how_much_in" 
	
	bool float_point_active = false;
	bool skip_counting = false;

	bool is_number1_float = (is_float(number1) == INVALID_VALUE) ? false : true;
	bool is_number2_float = (is_float(number2) == INVALID_VALUE) ? false : true;

	std::string number  = setup_for_div_or_mult(number1);
	std::string diviser = setup_for_div_or_mult(number2);

	// check for output result sign => - & +
	short output_sign = 0;
	output_sign += (number1[0] == '-') ? 1 : 0;
	output_sign += (number2[0] == '-') ? 1 : 0;

	if (output_sign == 1) str_result += '-';

	/*
		check if there's any special case like "x/0 , x/1 , ..."
	*/

	// if number / 0 => infinity
	if (diviser == "0" || diviser == "-0" || diviser == "0.0" || diviser == "-0.0") {
		return (output_sign == 1) ? "-infinity" : "infinity";
	}
	// if number / 1 => number
	if (diviser == "1" || diviser == "-1" || diviser == "-1.0" || diviser == "1.0") {

		if (output_sign == 1) {
			if (diviser[0] != '-') return ("-" + number);
			else return number;
		}
		else return number;

	}
	// if 0 / diviser => 0
	if (number == "0" || number == "-0" || number == "0.0" || number == "-0.0" ) return "0";

	// if x / x => 1
	if (number == diviser) return (output_sign == 1) ? "-1" : "1";

	// end of checking special cases ==============


	/*
		balance the numbers if there's a float
	*/
	
	size_t catch_balance_change_for_reminder_operation = 0;

	if (is_number1_float || is_number2_float) {
		balance_floats( number , diviser , &catch_balance_change_for_reminder_operation );
	}

	// division cycle

	std::string chunk = "0"; // when we cut a part from "number" for division
	size_t loop = 0; 
	size_t r = diviser.size();
	size_t added_zeros = 0;
	bool round = true;

	while ( still_not_zero(number) && loop < MAX_DIVISION_LOOP ) {

		// get a chunck for sub

		if (r <= number.size()) {
			chunk = number; // .substr(0, r);

			if ( compare(chunk, diviser, true) != NUMBER_2_BIGGER ) {
				goto count_scope;
			}
			else {
				r += 1;
				continue;
			}
		}
		if (r > number.size()) {

			if (catch_reminder) {
				return number;
			}

			if (!float_point_active) {
				str_result += ".";
				float_point_active = true;
			}

			chunk = number;

			do {

				if (added_zeros > 0) {
					str_result += "0";
				}

				chunk += "0";
				added_zeros += 1;

				count_object = how_much_in(chunk, diviser);

			} while (count_object.second == "0");

			number = chunk;
			goto sub_scope;
		}


		// count how many "diviser value" in the current "chunk"
		count_scope : {

			count_object = how_much_in(chunk, diviser);

			if (count_object.second == "0") {

				if (catch_reminder) {
					return chunk;
				}

				chunk += "0";
				added_zeros += 1;

				if (added_zeros > 1) {

					if (!float_point_active) {
						str_result += ".";
						float_point_active = true;
					}
					else str_result += "0";

				}

				goto count_scope;
			}
			else {
				// number = chunk;
				if (chunk.size() == number.size()) {
					goto sub_scope;
				}
				else goto round_scope;
			}
			

		}

		round_scope: {
			// round the numbers ranges for good "sub"
			if ( count_object.first.size() < number.size() && round ) {

				size_t range_to_fill = number.size() - ( ( added_zeros == 0 ) ? r : count_object.first.size() );

				for ( size_t z = 0; z < range_to_fill; z++ ) {
					count_object.first.push_back('0');
				}

			}
		}

		sub_scope: {

			// update final result
 			str_result += count_object.second;

			// subtract counted value from number for next cycle
			number = setup_for_div_or_mult( (std::string&)sub(number, count_object.first) );

			r = diviser.size();
			loop++;
			added_zeros = 0;
			round = true;
		}

	}

	// avoid "-.xxxx" or ".xxx"
	if (str_result[0] == '.') {
		str_result.insert(0, "0");
	}
	else {
		
		// to avoid "out of range" exception => "str_result[1]"
		if (str_result.size() > 1) { 

			if (str_result[0] == '-' && str_result[1] == '.') {
				str_result.insert(1, "0");
			}

		}

	}


	return (catch_reminder) ? "0" : str_result;

} // end of div function


// note this function use div function to preforme reminder operation
// note : mod function not support decimals
std::string mod( std::string& dividend, std::string& _diviser_ ) {

	std::string  value  = setup_for_div_or_mult(dividend);
	std::string diviser = setup_for_div_or_mult(_diviser_);

	/*
		filter against the exceptional cases like : "x%1 , 1%x , ..."
	*/
	
	// x % x = 0
	if (value == diviser) return "0";

	// x % 0 = 0
	if (diviser == "0" || diviser == "-0" || diviser == "0.0" || diviser == "-0.0") return "0";

	// 0 % x = 0
	if (value == "0" || value == "-0" || value == "0.0" || value == "-0.0") return "0";

	// x % 1 = 0
	if (diviser == "1" || diviser == "-1" || diviser == "1.0" || diviser == "-1.0") return "0";

	// small % bigger = small
	if (compare(value, diviser, true) == NUMBER_2_BIGGER) return dividend;

	// end of filtering 

	// using divide function to calculate reminder , because it's have all the bases
	std::string result = div(dividend, _diviser_, true);

	return (dividend[0] == '-' && result[0] != '-') ? '-' + result : result;

}


/*

		assistance functions

*/


// Note : numbers should be reversed by default !!!
short compare(std::string & number1, std::string & number2 , bool reverse_then_compare = false ) {

	if (reverse_then_compare) {
		std::reverse(number1.begin(), number1.end());
		std::reverse(number2.begin(), number2.end());
	}

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

	if (reverse_then_compare) {
		std::reverse(number1.begin(), number1.end());
		std::reverse(number2.begin(), number2.end());
	}


	return state;

} // end of compare function

// function to setup numbers and make them ready for the calculation
void setup_for_add_or_sub(std::string& number1, std::string& number2) {

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

// this function used by div to count how many times "used_number" can fit to "target_number"
std::pair<std::string, std::string> how_much_in(std::string& target_number, std::string& used_number) {

	std::string value   = "";
	std::string repeate = "";

	short comparison = compare(target_number, used_number , true);

	switch (comparison) {

		case NUMBERS_ARE_EQUAL : {
			value   = target_number;
			repeate = "1";
		}
		break;

		case NUMBER_2_BIGGER : {
			value   = "0";
			repeate = "0";
		}
		break;

		case  NUMBER_1_BIGGER: {

			std::string previous_value = used_number;
			value = used_number;

			for (size_t i = 2; ; i++) {

				value = add( value , used_number );
				comparison = compare( value , target_number , true );

				if (comparison == NUMBER_1_BIGGER || comparison == NUMBERS_ARE_EQUAL) {

					value = (comparison == NUMBER_1_BIGGER) ? previous_value : value;
					repeate = std::to_string(((comparison == NUMBER_1_BIGGER) ? i - 1 : i));

					break;
				}
				else previous_value = value;

			}

		} break;

	}

	return std::pair<std::string, std::string>( value , repeate );

} // end of calc_float_position function

// function to remove no needed char's like zero's and - + ...
std::string setup_for_div_or_mult(std::string& target_number , bool remove_sign ) {

	std::string new_str_number = "";

	// check if there's a "float point" in the number 
	bool float_point_found = false;

	for (size_t i = 0; i < target_number.size(); i += 1) {

		if (target_number[i] == '.') {
			float_point_found = true;
			break;
		}

	}

	// first to start filter 'none zero value' , 'float point .' , 'signs - +'

	size_t i = (target_number[0] == '-' || target_number[0] == '+') ? (remove_sign) ? 1 : 0 : 0;

	for ( ; i < (target_number.size() - 1) ; i++) {

		if (target_number[i] == '0') continue;
		else {
			if (target_number[i] == '.' || target_number[i] == '-' || target_number[i] == '+') {
				i -= (i == 0) ? 0 : 1;
			}
			break;
		}

	}

	size_t r = target_number.size() - 1;

	if (float_point_found) {

		// note : only for "float point" numbers !!!
		// this second filter is like the first but it start from last digit

		for (; r > i; r -= 1) {

			if (target_number[r] == '0') continue;
			else {

				if (target_number[r] == '.') {
					r -= 1;
				}

				break;
			}

		}
	}

	// copy values
	for ( ; i <= r ; i++ ) {
		new_str_number.push_back(target_number[i]);
	}

	return new_str_number;
} // end of remove_zeros


// this function used to get rid of float's point and switch numbers to integer's
// because integer's fit well with long division 
void balance_floats( std::string& number1 , std::string& number2 , size_t * catch_balance_factor_for_reminder ) {

	long long int n1_float_index = -1;
	long long int n2_float_index = -1;

	// search for '.' float point 
	for (size_t a = 0; a < number1.size(); a += 1) {

		if (number1[a] == '.') {
			n1_float_index = a;
			break;
		}

	}

	for (size_t a = 0; a < number2.size(); a += 1) {

		if (number2[a] == '.') {
			n2_float_index = a;
			break;
		}

	}
	// end of search 

	n1_float_index = (n1_float_index == -1) ? 0 : number1.size() - n1_float_index - 1;
	n2_float_index = (n2_float_index == -1) ? 0 : number2.size() - n2_float_index - 1;

	size_t range_to_balance = (n1_float_index > n2_float_index) ? n1_float_index : n2_float_index;

	std::string process_number;
	bool start_counting_for_range = false;

	// process number1 
	for (size_t i = 0 ; i < number1.size(); i++) {

		if (number1[i] == '.') {
			start_counting_for_range = true;
			continue;
		}
		
		if (start_counting_for_range) range_to_balance -= 1;

		process_number.push_back( number1[i] );
	}
	for (size_t i = 0; i < range_to_balance; i++) {
		process_number.push_back('0');
	}

	// copy processed result 
	number1 = process_number;

	// clean for number2

	process_number = "";
	start_counting_for_range = false;
	range_to_balance  = (n1_float_index > n2_float_index) ? n1_float_index : n2_float_index;

	// process number2 
	for (size_t i = 0; i < number2.size(); i++) {
		
		if (number2[i] == '.') {
			start_counting_for_range = true;
			continue;
		}

		if (start_counting_for_range) range_to_balance -= 1;

		process_number.push_back(number2[i]);
	}

	if (catch_balance_factor_for_reminder != nullptr) {
		*catch_balance_factor_for_reminder = range_to_balance;
	}

	for (size_t i = 0; i < range_to_balance; i++) {
		process_number.push_back('0');
	}

	// copy processed result 
	number2 = process_number;

} // end of balanc_floats function

bool still_not_zero(std::string const& target_number) {

	for ( size_t i = 0; i < target_number.size(); i++ ) {
		if (target_number[i] != '0' && target_number[i] != '.') return true;
	}

	return false;
}

/*
	recursive function used to compute the "math expression"
	after parsed to binary-tree
*/

std::string execute( node* target_node , std::map<std::string,std::string>* function_parameters ) {

	// compute left and right nodes first
	std::string left_value  = (target_node->left  != nullptr) ? execute(target_node->left , function_parameters) : EMPTY_STRING;
	std::string right_value = (target_node->right != nullptr) ? execute(target_node->right, function_parameters) : EMPTY_STRING;

	// to store computed value
	std::string str_result = EMPTY_STRING;
	
	// decision based on the element type
	switch (target_node->type) {

		case UNDEFINED : {
			
			return EMPTY_STRING;

		} break;

		case OPERATOR : {

			// if empty vs value = value
			if (left_value  == EMPTY_STRING) return right_value;
			if (right_value == EMPTY_STRING) return left_value;

			if (target_node->value == "+") {
				return add(left_value, right_value);
			}

			if (target_node->value == "-") {
				return sub(left_value, right_value);
			}

			if (target_node->value == "*") {
				return mult(left_value, right_value);
			}

			if (target_node->value == "/") {
				return div(left_value, right_value);
			}

			if (target_node->value == "%") {
				return mod(left_value, right_value);
			}

			if (target_node->value == "^") {
				return pow(left_value, right_value);
			}


		} break;

		case INT : {
			return target_node->value;
		} break;

		case FLOAT : {
			return target_node->value;
		} break;

		case VARIABLE : {

			return get_variable( target_node->value );

		} break;


		case FUNCTION : {

			// parsing this function call into call_object "name , {params...}"
			std::pair<std::string, std::vector<std::string>> call_object = parse_function_call(target_node->value);

			// try to fetch the function object from "functions map"
			std::pair<std::string , func> function_object = get_function(call_object.first);

			// in case function not found
			if (function_object.first == "") {
				return EMPTY_STRING;
			}
			else {

				// map/save parameters 
				// param_name : param_value
				std::map<std::string, std::string> parameters;

				// copy parameter_name , parameters_value
				for (size_t i = 0; i < function_object.second.parameters.size(); i += 1) {

					parameters.insert(
						std::pair<std::string, std::string>(
							function_object.second.parameters[i] , 
							(i < call_object.second.size()) ? call_object.second[i] : "0"
						)
					);

				}

				// call function + pass parameters
				return execute( function_object.second.root , &parameters );
				
			}

		} break;

		// todo !!!
		case PARAMETER : {

			if(function_parameters == nullptr) return EMPTY_STRING;
			else {

				std::map<std::string, std::string>::iterator itr_param = function_parameters->find(target_node->value);

				return (itr_param != function_parameters->end()) ? itr_param->second : EMPTY_STRING;
			}

		} break;

	}

	return str_result;

} // end of execute function
