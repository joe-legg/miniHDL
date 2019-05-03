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

class BitNode : public ExpressionNode
{
  public:
    bool value;
    BitNode(bool val): value(val) {}
    std::string getString();
};

class BinaryOperatorNode : public ExpressionNode
{
  public:
    const char *operation;
    ExpressionNode &left;
    ExpressionNode &right;
    std::string getString();
    BinaryOperatorNode(const char *op, ExpressionNode &left, ExpressionNode &right): operation(op), left(left), right(right) {}
};

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

class BlockNode : public StatementNode
{
  public:
    std::vector<StatementNode *> statements;
    std::string getString();
};

class ExpressionStatementNode : public StatementNode
{
  public:
    ExpressionNode &expr;
    std::string getString();
    ExpressionStatementNode(ExpressionNode &expr): expr(expr) {}
};

// Print ast
void printAST(Node *baseNode);

#endif
