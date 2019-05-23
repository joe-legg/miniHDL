#define TOK_AND                              1
#define TOK_OR                               2
#define TOK_NOT                              3
#define TOK_SEMICOLON                        4
#define TOK_CONNECTION                       5
#define TOK_COLON                            6
#define TOK_COMMA                            7
#define TOK_MODULE                           8
#define TOK_END                              9
#define TOK_INPUT                           10
#define TOK_OUTPUT                          11
#define TOK_LBRACKET                        12
#define TOK_RBRACKET                        13
#define TOK_TRUE                            14
#define TOK_FALSE                           15
#define TOK_IDENT                           16

    #include "ast.hpp"
    Node *parse();
