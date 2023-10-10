
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

#ifndef _function
	#define _function
	#include "function.cpp"
#endif

#ifndef _variables
	#define _variables
	#include "variables.cpp"
#endif


short operator_level(char const& ch) {

	switch (ch) {

		case '+': case '-': return LEVEL_1;

		case '/': case '%': case '*': return LEVEL_2;

		case '^': return LEVEL_3;

		case '(': case ')': return LEVEL_4;


		default: return LEVEL_MAX;
	}

}

bool is_operator(char const& ch) {

	switch (ch) {

		case '+': case '-': case '/': case '%': case '*': case '^': {
			return true;
		}

	}

	return false;
}

short is_variable(std::string const& target_name) {

	// search in variables map 
	return (variables.count(target_name) > 0 ) ? FOUND : VAR_NOT_FOUND;
}

short is_function(std::string const& target_name) {

	// search in functions map 
	std::string extracted_name = "";

	for ( char c : target_name ) {

		if (c == '{') break;
		
		extracted_name += c;
	}

	std::map<std::string, func>::iterator function_itr = functions.find(extracted_name);

	return ( function_itr != functions.end() ) ? FOUND : FUNCTION_NOT_FOUND;

}

// to check if target_value is a valid integer value or not
short is_int(std::string const& target_value) {

	int value = int(target_value[0] - '0');

	if ( ( value < 0 || value > 9 ) && ( target_value[0] != '-' && target_value[0] != '+') ) {

		return INVALID_VALUE;
	}

	for (size_t i = 1; i < target_value.size(); i++) {

		value = int(target_value[i] - '0');
		if (value < 0 || value > 9) return INVALID_VALUE;

	}

	return VALID_VALUE;
}

// to check if target_value is a valid float value or not
short is_float(std::string const& target_value) {

	for (size_t i = 0; i < target_value.size(); i++) {

		if (target_value[i] == '.') {

			if (i == 0) 
				return is_int( target_value.substr(1 , target_value.size() - 1) );

			if (i == (target_value.size() - 1))
				return is_int( target_value.substr(0 , target_value.size() - 1) );

			return (
				is_int(target_value.substr(0, i)) == VALID_VALUE
				&&
				is_int(target_value.substr(i + 1, target_value.size() - i)) == VALID_VALUE
				) ? VALID_VALUE : INVALID_VALUE;

		}

	}

	return INVALID_VALUE;
}

short is_valid_name(std::string const& target_name) {

	for (size_t i = 0; i < target_name.size(); i++) {

		if (!(std::isalpha(target_name[i])) && target_name[i] != '_') return INVALID_NAME;

	}

	return VALID_NAME;
}


short check_expression(std::string const& expression) {

	bool in_the_edge = false;
	size_t expression_brackets_balance = 0;
	size_t function_brackets_balance = 0;

	for (size_t i = 0; i < expression.size(); i++) {

		in_the_edge = (i == 0 || i == (expression.size() - 1) ) ? true : false;

		if ( is_operator(expression[i]) ) {

			if ( i != 0 && is_operator(expression[i - 1]) ) return OPERATOR_OPERATOR_EXCEPTION;
			else continue;

		}

		if ( expression[i] == '(' ) {

			if (!in_the_edge) {

				if ( expression[i - 1] == ')' ) return BRACKET_BRACKET_EXCEPTION;

				// if ( is_operator(expression[i + 1]) ) return BRACKET_OPERATOR_EXCEPTION;

			}

			expression_brackets_balance++;
			continue;
		}

		if ( expression[i] == ')' ) {

			if ( !in_the_edge ) {

				if ( is_operator(expression[i - 1]) ) return BRACKET_OPERATOR_EXCEPTION;

				if (expression[i + 1] == '(') return BRACKET_BRACKET_EXCEPTION;

			}

			expression_brackets_balance--;
			continue;
		}

		if (expression[i] == '{') {

			if (!in_the_edge) {

				if (
					is_operator(expression[i - 1]) || is_operator(expression[i + 1])
				) 
				return BRACKET_OPERATOR_EXCEPTION;

			}
			
			function_brackets_balance++;
			continue;
		}

		if (expression[i] == '}') {

			if (!in_the_edge) {

				if (is_operator(expression[i - 1])) return BRACKET_OPERATOR_EXCEPTION;

				if (expression[i + 1] == '(') return BRACKET_BRACKET_EXCEPTION;

			}

			function_brackets_balance++;
			continue;
		}

	}

	return ( (expression_brackets_balance == 0 && expression_brackets_balance == 0) ? VALID_MATH_EXPRESSION : UNBALANCED_BRACKETS_EXCEPTION );

} // end of check_expression function