#include "ast.hpp"
#include <iostream>

void printAST(Node *baseNode)
{
    std::cout << baseNode->getString();
}

// Get string methods
std::string Node::getString()
{
    return "Node \n";
}

std::string ExpressionNode::getString()
{
    return "Expression \n";
}

std::string BitNode::getString()
{
    std::string str = "Bit. Value : ";
    str += value ? "1\n" : "0\n";
    return str;
}

std::string BinaryOperatorNode::getString()
{
    return left.getString() + operation + right.getString() + "\n";
}

std::string IdentifierNode::getString()
{
    return ident + "\n";
}

std::string StatementNode::getString()
{
    return "Statement \n";
}

std::string BlockNode::getString()
{
    std::string str;
    for (long unsigned int i = 0; i < statements.size(); i++)
        str += statements[i]->getString();
    return str + "\n";
}

std::string ExpressionStatementNode::getString()
{
    return expr.getString() + "\n";
}
