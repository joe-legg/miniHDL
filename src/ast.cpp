#include "ast.hpp"
#include <iostream>

// Get string methods

std::string Node::getString()
{
    return "Node";
}

std::string ExpressionNode::getString()
{
    return "Expression";
}

std::string BoolNode::getString()
{
    std::string str = "Bit: ";
    str += value ? "1" : "0";
    return str;
}

std::string BinaryOperationNode::getString()
{
    return "Binary Operation: {" + left.getString() + ", Operator: " + operation
            + ", " + right.getString() + "}";
}

std::string UnaryOperationNode::getString()
{
    return "Unary Operation: {" + expr.getString() + ", Operator: " + operation + 
            + "}";
}

std::string IdentifierNode::getString()
{
    return "Identifier: \"" + ident + "\"";
}

std::string StatementNode::getString()
{
    return "Statement";
}

std::string BlockNode::getString()
{
    std::string str;
    for (long unsigned int i = 0; i < statements.size(); i++)
        str += statements[i]->getString() + ", ";
    return "Block of statements: {" + str + "}";
}

std::string ModuleDefinitionNode::getString()
{
    std::string paramStr = ", Parameters: {";
    for (long unsigned int i = 0; i < parameters.size(); i++)
        paramStr += std::string("Parameter: {Type: ") + 
                (parameters[i]->type ? "Output, " : "Input, ") +
                parameters[i]->ident->getString() + "}, ";
    paramStr += "}, ";
    return "Module Definition: {" + ident.getString() + paramStr +
            block.getString() + "}";
}

std::string ExpressionStatementNode::getString()
{
    return "Expression: {" + expr.getString() + "}";
}

std::string ModuleInstanceNode::getString()
{
    std::string argStr = "Arguments: {";
    for (int i = 0; i < arguments.size(); i++)
        argStr += arguments[i]->getString() + ", ";
    argStr += "}";
    return "Module Instance: {" + ident.getString() + ", Module: \"" +
            module.ident + "\", " + argStr + "}";
}
