
#pragma once

#include "pch.h"
#include "node.cpp"
#include "parser.cpp"

std::string process_expression(std::string math_expression) {

	expression_info check = check_expression(math_expression);

	if( !check.is_valid ) return std::string("ERROR:INVALID EXPRESSION !");

	node root( math_expression );

	parse_expression( root );

}

void make_int(std::string int_name, std::string int_value) {

}

void make_float(std::string float_name, std::string float_value) {

}