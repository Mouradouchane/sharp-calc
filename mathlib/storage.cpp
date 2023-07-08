
/*
* 
	file for containing "variables and functions" map's

*/ 

#pragma once

#include "pch.h"

#ifndef function
	#include "function.cpp"
#endif

#ifndef variables
	#include "variables.cpp"
#endif

#ifndef map
	#include <map>
#endif

#ifndef string
	#include <string>
#endif

// variables map
std::map<std::string, var> variables = {};

// functions map
std::map<std::string, func> functions = {};

