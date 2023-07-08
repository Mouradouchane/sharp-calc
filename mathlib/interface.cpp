
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

const char* names[] = {
	"UNDEFINED",
	"INT",
	"UINT",
	"FLOAT",
	"UFLOAT",
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

extern "C" __declspec(dllexport) std::string process_expression(std::string math_expression) {

	expression_info check = check_expression(math_expression);

	if( check.invalid_expression_exception ) return std::string("ERROR:INVALID EXPRESSION");

	node root( math_expression );

	parse_expression( root );

	std::cout << "============== PARSE ===============\n";
	print_parsed_expression(root , 1);
	std::cout << "============== E N D ==================\n";

	return std::string("");
}

extern "C" __declspec(dllexport) bool create_int(std::string int_name, std::string int_value) {

	// check if variable already in map

	auto map_var = variables.find(int_name);

	if ( map_var != variables.end() ) {

		map_var->second.value = int_value;
		return VAILD_NAME;

	}
	
	// integer creation process

	// check name
	for (size_t i = 0; i < int_name.size(); i++) {

		if ( !(std::isalpha(int_name[i])) && int_name[i] != '_' ) return INVALID_NAME;
		
	}
	// then save it 
	variables.insert(std::pair<std::string, var> { int_name , var(int_name, int_value, INT_128) } );

	return VAILD_NAME;
}

extern "C" __declspec(dllexport) bool create_float(std::string float_name, std::string float_value) {
	
	// check variable name

	// store variable if valid
	/*
	var new_float(float_name, float_value, FLOAT_128);
	variables.insert( std::pair<std::string, var> { new_float.name , new_float } );
	*/
	return false;

}

extern "C" __declspec(dllexport) bool create_function(
	std::string function_definition
) {

	// check 
	
	// process and store function
	/*
	func function_object( "def_name" , "x*5+y" , { "y" , "x" } );
	functions.insert( std::pair<std::string, func>{ function_object.name , function_object } );
	*/
	return false;

}