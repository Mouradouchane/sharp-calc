
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

		case '/': case '%': case '*': case '^': return LEVEL_2;

		case '(': case ')': return LEVEL_3;


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

bool is_variable(std::string const& target_name) {

	// search in variables map 
	return (variables.count(target_name) > 0 ) ? FOUND : VAR_NOT_FOUND;
}

bool is_function(std::string const& target_name) {

	// search in functions map 
	return ( functions.count( target_name ) > 0) ? FOUND : FUNCTION_NOT_FOUND;

}

// to check if target_value is a valid integer value or not
bool is_int(std::string const& target_value) {

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
static bool is_float(std::string const& target_name) {

	for (size_t i = 0; i < target_name.size(); i++) {

		if (target_name[i] == '.') {

			return (
				(i > 0) ? is_int(target_name.substr(0, i)) : true
				&&
				(i < target_name.length()) ? is_int(target_name.substr(i + 1, target_name.size() - i)) : true
			);

		}

	}

	return false;
}

bool is_valid_name(std::string const& target_name) {

	for (size_t i = 0; i < target_name.size(); i++) {

		if (!(std::isalpha(target_name[i])) && target_name[i] != '_') return INVALID_NAME;

	}

	return VALID_NAME;
}