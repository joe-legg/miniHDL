#define TOK_AND                              1
#define TOK_XOR                              2
#define TOK_OR                               3
#define TOK_NOT                              4
#define TOK_SEMICOLON                        5
#define TOK_CONNECTION                       6
#define TOK_COLON                            7
#define TOK_COMMA                            8
#define TOK_MODULE                           9
#define TOK_END                             10
#define TOK_INPUT                           11
#define TOK_OUTPUT                          12
#define TOK_LBRACKET                        13
#define TOK_RBRACKET                        14
#define TOK_TRUE                            15
#define TOK_FALSE                           16
#define TOK_IDENT                           17

    #include "ast.hpp"
    Node *parse(const char *filename);
