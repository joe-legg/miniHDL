#include "ast.hpp"

std::string Node::codeGen() { return ""; }
std::string ExpressionNode::codeGen() { return ""; }
std::string StatementNode::codeGen() { return ""; }

std::string BoolNode::codeGen() { return value ? "1" : "0"; }

std::string BinaryOperationNode::codeGen()
{
    if (operation == "and") // And gate
        return left.codeGen() + "&" + right.codeGen();
    else if (operation == "or") // Or gate
        return left.codeGen() + "|" + right.codeGen();
    else if (operation == "con") // Connection
        return "assign " + left.codeGen() + " = " + right.codeGen() + ";\n";
    return "";
}

std::string UnaryOperationNode::codeGen()
{
    if (operation == "not")
        return "~" + expr.codeGen();
    return "";
}

std::string IdentifierNode::codeGen() { return ident; }


std::string BlockNode::codeGen()
{
    std::string code;
    for (int i = 0; i < statements.size(); i++)
        code += statements[i]->codeGen();
    return code;
}

std::string ModuleDefinitionNode::codeGen()
{
    std::string paramCode;
    for (int i = 0; i < parameters.size(); i++)
        paramCode += (parameters[i]->type == INPUT ? "input " : "output ") +
                parameters[i]->ident->ident + ",";
    paramCode.pop_back();
    return "module " + ident.ident + "(" + paramCode + ");\n" + block.codeGen() +
            "endmodule\n";
}

std::string ExpressionStatementNode::codeGen() { return expr.codeGen(); }

std::string ModuleInstanceNode::codeGen()
{
    std::string argCode;
    for (int i = 0; i < arguments.size(); i++)
        argCode += arguments[i]->ident + ",";
    argCode.pop_back();
    return module.ident + " " + ident.ident + "(" + argCode + ");\n";
}
