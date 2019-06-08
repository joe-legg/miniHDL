#include "ast.hpp"

std::string ASTNode::codeGen()  { return ""; }
std::string StmtNode::codeGen() { return ""; }
std::string ExprNode::codeGen() { return ""; }

std::string BoolNode::codeGen() { return value ? "1'b1" : "1'b0"; }

std::string BinaryOpNode::codeGen()
{
    switch (op)
    {
        case Operation::And:
            return left->codeGen() + " & " + right->codeGen();
        case Operation::Or:
            return left->codeGen() + " | " + right->codeGen();
        case Operation::Xor:
            return left->codeGen() + " ^ " + right->codeGen();
        case Operation::Connection:
            return "assign " + left->codeGen() + " = " + right->codeGen();
        default:
            return "";
    }
}

std::string UnaryOpNode::codeGen()
{
    switch (op)
    {
        case Operation::Not:
            return "~" + expr->codeGen();
        default:
            return "";
    }
}

std::string ExprStmtNode::codeGen() { return expr->codeGen() + ";"; }

std::string IdentNode::codeGen() { return "_" + ident + "_"; }

std::string WireDef::codeGen()
{
    return "wire " + ident->codeGen() + " = " + expr->codeGen() + ";";
}

std::string CompoundStmtNode::codeGen()
{
    std::string code;
    for (int i = 0; i < stmts.size(); i++)
        code += stmts[i]->codeGen() + "\n";
    return code;
}

std::string WhenElseExprNode::codeGen()
{
    return "(" + condition->codeGen() + " ? " + expr->codeGen() + " : " +
            elseExpr->codeGen() + ")";
}

std::string ModuleInstNode::codeGen()
{
    std::string argsCode;
    for (int i = 0; i < args.size(); i++)
        argsCode += args[i]->codeGen() + ",";
    argsCode.pop_back();
    return moduleIdent->codeGen() + " " + instIdent->codeGen() + "(" + argsCode + ");";
}

std::string ModuleDef::codeGen()
{
    if (portList.size() < 1)
        return "module " + ident->codeGen() + ";\n" + stmts->codeGen() +
                "endmodule";
    std::string portListCode;
    for (int i = 0; i < portList.size(); i++)
        portListCode += (portList[i].type == Type::Input ? "input " : "output ")
                + portList[i].ident->codeGen() + ",";
    portListCode.pop_back();
    return "module " + ident->codeGen() + "(" + portListCode + ");\n" +
            stmts->codeGen() + "endmodule";
}
