
#ifndef defs
	#include "defs.hpp"
#endif

#ifndef string
	#include <string>
#endif

short operator_level(char const& ch) {

	switch (ch) {

	case '+': case '-': return LEVEL_1;

	case '/': case '%': case '*': case '^': return LEVEL_2;

	case '(': case ')': return LEVEL_3;


	default: return LEVEL_MAX;
	}

}

bool is_operator(char const& ch) {

	switch (ch) {

	case '+': case '-': case '/': case '%': case '*': case '^': {
		return true;
	}

	}

	return false;
}

bool is_variable(std::string const& target_name) {

	if (!isalpha(target_name[0])) return false;

	for (size_t i = 1; i < target_name.size(); i++) {

	}

	return false;
}

bool is_function(std::string const& target_name) {
	return false;
}

bool is_int(std::string const& target_name) {

	int value = 0;
	for (size_t i = 0; i < target_name.size(); i++) {

		value = int(target_name[i] - '0');
		if (value < 0 || value > 9) return false;

	}

	return true;
}

static bool is_float(std::string const& target_name) {

	for (size_t i = 0; i < target_name.size(); i++) {

		if (target_name[i] == '.') {

			return (
				(i > 0) ? is_int(target_name.substr(0, i)) : true
				&&
				(i < target_name.length()) ? is_int(target_name.substr(i + 1, target_name.size() - i)) : true
				);

		}

	}

	return false;
}