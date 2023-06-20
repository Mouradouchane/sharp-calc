
#pragma once

#include "pch.h"
#include "node.cpp"
#include "parser.cpp"

static void print_parsed_expression(node& expression_node , size_t tab = 1) {

	if( expression_node.right != nullptr ) print_parsed_expression(*expression_node.right, tab + tab);

	for (size_t i = 1; i <= tab; i++) {
		std::cout << '\t';
	}
	std::cout << expression_node.type << " : " << expression_node.value << '\n';

	if ( expression_node.left  != nullptr ) print_parsed_expression(*expression_node.left , tab + tab);

}

extern "C" __declspec(dllexport) std::string process_expression(std::string math_expression) {

	expression_info check = check_expression(math_expression);

	if( !check.invalid_expression_exception ) return std::string("ERROR:INVALID EXPRESSION");

	node root( math_expression );

	parse_expression( root );

	std::cout << "=================================\n";
	print_parsed_expression(root , 1);
	std::cout << "=================================\n";

	return std::string("");
}

extern "C" __declspec(dllexport) void make_int(std::string int_name, std::string int_value) {

}

extern "C" __declspec(dllexport) void make_float(std::string float_name, std::string float_value) {

}