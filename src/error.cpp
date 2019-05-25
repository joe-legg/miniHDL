#include "error.hpp"
#include <iostream>

void error(std::string msg)
{
    std::cout << "\033[31m" << msg << "\033[39;49m\n";
}
