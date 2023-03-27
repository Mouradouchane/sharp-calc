
#pragma once

#include "pch.h"

bool static is_operator(char& ch) {

	switch (ch) {

	case '+': return true;
	case '-': return true;
	case '/': return true;
	case '%': return true;
	case '*': return true;

	}

	return false;
}

class expression {

	public:
		std::string str;

		expression(std::string math_expression_as_string) {

			this->str = std::string(math_expression_as_string);

		}

		expression(const char* math_expression_as_cstring) {
			this->str = math_expression_as_cstring;
		}

		expression() {

		}

	/*
	static bool is_valid_expression(expression const& expression_object);
	static void parse_expression(expression& expression_object);
	*/

	static bool is_valid_expression(expression const& expression_object) {

		int32_t balance = 0;

		for (uint32_t i = 0; i < expression_object.str.size(); i++) {

			if (expression_object.str[i] == '(') {
				balance++;
				continue;
			}

			if (expression_object.str[i] == ')') {
				balance--;
				continue;
			}

		}

		return (balance == 0) ? true : false;

	}

	static void parse_expression(expression& expression_object) {

		std::vector< std::string > sub_expressions;

		long int balance = 0;
		size_t s = 0;

		// parsing 
		for (size_t i = 1; i < expression_object.str.size(); i++) {

			// keep track of ( ) for ideal parsing

			if (expression_object.str[i] == '(') {
				balance++;
				continue;
			}

			if (expression_object.str[i] == ')') {
				balance--;
				continue;
			}

			if (balance == 0 && is_operator(expression_object.str[i])) {
				sub_expressions.push_back(
					expression_object.str.substr(s, i - s)
				);
				s = i;
			}

		}

		sub_expressions.push_back(
			expression_object.str.substr(s, expression_object.str.size() - s)
		);

		for (std::string& exp : sub_expressions) {

			std::cout << exp << '\n';

		}

	}
};


