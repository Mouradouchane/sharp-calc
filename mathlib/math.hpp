
#pragma once

#ifndef framework
	#include "framework.h"
#endif

// DLL interface 


	/*
		this function is the interface of this library .
		send "math expression" to it and get result back !
	*/

extern "C" __declspec(dllexport) std::string process_expression(std::string math_expression);



	/*
		NOTE !!!!!!!!
		variables is 128 automatically 
	*/


	/*
		function for you to define int's
	*/ 
extern "C" 	__declspec(dllexport) bool create_int(std::string int_name , std::string int_value);


	/*
		function for you to define float's
	*/
extern "C" 	__declspec(dllexport) bool create_float(std::string float_name , std::string float_value);


	/*
		function for you to define function's
	*/
extern "C" __declspec(dllexport) bool create_function( std::string function_definition );