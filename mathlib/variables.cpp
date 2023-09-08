
#pragma once

#include "pch.h"

#ifndef string
	#include <string>
#endif

#ifndef defs
	#include "defs.hpp"
#endif

class var {

public:

	std::string name  = "";
	std::string value = "";

	short type = _INT_; // value type 'int | float"

	// constructors 

	var(){}

	var( std::string var_name , std::string var_value = "" , short var_type = _INT_ ) {

		this->name  = var_name;
		this->value = var_value;
		this->type  = var_type;

	}

	// destructors

	~var() {

	}


}; // end of class var