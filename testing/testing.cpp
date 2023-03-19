
#include <iostream>

#define IMPORT 1
#include "../operations/dllmain.hpp"


int main(){

    std::cout << "DLL LOAD TIME =" << operator_test() << '\n';
    std::cout << "DLL LOAD TIME =" << parser_test() << '\n';

    system("pause");

    return 0;
}

