
#pragma once

#if EXPORT

	extern "C" __declspec(dllexport) int parser_test();

	extern "C" __declspec(dllexport) int operator_test();

#endif

#if IMPORT 

	extern "C" __declspec(dllimport) int parser_test();

	extern "C" __declspec(dllimport) int operator_test();

#endif