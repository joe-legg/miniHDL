#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <vector>
#include <tuple>

#define INPUT 0
#define OUTPUT 1
#define MODULE 2
#define MODULE_INST 3

typedef std::tuple<int /* Type */, std::string /* Symbol */,
        int /* extra data */> Symbol;

class SymbolTable
{
    // Holds a list of the symbols in the current scope
    std::vector<std::vector<Symbol>> scopes;

  public:
    // Symbols
    void insertSym(int type, std::string ident, int extraData = 0);
    Symbol lookupIdent(std::string ident);
    bool isIdentInScope(std::string ident);

    // Scope
    void enterScope();
    void exitScope();
};

#endif
