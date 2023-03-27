
#pragma once

#define TYPE char

// DLL interface 

extern "C" __declspec(dllexport) void parse_expression(std::string expression_str);
