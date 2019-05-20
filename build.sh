if [ ! -d "bin" ]
then
    mkdir bin
fi

echo "Compiling lemon grammar"
lemon-- src/grammar.lemon
echo "Compiling flex lexer."
flex -o src/lex.yy.cpp src/lexer.l
echo "Compiling C/C++"
clang++ -Wall -o bin/bool-logic src/grammar.cpp src/ast.cpp src/error.cpp src/main.cpp src/symbolTable.cpp src/codeGen.cpp src/lex.yy.cpp
