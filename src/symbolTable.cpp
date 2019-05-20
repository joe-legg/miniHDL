#include "symbolTable.hpp"

void SymbolTable::insertSym(int type, std::string ident)
{
    scopes[scopes.size() - 1].push_back(std::make_tuple(type, ident));
}

Symbol SymbolTable::lookupIdent(std::string ident)
{
    for (int i = 0; i < scopes.size(); i++)
        for (int k = 0; k < scopes[i].size(); k++)
            if (std::get<1>(scopes[i][k]) == ident)
                return scopes[i][k];
    return std::make_tuple(-1, ""); // If symbol is not in scope
}

bool SymbolTable::isIdentInScope(std::string ident)
{
    return std::get<0>(lookupIdent(ident)) == -1 ? false : true;
}

void SymbolTable::enterScope() { scopes.push_back(std::vector<Symbol>()); }
void SymbolTable::exitScope()  { scopes.pop_back(); }
