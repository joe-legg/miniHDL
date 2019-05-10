%{
    #include "grammar.hpp"
%}

%option nounput
%option noinput
%option noyywrap

%option yylineno

%%

and   return TOK_AND;
or    return TOK_OR;
not|! return TOK_NOT;
true  return TOK_TRUE;
false return TOK_FALSE;

"(" return TOK_LBRACKET;
")" return TOK_RBRACKET;
";" return TOK_SEMICOLON;

" " {}
\n {}
\t {}
. {}

%%
