
#pragma once 
#include "pch.h"
#include "framework.h"

/*
std::map<std::string, var>  variables;
std::map<std::string, func> functions;
*/

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

bool is_int(std::string const& target_name) {

	int value = 0;
	for (size_t i = 0; i < target_name.size(); i++) {

		value = int(target_name[i] - '0');
		if (value < 0 || value > 9) return false;

	}

	return true;
}

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