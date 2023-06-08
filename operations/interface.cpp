
#pragma once

#include "pch.h"
#include "node.cpp"
#include "parser.cpp"

std::string process_expression(std::string math_expression) {


	if( ! is_valid_expression( math_expression ) ) return std::string("ERROR:INVALID EXPRESSION !");

	node root( math_expression );

	parse_expression( root );

}

void make_int(std::string int_name, std::string int_value) {

}

void make_float(std::string float_name, std::string float_value) {

}