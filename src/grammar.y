%include 
{
    #include <iostream>
    #include "ast.hpp"

    extern int yylineno;

    BlockNode *programBlock;
}

%syntax_error
{
    std::cout << "\033[31mSyntax error on line " << yylineno << ".\033[39;49m\n";
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

%token_type { const char * }

%type statements { BlockNode * }
%type program { BlockNode * }
%type statement { StatementNode * }
%type expr { ExpressionNode * }

%left AND.
%left OR.
%right NOT.

program ::= statements(B). { programBlock = B; }

statements(A) ::= statement(B). { A = new BlockNode; A->statements.push_back(B); }
statements ::= statements(B) statement(C). { B->statements.push_back(C); }

statement(A) ::= expr(B) SEMICOLON. { A = new ExpressionStatementNode(*B); } // Expression

expr(A) ::= LBRACKET expr(B) RBRACKET. { A = B; }
expr(A) ::= expr(B) AND expr(D). { A = new BinaryOperatorNode("and", *B, *D); }
expr(A) ::= expr(B) OR expr(D). { A = new BinaryOperatorNode("or", *B, *D); }
// expr ::= NOT expr.
expr(A) ::= TRUE. { A = new BitNode(true); }
expr(A) ::= FALSE. { A = new BitNode(false); }
