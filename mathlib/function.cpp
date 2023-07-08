
#pragma once 
#include "pch.h"

#ifndef algorithm
	#include <algorithm>
#endif

#ifndef string
	#include <string>
#endif

#ifndef vector
	#include <vector>
#endif

/*

	class for contain function as an object => name , params , expression ...

*/

// function syntax example => fn_name{ param_a , param_b } = param_a * 2 + param_b

class func {

public :

	std::string name = "";
	std::string expression = "";
	std::vector<std::string> parameters = {};

	// constructors

	func() { }

	func(
		std::string const& fn_name, 
		std::string const& fn_expression, 
		std::initializer_list<std::string> const& fn_parameters
	) {

		this->name = fn_name;
		this->expression = fn_expression;
		
		// copy parameters
		for (std::string parameter : fn_parameters ) {
			this->parameters.push_back(parameter);
		}

		// sort parameters 
		std::sort(
			this->parameters.begin(), this->parameters.end()
		);

	}

	// destructor's
	~func() {

	}

}; // end of class function