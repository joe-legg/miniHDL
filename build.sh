if [ ! -d "bin" ]
then
    mkdir bin
fi

echo "Compiling lemon grammar"
lemon src/grammar.y
echo "Compiling flex lexer."
flex -o src/lex.yy.c src/lexer.l
echo "Compiling C/C++"
g++ -o bin/bool-logic -Wall src/grammar.c src/ast.cpp src/parser.cpp src/main.cpp src/codeGen.cpp src/lex.yy.c
