
#pragma once

#ifndef framework
	#include "framework.h"
#endif

// DLL interface 

extern "C" {

	/*
		this function is the interface of this library .
		send "math expression" to it and get result back !
	*/
	__declspec(dllexport) std::string process_expression(std::string math_expression);



	/*
		NOTE !!!!!!!!
		the size of the variable gonna be defined by the library automaticlly 
		depened on the size of the value 
	*/

	/*
		function for you to define int's
	*/ 
	__declspec(dllexport) void make_int(std::string int_name , std::string int_value);

	/*
		function for you to define float's
	*/
	__declspec(dllexport) void make_float(std::string float_name , std::string float_value);

}