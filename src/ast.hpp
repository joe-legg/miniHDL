#ifndef AST_H
#define AST_H

#include <vector>
#include <string>

enum class Operation { And, Or, Xor, Not, Connection };
enum class Type { Input, Output };

class ASTNode
{
  public:
    virtual std::string codeGen(); 
    virtual std::string getString();
    virtual ~ASTNode();
};

class ExprNode : public ASTNode
{
  public:
    std::string codeGen(); 
    std::string getString();
};

class StmtNode : public ASTNode
{
  public:
    std::string codeGen(); 
    std::string getString();
};

// Expression nodes

class BoolNode : public ExprNode
{
  public:
    bool value;

    std::string codeGen(); 
    std::string getString();
    BoolNode(bool value) : value(value) {}
};

class BinaryOpNode : public ExprNode
{
  public:
    Operation op;
    ExprNode *left;
    ExprNode *right;

    std::string codeGen(); 
    std::string getString();
    BinaryOpNode(Operation op, ExprNode *left, ExprNode *right) : op(op),
            left(left), right(right) {}
    ~BinaryOpNode();
};

class UnaryOpNode : public ExprNode
{
  public:
    Operation op;
    ExprNode *expr;

    std::string codeGen(); 
    std::string getString();
    UnaryOpNode(Operation op, ExprNode *expr) : op(op), expr(expr) {}
    ~UnaryOpNode();
};

class IdentNode : public ExprNode
{
  public:
    std::string ident;

    std::string codeGen(); 
    std::string getString();
    IdentNode(std::string ident) : ident(ident) {}
};

class WhenElseExprNode : public ExprNode
{
  public:
    ExprNode *condition;
    ExprNode *expr;
    ExprNode *elseExpr;

    std::string codeGen();
    std::string getString();
    WhenElseExprNode(ExprNode *condition, ExprNode *expr,
            ExprNode *elseExpr) : condition(condition), expr(expr),
            elseExpr(elseExpr) {}
    ~WhenElseExprNode();
};

// Statement nodes

class WireDef : public StmtNode
{
  public:
    IdentNode *ident;
    ExprNode *expr;

    std::string codeGen(); 
    std::string getString();
    WireDef(IdentNode *ident, ExprNode *expr) : ident(ident), expr(expr) {}
    ~WireDef();
};

class CompoundStmtNode : public StmtNode
{
  public:
    std::vector<StmtNode *> stmts;

    std::string codeGen(); 
    std::string getString();
    ~CompoundStmtNode();
};

class ExprStmtNode : public StmtNode
{
  public:
    ExprNode *expr;

    std::string codeGen(); 
    std::string getString();
    ExprStmtNode(ExprNode *expr) : expr(expr) {}
    ~ExprStmtNode();
};

class ModuleInstNode : public StmtNode
{
  public:
    IdentNode *moduleIdent;
    IdentNode *instIdent;
    std::vector<ExprNode *> args;

    std::string codeGen(); 
    std::string getString();
    ModuleInstNode(IdentNode *moduleIdent, IdentNode *instIdent,
            std::vector<ExprNode *> args) : moduleIdent(moduleIdent),
            instIdent(instIdent), args(args) {}
    ~ModuleInstNode();
};

class Port
{
  public:
    Type type;
    IdentNode *ident;
    
    Port(IdentNode *ident, Type type) : ident(ident), type(type) {}
};

class ModuleDef : public StmtNode
{
  public:
    IdentNode *ident;
    std::vector<Port> portList;
    CompoundStmtNode *stmts;

    std::string codeGen(); 
    std::string getString();
    ModuleDef(IdentNode *ident, std::vector<Port> portList,
            CompoundStmtNode *stmts) : ident(ident), portList(portList),
            stmts(stmts) {}
    ~ModuleDef();
};

#endif
