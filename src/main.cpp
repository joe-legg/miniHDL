#include <iostream>
#include "grammar.h"

int main()
{
    Node *ast = parse();
    std::cout << ast->getString() << "\n\n";
    std::cout << ast->codeGen() << "\n";

    return 0;
}
