
#pragma once

#ifndef _framework
	#define _framework
	#include "framework.h"
#endif

#ifndef _defs
	#define _defs
	#include "defs.hpp"
#endif

// DLL interface 


	/*
		this function is the interface of this library .
		send "math expression" to it and get result back !
	*/

extern "C" __declspec(dllexport) std::string process_expression(std::string math_expression);



	/*
		NOTE !!!!!!!!
		variables is 128bit automatically 
	*/


	/*
		function for you to define int's
	*/ 
extern "C" 	__declspec(dllexport) short create_int(std::string int_name , std::string int_value);


	/*
		function for you to define float's
	*/
extern "C" 	__declspec(dllexport) short create_float(std::string float_name , std::string float_value);


	/*
		function for you to define function's
	*/
extern "C" __declspec(dllexport) short create_function(
	std::string function_name,
	std::string function_parameters,
	std::string function_expression
);


	/*
		function for you to get a variable from the "variables map"
	*/
extern "C" __declspec(dllexport) std::string get_variable(std::string var_name);


	/*
		functions used in debug build
	*/

#ifdef _DEBUG

extern "C" __declspec(dllexport) std::string debug_add(std::string a, std::string b); // a + b

extern "C" __declspec(dllexport) std::string debug_sub(std::string a, std::string b); // a - b

extern "C" __declspec(dllexport) std::string debug_mult(std::string a, std::string b); // a * b

extern "C" __declspec(dllexport) std::string debug_div(std::string a, std::string b); // a / b

extern "C" __declspec(dllexport) std::string debug_mod(std::string a, std::string b); // a % b

extern "C" __declspec(dllexport) std::string debug_pow(std::string a, std::string b); // a ** b

#endif 