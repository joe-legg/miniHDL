%include
{
    #include <iostream>
    #include "ast.hpp"
    
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

%type statements { BlockNode * }
%type program    { BlockNode * }
%type statement  { StatementNode * }
%type expr       { ExpressionNode * }

%left AND.
%left OR.
%right NOT.

program ::= statements(B). { rootNode = B; }

statements(A) ::= statement(B). { A = new BlockNode; A->statements.push_back(B); }
statements ::= statements(B) statement(C). { B->statements.push_back(C); }

// Expression statement
statement(A) ::= expr(B) SEMICOLON. { A = new ExpressionStatementNode(*B); } 

expr(A) ::= LBRACKET expr(B) RBRACKET. { A = B; }
expr(A) ::= expr(B) AND expr(D). { A = new BinaryOperationNode("and", *B, *D); }
expr(A) ::= expr(B) OR expr(D). { A = new BinaryOperationNode("or", *B, *D); }
// expr ::= NOT expr.
expr(A) ::= TRUE. { A = new BoolNode(true); }
expr(A) ::= FALSE. { A = new BoolNode(false); }

%code
{
    extern char *yytext;
    extern int yylex();
    
    Node *parse()
    {
        void *parser = ParseAlloc(malloc);
        int token;

        // Uncomment for debugging
        // ParseTrace(stdout, "Parser: ");

        while ((token = yylex()))
            Parse(parser, token, yytext);

        Parse(parser, 0, NULL);

        ParseFree(parser, free);

        return rootNode;
    }
}
