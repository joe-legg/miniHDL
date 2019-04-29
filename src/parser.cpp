#include "parser.hpp"
#include <stdlib.h>
#include <cstdio>

extern int yylex();
extern char *yytext;
extern void *ParseAlloc(void *(malloc)(size_t));
extern void Parse(void *parser, int tok_id, const char *tokData);
extern void ParseFree(void *parser, void (*freeProc)(void*));
extern void ParseTrace(FILE *fp, char *trace);

Node *parse()
{
    void* parser = ParseAlloc(malloc);
    int token;
    
    // Uncomment for debugging
    ParseTrace(stdout, "Parser: ");
    
    while (token = yylex())
    {
        Parse(parser, token, yytext);
    }

    Parse(parser, 0, NULL);
    ParseFree(parser, free);
}
