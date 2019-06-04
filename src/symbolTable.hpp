#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <vector>

enum class SymType { Input, Output, Wire, ModuleDef, ModuleInst, None };

class Symbol
{
  public:
    std::string symbol;
    SymType type;
};

class SymbolTable
{
    // Holds a list of the symbols in the current scope
    std::vector<std::vector<Symbol>> scopes;

  public:
    // Symbols
    void insertSym(std::string symbol, SymType type);
    Symbol lookupSym(std::string symbol);
    bool isIdentInScope(std::string symbol);

    // Scope
    void enterScope();
    void exitScope();
};

#endif
