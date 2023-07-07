
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

	short type = INT_128; // type of the value in this variable

	// constructors 

	var(){}

	var( std::string var_name , std::string var_value = "" , short var_type = INT_128 ) {

		this->name  = var_name;
		this->value = var_value;
		this->type  = var_type;

	}

	// desturctors
	~var() {

	}

};