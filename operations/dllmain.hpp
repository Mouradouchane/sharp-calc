
#pragma once

#define TYPE LPWSTR

// extern "C" __declspec(dllexport) TYPE parse_expression( TYPE );

extern "C" __declspec(dllexport) void parse_expression( TYPE& str_exp ) {

	str_exp[0] = L'M';
	str_exp[1] = L'M';
	str_exp[2] = L'M';

	// return expression_string_lenght;

}
