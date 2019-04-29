%{
    #include "grammar.h"
%}

%option noyywrap
%option yylineno

%%

and   return AND;
or    return OR;
not|! return NOT;
true  return TRUE;
false return FALSE;

"(" return LBRACKET;
")" return RBRACKET;
";" return SEMICOLON;

" " {}
\n {}
\t {}
. {}

%%
