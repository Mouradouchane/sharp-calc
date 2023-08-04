
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

#ifndef _analysing
	#define _analysing
	#include "analysing.cpp"
#endif

#ifndef _parser
	#define _parser
	#include "parser.cpp"
#endif

#define _DEBUG

const char* names[] = {
	"UNDEFINED",
	"INT",
	"UINT",
	"FLOAT",
	"UFLOAT",
	"VARIABLE ",
	"FUNCTION",
	"OPERATOR",
	"PARAMETER"
};

/*
	functions that should be only in debug
*/
#ifdef _DEBUG

static void print_parsed_expression(node& expression_node , size_t tab = 1) {

	if( expression_node.right != nullptr ) print_parsed_expression(*expression_node.right, tab + tab);

	for (size_t i = 1; i <= tab; i++) {
		std::cout << '\t';
	}
	std::cout << names[expression_node.type] << " : " << expression_node.value << '\n';

	if ( expression_node.left  != nullptr ) print_parsed_expression(*expression_node.left , tab + tab);

}

#endif

extern "C" __declspec(dllexport) std::string process_expression(std::string math_expression) {

	// remove space's from expression
	trim_expression(math_expression);

	// check operator's , brackets in the expression
	if (check_expression(math_expression) != VALID_MATH_EXPRESSION) return std::string("");

	// create binary-tree for the expression
	node root( math_expression );

	// start to parse the expression
	parse_expression( root );

	#ifdef _DEBUG
		std::cout << "============== PARSE ===============\n";
		print_parsed_expression(root , 1);
		std::cout << "============== E N D ==================\n";
	#endif

	// todo : computer parsed expression

	// todo : return value
	return std::string("");

} // end of process_expression function


// function to get back a value of variable from the "variables map"
extern "C" __declspec(dllexport) std::string get_variable(std::string var_name) {

	std::map<std::string, var>::iterator container = variables.find(var_name);

	return (container != variables.end()) ? container->second.value : std::string("");

} // end of get_variable function

extern "C" __declspec(dllexport) short create_int(std::string int_name, std::string int_value ) {

	// remove spaces then check 

	trim_expression(int_name);
	if ( is_valid_name(int_name) == INVALID_NAME ) return INVALID_NAME;

	trim_expression(int_value);
	if ( is_int(int_value) == INVALID_VALUE ) return INVALID_VALUE;

	// if "name" and "value" ==> correct
	variables.insert(std::pair<std::string, var> { int_name , var(int_name, int_value, (int_value[0] == '-') ? INT_128 : UINT_128 ) });

	return VALID;

} // end of create_int function


extern "C" __declspec(dllexport) short create_float(std::string float_name, std::string float_value ) {
	
	// remove spaces then check 

	trim_expression(float_name);
	if( is_valid_name(float_name) == INVALID_NAME ) return INVALID_NAME;

	trim_expression(float_value);
	if ( is_float(float_value) == INVALID_VALUE ) return INVALID_VALUE;

	// if "name" and "value" ==> correct
	variables.insert(std::pair<std::string, var> { float_name, var(float_name, float_value, (float_value[0] == '-') ? FLOAT_128 : UFLOAT_128 ) });

	return VALID;

} // end of create_float function


extern "C" __declspec(dllexport) short create_function(
	std::string function_name,
	std::string function_parameters,
	std::string function_expression 
) {

	// check name
	trim_expression(function_name);
	if (is_valid_name(function_name) == INVALID_NAME) return INVALID_NAME;

	func new_function_object;
	new_function_object.name = function_name;

	trim_expression(function_parameters);
	
	if (function_parameters != "") {

		// parse + check parameters
		std::vector<std::string>* parameters = parse_parameters(function_parameters);
	
		if (parameters == nullptr) return INVALID_FUNCTION_PARAMETERS;

		// copy parameters 
		new_function_object.parameters = *parameters;

		// sort parameters 
		std::sort(
			new_function_object.parameters.begin(), new_function_object.parameters.end()
		);

		delete parameters;
	}

	// remove space's from expression 
	trim_expression(function_expression);

	// check operator's , brackets in the function expression
	if (check_expression(function_expression) != VALID_MATH_EXPRESSION) return INVALID_FUNCTION_DEFINITION;

	new_function_object.root = node(function_expression);

	// parse function expression
	parse_expression( new_function_object.root , &new_function_object );

	#ifdef _DEBUG
		std::cout << "============== PARSE ===============\n";
		std::cout << new_function_object.name << '{' << function_parameters << "}\n";
		print_parsed_expression(new_function_object.root, 1);
		std::cout << "============== E N D ==================\n";
	#endif

	functions.insert(std::pair<std::string, func>{ function_name, new_function_object});

	return VALID;

} // end of create_function function