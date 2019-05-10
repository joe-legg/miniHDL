#include <iostream>
#include "parser.hpp"

int main()
{
    Node *ast = parse();
    std::cout << ast->getString() << "\n";

    return 0;
}
