
#pragma once

#include "pch.h"
#include "framework.h"

/*
#ifndef _storage 
	#define _storage 
	#include "storage.hpp"
#endif
*/

#ifndef _node 
	#define _node 
	#include "node.cpp"
#endif

#ifndef _analysing
	#define _analysing 
	#include "analysing.cpp"
#endif

// simple structure who hold a few information about "math_expressions" 
class expression_info {
	
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

/*
	function that use multiple functions from "analysing.cpp" 
	to identify the shape of the value in string
*/
static short define_this(std::string const& undefined_value , func * function = nullptr ) {

	if ( is_operator(undefined_value[0]) )				return OPERATOR;
	if ( is_int(undefined_value)   == VALID_VALUE)		return INT;
	if ( is_float(undefined_value) == VALID_VALUE)		return FLOAT;
	if ( is_function(undefined_value) == FOUND )		return FUNCTION;

	if (function != nullptr) {

		if (std::binary_search(function->parameters.begin(), function->parameters.end(), undefined_value)) {
			return PARAMETER;
		}

	}

	if ( is_variable(undefined_value) == FOUND )	return VARIABLE;

	return UNDEFINED;
}

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


// function to remove space from "math expression"
void trim_expression( std::string & math_expression ) {
	
	math_expression.erase(
		std::remove_if(math_expression.begin(), math_expression.end() , std::isspace),
		math_expression.end()
	);

} // end of trim_expression function


/*
	function for "check/analyse" the "math expression" to make sure that
	everything is ok "before start parsing or operate" on it .
*/
expression_info check_expression( std::string const& math_expression , func * function = nullptr) {
	
	expression_info result;

	// to keep track the brackets balance to see if the expression is valid or not
	int32_t expression_brackets_balance = 0;
	int32_t functions_brackets_balance = 0;

	// to get the start/end index of something between operators in expression
	size_t start = 0;
	size_t end = 0;
	bool check_range = false;

	for (uint32_t i = 0; i < math_expression.size(); i++) {

		// sub expression enter
		if (math_expression[i] == '(') {

			expression_brackets_balance++;
			check_range = true;
		}

		// sub expression leave
		if (math_expression[i] == ')') {

			expression_brackets_balance--;
			check_range = true;

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
			check_range = true;
		}

		// function leave
		if (math_expression[i] == '}') {

			functions_brackets_balance--;
			check_range = true;

			// if } followed by { that's mean invalid expression
			if (math_expression[i + 1] == '{') {
				result.invalid_expression_exception = true;
				result.bracket_bracket_exception = true;
				return result;
			}

		}

		// if operator followed by operator or operator followed by ')' that's mean "invalid expression" 
		if ( 
			is_operator(math_expression[i]) && 
			( is_operator(math_expression[i + 1] ) | (math_expression[i + 1] == ')') )
		) {

			result.invalid_expression_exception = true;
			result.operator_operator_exception  = true;

			return result;
		}

		if ( is_operator(math_expression[i]) || check_range || i == (math_expression.size() - 1) ) {

			if (i == (math_expression.size() - 1)) end = (i - start) + 1;
			else end = (i - start);

			// take a copy of that sub expression in that range 
			std::string sub_expression = math_expression.substr( start , end );

			if (sub_expression != "") {
				// check and try to define what that "sub expression" is !!!
				short type = define_this(sub_expression, function);

				// if that "sub expression" is undefined that mean the hole math expression are "invalid"
				if (type == UNDEFINED) {
					result.invalid_expression_exception = true;
					result.undefined_exception = true;

					return result;
				}

				if (type == VARIABLE)  result.contain_variables = true;
				if (type == FUNCTION)  result.contain_functions = true;

			}

			start = i + 1;
		}

		check_range = false;
	}

	// brackets_balance not equal to zero , mean this expression not a valid expression
	if ( expression_brackets_balance != 0 || functions_brackets_balance != 0 ) {
		result.invalid_expression_exception = true;
		result.bracket_bracket_exception = true;
	}

	return result;

} // end of check_expression function

/*
	function take a parameters of function "x,y,z,..." and parse them into vector
	NOTE : function return pointer to *vector in heap*
*/
std::vector<std::string>* parse_parameters( std::string & parameters_as_string ) {

	std::vector<std::string> * parameters = new std::vector<std::string>();
	
	size_t s = 0;
	for (size_t i = 0 ; i < parameters_as_string.size(); i++) {

		if ( parameters_as_string[i] == ',' || i == (parameters_as_string.size() - 1) ) {
			parameters->push_back( 
				parameters_as_string.substr( s , i-s + (i == (parameters_as_string.size() - 1) ? 1 : 0) )
			);
			s = i+1;

			// if parameter name invalid 
			if ( is_valid_name( *parameters->rbegin() ) == INVALID_NAME ) {
				delete parameters;
				return nullptr;
			}

		}

	}

	return parameters;
}

void parse_expression( node& expression_node , func * function = nullptr ) {

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

				parse_expression(expression_node , function);
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
		if( expression_node.left  != nullptr ) parse_expression( *expression_node.left  , function);
		if( expression_node.right != nullptr ) parse_expression( *expression_node.right , function);

	}

		// try to identifiy the current value in this node "int,float,variable,...."
		expression_node.type = define_this(expression_node.value , function);


} // end of parse_expressionn function

