
/*
	declare storage map's as external global 
*/

#ifndef map
	#include <map>
#endif

#ifndef string
	#include <string>
#endif

#ifndef function
	#include "function.cpp"
#endif

#ifndef variables
	#include "variables.cpp"
#endif

// variables map
extern std::map<std::string, var>  variables;

// functions map
extern std::map<std::string, func> functions;