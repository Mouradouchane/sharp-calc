
#pragma once

#define DEBUG

#include "pch.h"

#ifndef node
	#include "node.cpp"
#endif

#ifndef parser
	#include "parser.cpp"
#endif

#ifndef storage
	#include "storage.hpp"
#endif

// where the variables and functions get stored
extern std::map<std::string, std::string> variables;
extern std::map<std::string, std::string> functions;


#ifdef DEBUG 

const char* names[] = {
	"UNDEFINED",
	"INT",
	"FLOAT",
	"VARIABLE ",
	"FUNCTION",
	"OPERATOR"
};

// function for debug/check's only 
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

	expression_info check = check_expression(math_expression);

	if( check.invalid_expression_exception ) return std::string("ERROR:INVALID EXPRESSION");

	node root( math_expression );

	parse_expression( root );

	#ifdef DEBUG

		std::cout << "=================================\n";
		print_parsed_expression(root , 1);
		std::cout << "=================================\n";

	#endif 

	return std::string("");
}

extern "C" __declspec(dllexport) void make_int(std::string int_name, std::string int_value) {

	// check variable name

	// store variable if valid
	variables.insert(int_name, int_value);

}

extern "C" __declspec(dllexport) void make_float(std::string float_name, std::string float_value) {
	
	// check variable name

	// store variable if valid
	variables.insert(float_name, float_value);

}

extern "C" __declspec(dllexport) void make_function(
	std::string function_name , 
	std::string function_expression 
) {

	// check function name

	// store function if valid
	functions.insert(function_name, function_expression);

}