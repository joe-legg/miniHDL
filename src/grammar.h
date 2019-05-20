#define TOK_AND                              1
#define TOK_OR                               2
#define TOK_NOT                              3
#define TOK_SEMICOLON                        4
#define TOK_CONNECTION                       5
#define TOK_MODULE                           6
#define TOK_END                              7
#define TOK_COMMA                            8
#define TOK_INPUT                            9
#define TOK_OUTPUT                          10
#define TOK_LBRACKET                        11
#define TOK_RBRACKET                        12
#define TOK_TRUE                            13
#define TOK_FALSE                           14
#define TOK_IDENT                           15

    #include "ast.hpp"
    Node *parse();
