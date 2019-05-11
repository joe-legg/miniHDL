if [ ! -d "bin" ]
then
    mkdir bin
fi

echo "Compiling lemon grammar"
lemon src/grammar.y 
mv src/grammar.h src/grammar.hpp
mv src/grammar.c src/grammar.cpp
echo "Compiling flex lexer."
flex -o src/lex.yy.cpp src/lexer.l
echo "Compiling C/C++"
g++ -o bin/bool-logic -Wall src/grammar.cpp src/ast.cpp src/main.cpp src/codeGen.cpp src/lex.yy.cpp
