#define TOK_AND                              1
#define TOK_XOR                              2
#define TOK_OR                               3
#define TOK_NOT                              4
#define TOK_CONNECTION                       5
#define TOK_SEMICOLON                        6
#define TOK_WIRE                             7
#define TOK_WHEN                             8
#define TOK_END                              9
#define TOK_ELSE                            10
#define TOK_MODULE                          11
#define TOK_COMMA                           12
#define TOK_INPUT                           13
#define TOK_OUTPUT                          14
#define TOK_LBRACKET                        15
#define TOK_RBRACKET                        16
#define TOK_TRUE                            17
#define TOK_FALSE                           18
#define TOK_IDENT                           19

    void parse(const char *filename);
