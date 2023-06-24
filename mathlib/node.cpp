
#pragma once

#include "pch.h"

#ifndef string
	#include <string>
#endif

#ifndef defs
	#include "defs.hpp"
#endif

/*
	NOTE !!!!!
	this class node for representing/parsing "math expressions" to binary-tree
*/

class node {

	public :

		bool is_empty = true;

		// type of this value : expression/operator/value/variable...
		short type = UNDEFINED; 

		std::string value = "";

		node* left  = nullptr; 
		node* right = nullptr;

		// constructor's

		node() { }

		node(std::string const& math_expression , short const& expression_type ) {

			this->is_empty = false;
			this->value = math_expression;
			this->type  = expression_type;
		}

		node(std::string const& math_expression) {

			this->is_empty = false;
			this->value = math_expression;

		}

		// destructor
		~node() {

			if (this->left != nullptr) this->left->~node();
			if (this->right != nullptr) this->right->~node();

		}

}; // end of class node