#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#pragma once

// Windows Header Files
#include <iostream>
#include <windows.h>
#include <wtypes.h>
#include <string>
#include <vector>
//#include <oleauto.h>

#ifndef algorithm
	#include <algorithm>
#endif

#ifndef defs
	#include "defs.hpp"
#endif

#ifndef map
	#include <map>
#endif

#ifndef node
	#include "node.cpp"
#endif

#ifndef function
	#include "function.cpp"
#endif

#ifndef variables
	#include "variables.cpp"
#endif

#ifndef storage
	#include "storage.hpp"
#endif