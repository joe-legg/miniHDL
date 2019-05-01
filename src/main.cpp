#include "parser.hpp"

int main()
{
    Node *ast = parse();
    printAST(ast);

    return 0;
}
