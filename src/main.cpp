#include <iostream>
#include "grammar.h"

int main()
{
    Node *ast = parse();
    std::cout << ast->getString() << "\n";

    return 0;
}
