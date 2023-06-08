
#pragma once

#include "pch.h"

#ifndef node
	#include "node.cpp"
#endif

static short operator_level(char const& ch) {

	switch (ch) {

		case '+': case '-': return 1;
	
		case '/': case '%': case '*': case '^': return 2;
	
		case '(': case ')': return 3;
	

		default: return 6;

	}

}

static bool is_operator( char const& ch ) {

	switch (ch) {

		case '+': case '-': {
			return true;
		}

		case '/': case '%': case '*': case '^' : {
			return true;
		} 

		case '(': case ')': {
			return true;
		}

	}

	return false;
}


static bool is_valid_expression(std::string const& math_expression) {

	int32_t balance = 0;
	bool last_char_operator = false;

	for (uint32_t i = 0; i < math_expression.size(); i++) {

		if (math_expression[i] == '(') {
			balance++;
			continue;
		}

		if (math_expression[i] == ')') {
			balance--;
			continue;
		}

	}

	return (balance == 0) ? true : false;

}

static void parse_expression( node& expression_node ) {
	
	short  last_op_level = 6;
	size_t last_op_index = 0;

	short current_op_level = 6;
	for (size_t i = 0; i < expression_node.value.size(); i++ ) {

		current_op_level = operator_level(expression_node.value[i]);

		if ( current_op_level <= last_op_level ) {
			last_op_level = current_op_level;
			last_op_index = i;
		}

	}

}

