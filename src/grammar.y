%include
{
    #include <iostream>
    #include "ast.hpp"
    #include <string.h> 

    extern int yylineno;

    Node *rootNode = new Node;
}

%syntax_error
{
    std::cout << "\033[31mSyntax error on line " << yylineno << " near \""
            << TOKEN << "\".\033[39;49m\n";
}

%parse_accept
{
    std::cout << "\033[96mParsing done.\033[39;49m\n";
}

%parse_failure
{
    std::cout << "\033[31mParsing failed.\033[39;49m\n";
}

%stack_overflow
{
    std::cout << "\033[31mParser stack overflow.\033[39;49m\n";
}

%token_prefix TOK_
%token_type   { const char * }

%left AND.
%left OR.
%right NOT.

%type program { BlockNode * }
program ::= statements(B). { rootNode = B; }

%type statements { BlockNode * }
statements(A) ::= statement(B).            { A = new BlockNode; A->statements.push_back(B); }
statements ::= statements(B) statement(C). { B->statements.push_back(C); }

%type statement { StatementNode * }
// Expression statement
statement(A) ::= expr(B) SEMICOLON. { A = new ExpressionStatementNode(*B); } 

%type expr { ExpressionNode * }
expr(A) ::= LBRACKET expr(B) RBRACKET. { A = B; }
expr(A) ::= expr(B) AND expr(D).       { A = new BinaryOperationNode("and", *B, *D); }
expr(A) ::= expr(B) OR expr(D).        { A = new BinaryOperationNode("or", *B, *D); }
expr(A) ::= NOT expr(C).               { A = new UnaryOperationNode("not", *C); }
expr(A) ::= TRUE.                      { A = new BoolNode(true); }
expr(A) ::= FALSE.                     { A = new BoolNode(false); }
expr(A) ::= IDENT(B).                  { A = new IdentifierNode(B); }

%code
{
    extern int yylex();
    extern char *yytext;

    Node *parse()
    {
        void *parser = ParseAlloc(malloc);
        int token;

        // Uncomment for debugging
        // ParseTrace(stdout, "Parser: ");

        while ((token = yylex()))
        {
            Parse(parser, token, strdup(yytext));
        }

        Parse(parser, 0, NULL);

        ParseFree(parser, free);

        return rootNode;
    }
}
