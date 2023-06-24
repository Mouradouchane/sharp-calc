
#pragma once

#include "pch.h"

#ifndef node
	#include "node.cpp"
#endif


#ifndef defs
	#include "defs.hpp"
#endif

// simple structure who hold a few information about "math_expressions" 
struct expression_info {
	
	public : 

		// exceptions ==============================
		bool invalid_expression_exception	= false;
		bool bracket_bracket_exception		= false;
		bool operator_operator_exception	= false;
		bool undefined_exception			= false;
		bool divison_by_zero				= false;

		// info ====================================
		bool contain_subexpressions			= false;
		bool contain_variables				= false;
		bool contain_functions				= false;

};

static short operator_level(char const& ch) {

	switch (ch) {

		case '+': case '-': return LEVEL_1;
	
		case '/': case '%': case '*': case '^': return LEVEL_2;
	
		case '(': case ')': return LEVEL_3;
	

		default: return LEVEL_MAX;
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

	if ( !isalpha(target_name[0]) ) return false;

	for( size_t i = 1 ; i < target_name.size() ; i++ ){
		
	}

	return false;
}

static bool is_function(std::string const& target_name) {
	return false;
}

static bool is_int(std::string const& target_name ) {

	int value = 0;
	for (size_t i = 0; i < target_name.size(); i++) {

		value = int( target_name[i] - '0' );
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

static short define_this(std::string const& undefined_value) {

	if (is_operator(undefined_value[0]))return OPERATOR;
	if (is_int(undefined_value))		return INT;
	if (is_float(undefined_value))		return FLOAT;
	if (is_variable(undefined_value))	return VARIABLE;
	if (is_function(undefined_value))	return FUNCTION;

	return UNDEFINED;
	return UNDEFINED;
}

/*
	function for check/analyse math expression before starting operations
*/
static expression_info check_expression( std::string const& math_expression ) {
	
	expression_info result;

	// to keep track the brackets balance to see if the expression is valid or not
	int32_t expression_brackets_balance = 0;
	int32_t functions_brackets_balance = 0;

	// to get the start/end index of something between operators in expression
	size_t start = 0;
	size_t end = 0;

	for (uint32_t i = 0; i < math_expression.size(); i++) {

		// sub expression enter
		if (math_expression[i] == '(') {
			expression_brackets_balance++;
		}


		// sub expression leave
		if (math_expression[i] == ')') {

			expression_brackets_balance--;

			// if ) followed by ( that's mean invalid expression
			if (math_expression[i + 1] == '(') {
				result.invalid_expression_exception = true;
				result.bracket_bracket_exception = true;
				return result;
			}

		}

		// function enter
		if (math_expression[i] == '{') {
			functions_brackets_balance++;
		}

		// function leave
		if (math_expression[i] == '}') {
			functions_brackets_balance--;

			if (math_expression[i + 1] == '{') {
				result.invalid_expression_exception = true;
				result.bracket_bracket_exception = true;
				return result;
			}

		}

		// if operator followed by operator or operator followed by ')' that's mean "invalid expression" 
		if ( 
			is_operator(math_expression[i]) && 
			( is_operator(math_expression[i + 1]) | math_expression[i + 1] == ')' )
		) {

			result.invalid_expression_exception = true;
			result.operator_operator_exception  = true;

			return result;
		}

		if ( 
			is_operator(math_expression[i]) || math_expression[i] == '(' || math_expression[i] == ')'
		) {
			end = i - 1;

			// check for undefined's 

			std::string str = math_expression.substr( start , ( end - start ) + 1);

			short type = define_this(str);

			if (type == UNDEFINED) {
				result.invalid_expression_exception = true;
				result.undefined_exception = true;

				return result;
			}

			if (type == VARIABLE) result.contain_variables = true;
			if (type == FUNCTION) result.contain_functions = true;
			
			start = i + 1;
		}

	}

	// brackets_balance == 0 : mean expression is "valid/balanced" on brackets level
	if ( expression_brackets_balance != 0 || functions_brackets_balance != 0 ) {
		result.invalid_expression_exception = true;
		result.bracket_bracket_exception = true;
	}

	return result;

} // end of check_expression function


static void pass_sub_expression( std::string & expression , size_t & index ) {

	INT32 balance = 1;

	index += 1;
	for (		; index < expression.size() ; index += 1 ) {

		if (expression[index] == '(') balance++ ;

		if (expression[index] == ')') {
			balance-- ;

			// balance == 0 with ')' mean we find the end of this sub-expression
			if (balance == 0) {
				index += 1;
				return;
			}
		}

	}

} // end of pass_sub_expression function


static void parse_expression( node& expression_node ) {

	bool preforme_parse = false;

	// to keep track the last low operator precedence
	short  last_op_level = 4;
	size_t last_op_index = 0;

	// search for last low operator to parse depend on it
	short current_op_level = 6;
	for (size_t i = 0; i < expression_node.value.size(); i++ ) {

		if ( expression_node.value[i] == '(' ) {
			bool all_inside = ( i == 0 ) ? true : false;

			pass_sub_expression(expression_node.value , i);

			if (i == expression_node.value.length() && all_inside) {
				expression_node.value = expression_node.value.substr(
					1, expression_node.value.length() - 2
				);

				parse_expression(expression_node);
				return;
			}

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
			(last_op_index > 0) ? expression_node.value.substr(0, last_op_index ) : "0" ,
			(last_op_index > 0) ? UNDEFINED : INT
		);


		expression_node.right = new node( 
			(last_op_index < expression_node.value.length()) ? expression_node.value.substr( 
				last_op_index + 1 , expression_node.value.size() - last_op_index 
			) : "0" ,
			(last_op_index > 0) ? UNDEFINED : INT
		);

		// update current value at the current node
		expression_node.value = expression_node.value[last_op_index];
		
		/*
			after parsing the expression into tow sub_expressions
			now we preforme "parse+check" for both new "sub_expressions"
		*/
		if( expression_node.left  != nullptr ) parse_expression( *expression_node.left );
		if( expression_node.right != nullptr ) parse_expression( *expression_node.right );

	}

		// try to identifiy the current value in this node "int,float,variable,...."
		expression_node.type = define_this(expression_node.value);


} // end of parse_expressionn function

