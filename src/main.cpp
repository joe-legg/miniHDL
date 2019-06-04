#include <iostream>
#include "parser.h"

int main()
{
    auto ast = parse("test.minihdl");
    std::cout << ast->getString() << "\n";
    delete ast;
}
