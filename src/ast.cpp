#include "ast.hpp"
#include <iostream>

// Get string methods

std::string Node::getString()
{
    return "Node\n";
}

std::string ExpressionNode::getString()
{
    return "Expression\n";
}

std::string BoolNode::getString()
{
    std::string str = "Bit: ";
    str += value ? "1" : "0";
    return str;
}

std::string BinaryOperationNode::getString()
{
    return "Binary Operation: {" + left.getString() + " Operator: " + operation
            + " " + right.getString() + "}";
}

std::string UnaryOperationNode::getString()
{
    return "Unary Operation: { " + expr.getString() + " Operator: " + operation + 
            + "}";
}

std::string IdentifierNode::getString()
{
    return ident + "\n";
}

std::string StatementNode::getString()
{
    return "Statement\n";
}

std::string BlockNode::getString()
{
    std::string str;
    for (long unsigned int i = 0; i < statements.size(); i++)
        str += " " + statements[i]->getString();
    return "Block of statements: {" + str + "}";
}

std::string ExpressionStatementNode::getString()
{
    return "Expression: {" + expr.getString() + "}";
}
