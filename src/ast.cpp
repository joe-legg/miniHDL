#include "ast.hpp"

// Destructors

ASTNode::~ASTNode() {}

ModuleDef::~ModuleDef()       { delete ident; delete stmts; }
BinaryOpNode::~BinaryOpNode() { delete left; delete right; }
WireDef::~WireDef()           { delete ident; delete expr; }
ExprStmtNode::~ExprStmtNode() { delete expr; }
UnaryOpNode::~UnaryOpNode()   { delete expr; }

WhenElseStmtNode::~WhenElseStmtNode()
{
    delete condition;
    delete stmts;
    delete elseStmts;
}

CompoundStmtNode::~CompoundStmtNode()
{
    for (int i = 0; i < stmts.size(); i++)
        delete stmts[i];
}

ModuleInstNode::~ModuleInstNode()
{ 
    delete moduleIdent; 
    delete instIdent;
    for (int i = 0; i < args.size(); i++)
        delete args[i];
}

// Get string methods

std::string ASTNode::getString()  { return ""; }
std::string StmtNode::getString() { return ""; }
std::string ExprNode::getString() { return ""; }

std::string BoolNode::getString()
{
    return value ? "Bool Val: true" : "Bool Val: false";
}


std::string BinaryOpNode::getString()
{
    return "Binary Operation: {" + left->getString() + ", Operation: " + 
            std::to_string(op) + ", " + right->getString() + "}";
}

std::string UnaryOpNode::getString()
{
    return "Unary Operation: {Operation: " + std::to_string(op) +
            ", " + expr->getString() + "}";
}

std::string IdentNode::getString()
{
    return "Ident: \"" + ident + "\"";
}

std::string ExprStmtNode::getString()
{
    return "Expression Statement: {" + expr->getString() + "}";
}

std::string WireDef::getString()
{
    return "Wire Def: {" + ident->getString() + ", " + expr->getString() + "}";
}

std::string CompoundStmtNode::getString()
{
    std::string stmtString;
    for (int i = 0; i < stmts.size(); i++)
        stmtString += stmts[i]->getString() + ", ";
    stmtString.pop_back();
    stmtString.pop_back();
    return "Compound Statement: {" + stmtString + "}";
}

std::string WhenElseStmtNode::getString()
{
    return "When else stmt: {Condition: {" + condition->getString() +
            "}, Statements: {" + stmts->getString() + "}, Else statements: {" +
            elseStmts->getString() + "}}";
}

std::string ModuleInstNode::getString()
{
    std::string argStr;
    for (int i = 0; i < args.size(); i++)
        argStr += args[i]->getString() + ", ";
    argStr.pop_back();
    return "Module Instance: {Module Ident: {" + moduleIdent->getString() +
            "}, Instance Ident: {" + instIdent->getString() + "}, Arguments: {" +
            argStr + "}}";
}

std::string ModuleDef::getString()
{
    std::string portListStr = "Port List: {";
    for (int i = 0; i < portList.size(); i++)
        portListStr += "Port: {Type: " + std::to_string(portList[i].type) +
                ", " + portList[i].ident->getString() + "}, ";
    portListStr.pop_back();
    portListStr.pop_back();
    portListStr += "}, ";
    return "Module Def: {" + ident->getString() + ", " + portListStr +
            stmts->getString() + "}";
}
