#include "symbolTable.hpp"

void SymbolTable::insertSym(std::string symbol, SymType type,
        std::vector<SymType> ports)
{
    scopes[scopes.size() - 1].push_back({symbol, type, ports});
}

Symbol SymbolTable::lookupSym(std::string symbol)
{
    for (int i = 0; i < scopes.size(); i++)
        for (int k = 0; k < scopes[i].size(); k++)
            if (scopes[i][k].symbol == symbol)
                return scopes[i][k];
    return {"", SymType::None, std::vector<SymType>()};
}

bool SymbolTable::isIdentInScope(std::string symbol)
{
    return lookupSym(symbol).type == SymType::None ? false : true;
}

void SymbolTable::enterScope() { scopes.push_back(std::vector<Symbol>()); }
void SymbolTable::exitScope()  { scopes.pop_back(); }
