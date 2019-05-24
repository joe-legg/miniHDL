#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

#define OUTPUT 1
#define INPUT 0

class Node
{
  public:
    virtual std::string codeGen();
    virtual std::string getString();
};

// Expression
class ExpressionNode : public Node
{
  public:
    std::string codeGen();
    std::string getString();
};

// Boolean value
class BoolNode : public ExpressionNode
{
  public:
    bool value;
    std::string codeGen();
    std::string getString();
    BoolNode (bool val) : value(val) {}
};

// Binary operation
class BinaryOperationNode : public ExpressionNode
{
  public:
    std::string operation;
    ExpressionNode &left;
    ExpressionNode &right;
    std::string codeGen();
    std::string getString();
    BinaryOperationNode(const char *op, ExpressionNode &left,
             ExpressionNode &right) : operation(op), left(left), right(right) {}
};

// Unary operation
class UnaryOperationNode : public ExpressionNode
{
  public:
    std::string operation;
    ExpressionNode &expr;
    std::string codeGen();
    std::string getString();
    UnaryOperationNode(const char *operation,
            ExpressionNode &expr) : operation(operation), expr(expr) {}
};

// Identifier
class IdentifierNode : public ExpressionNode
{
  public:
    std::string ident;
    std::string codeGen();
    std::string getString();
    IdentifierNode(std::string ident) : ident(ident) {}
};

// Statement
class StatementNode : public Node
{
  public:
    std::string codeGen();
    std::string getString();
};

// Block of statements
class BlockNode : public StatementNode
{
  public:
    std::vector<StatementNode *> statements;
    std::string codeGen();
    std::string getString();
};

class Parameter
{
  public:
    bool type;
    IdentifierNode *ident;
    Parameter(bool type, IdentifierNode *ident): type(type), ident(ident) {}
};

// Module definition
class ModuleDefinitionNode : public StatementNode
{
  public:
    IdentifierNode &ident;
    std::vector<Parameter *> parameters;
    BlockNode &block;
    std::string codeGen();
    std::string getString();
    ModuleDefinitionNode(IdentifierNode &ident,
            std::vector<Parameter *> parameters, BlockNode &block) : ident(ident),
            parameters(parameters), block(block) {}
};

// Expression statement
class ExpressionStatementNode : public StatementNode
{
  public:
    ExpressionNode &expr;
    std::string codeGen();
    std::string getString();
    ExpressionStatementNode(ExpressionNode &expr) : expr(expr) {}
};

// Module instance
class ModuleInstanceNode : public StatementNode
{
  public:
    IdentifierNode &ident;
    IdentifierNode &module;
    std::vector<IdentifierNode *> arguments;
    std::string codeGen();
    std::string getString();
    ModuleInstanceNode(IdentifierNode &ident, IdentifierNode &module,
            std::vector<IdentifierNode *> arguments) : ident(ident),
            module(module), arguments(arguments) {}
};

#endif
