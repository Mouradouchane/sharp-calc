
#pragma once

#ifndef string
	#include <string>
#endif


/*
	NOTE !!!!!
	this class node for representing/parsing "math expressions" to binary-tree
*/

class node {

	public :

		bool is_empty = true;

		// type of this value : expression/operator/value/variable...
		std::string type = "undefiend"; 

		std::string value = "";

		node* left  = nullptr; 
		node* right = nullptr;

		// constructor's

		node() { }

		node(std::string& math_expression) {

			this->is_empty = false;
			this->value = math_expression;

		}


		// destructor
		~node() {

			if (this->left != nullptr) this->left->~node();
			if (this->right != nullptr) this->right->~node();

		}

}; // end of class node