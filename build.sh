if [ ! -d "bin" ]
then
    mkdir bin
fi

echo "Compiling lemon grammar"
lemon-- src/parser.lemon
echo "Compiling flex lexer."
flex -o src/lex.yy.c src/lexer.l
echo "Compiling C/C++"
clang++ -o bin/minihdl src/parser.cpp src/main.cpp src/lex.yy.c src/error.cpp src/ast.cpp src/codeGen.cpp
