#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

class Node
{
  public:
    virtual void codeGen();
    virtual std::string getString();
};

// Expression
class ExpressionNode : public Node 
{
  public:
    std::string getString();
};

// Boolean value
class BoolNode : public ExpressionNode
{
  public:
    bool value;
    BoolNode(bool val): value(val) {}
    std::string getString();
};

// Binary operation
class BinaryOperationNode: public ExpressionNode
{
  public:
    const char *operation;
    ExpressionNode &left;
    ExpressionNode &right;
    std::string getString();
    BinaryOperationNode(const char *op, ExpressionNode &left, ExpressionNode &right): operation(op), left(left), right(right) {}
};

// Identifier
class IdentifierNode : public ExpressionNode
{
  public:
    std::string ident;
    std::string getString();
    IdentifierNode(std::string ident): ident(ident) {}
};

// Statement
class StatementNode : public Node
{
  public:
    std::string getString();
};

// Block of statements
class BlockNode : public StatementNode
{
  public:
    std::vector<StatementNode *> statements;
    std::string getString();
};

// Expression statement
class ExpressionStatementNode : public StatementNode
{
  public:
    ExpressionNode &expr;
    std::string getString();
    ExpressionStatementNode(ExpressionNode &expr): expr(expr) {}
};

#endif
