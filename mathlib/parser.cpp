
#pragma once

#include "pch.h"

#ifndef node
	#include "node.cpp"
#endif

// simple structure who hold a few information about "math_expressions" 
struct expression_info {
	
	public : 
		bool is_valid = false;
		bool is_it_bracket_expression = false;

		bool is_contain_subexpressions = false;
		bool is_contain_variables = false;
		bool is_contain_functions = false;

		bool is_something_undefined = false;
		bool operator_operator = false;

};

static short operator_level(char const& ch) {

	switch (ch) {

		case '+': case '-': return 1;
	
		case '/': case '%': case '*': case '^': return 2;
	
		case '(': case ')': return 3;
	

		default: return 9;
	}

}

static bool is_operator(char const& ch) {

	switch (ch) {

		case '+': case '-': case '/': case '%': case '*': case '^': {
			return true;
		}

	}

	return false;
}

static bool is_variable(std::string const& target_name) {
	return false;
}

static bool is_function(std::string const& target_name) {
	return false;
}

static bool is_int(std::string const& target_name ) {
	return false;
}

static bool is_float(std::string const& target_name) {
	return false;
}

static std::string define_this(std::string const& undefiend_value) {

	if (is_variable(undefiend_value))	return std::string("variable");
	if (is_function(undefiend_value))	return std::string("function");
	if (is_int(undefiend_value))		return std::string("int");
	if (is_float(undefiend_value))		return std::string("float");
	if (is_operator(undefiend_value[0]))return std::string("operator");

	return std::string("undefined");
}

/*
	function for check/analyse math expression before starting operations
*/
static expression_info check_expression( std::string const& math_expression ) {
	
	expression_info result;

	// for keep track the brackets balance to see if the expression is valid or not
	int32_t brackets_balance = 0;

	// to get the start/end index of something between operators in expression
	size_t start = 0;
	size_t end = 0;

	for (uint32_t i = 0; i < math_expression.size(); i++) {

		// sub expression enter
		if (math_expression[i] == '(') {
			brackets_balance++;
		}

		// sub expression leave
		if (math_expression[i] == ')') {
			brackets_balance--;
		}

		// if operator followed by operator or operator followed by ')' that's mean "invalid expression" 
		if ( 
			is_operator(math_expression[i]) && 
			( is_operator(math_expression[i-1]) | math_expression[i + 1] == ')' )
		) {

			result.is_valid = false;
			result.operator_operator = true;

			return result;
		}

		if ( 
			is_operator(math_expression[i]) || math_expression[i] == '(' || math_expression[i] == ')'
		) {
			end = i - 1;

			// todo : check what's in between "start & end"
			std::string str = math_expression.substr( start , ( end - start ) + 1);

			// todo : check for undefined's


			start = i + 1;
		}

	}

	//  brackets_balance == 0 : mean this expression is valid/balanced on brackets level
	if (brackets_balance == 0) result.is_valid = true;

	return result;

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

	bool preforme_parse = false;

	// to keep track the last low operator precedence
	short  last_op_level = 4;
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

			preforme_parse = true;
		}

	}

	// parse the expression based on the last lowest operator found
	if (preforme_parse) {

		expression_node.left  = new node(
			expression_node.value.substr(0, last_op_index )
		);

		expression_node.right = new node( 
			expression_node.value.substr( last_op_index + 1 , expression_node.value.size() - last_op_index ) 
		);

		expression_node.value = expression_node.value[last_op_index];
		expression_node.type  = define_this( expression_node.value );

		/*
			after this parsing expression into tow parts
			go parse those new "sub expressions"
		*/
		parse_expression( *expression_node.left  );
		parse_expression( *expression_node.right );

	}

}

