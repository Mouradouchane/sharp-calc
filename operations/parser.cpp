
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

static void get_sub_expression_end( std::string & expression , size_t & index ) {

	INT32 balance = 1;

	index += 1;
	for (		; index < expression.size() ; index += 1 ) {

		if (expression[index] == '(') balance++ ;

		if (expression[index] == ')') {
			balance-- ;

			// balance == 0 with ')' mean we find the end of this sub-expression
			if ( balance == 0 ) break; 
		}

	}

}

static void parse_expression( node& expression_node ) {
	
	// to keep track the last low operator precedence
	short  last_op_level = 6;
	size_t last_op_index = 0;

	// search for last low operator to parse depend on it
	short current_op_level = 6;
	for (size_t i = 0; i < expression_node.value.size(); i++ ) {

		if ( expression_node.value[i] == '(' ) {

			get_sub_expression_end(expression_node.value , i);

		}

		current_op_level = operator_level(expression_node.value[i]);

		if ( current_op_level <= last_op_level ) {
			last_op_level = current_op_level;
			last_op_index = i;
		}


	}

	// parse the expression based on the last lowest operator found


	// mark this node with 


	// go to left and right nodes


}

