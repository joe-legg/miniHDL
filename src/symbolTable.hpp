#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <vector>
#include <tuple>

#define INPUT 0
#define OUTPUT 1
#define MODULE 2

typedef std::tuple<int, std::string> Symbol;

class SymbolTable
{
    // Holds a list of the symbols in the current scope
    std::vector<std::vector<Symbol>> scopes = {std::vector<Symbol>()};

  public:
    // Symbols
    void insertSym(int type, std::string ident);
    Symbol lookupIdent(std::string ident);
    bool isIdentInScope(std::string ident);

    // Scope
    void enterScope();
    void exitScope();
};

#endif
