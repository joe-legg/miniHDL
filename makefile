miniHDL: main.o parser.o lex.yy.o error.o ast.o codeGen.o symbolTable.o
	clang++ -o bin/minihdl main.o parser.o lex.yy.o error.o ast.o codeGen.o symbolTable.o

main.o: src/main.cpp
	clang++ -c src/main.cpp

parser.o: src/parser.lemon src/parser.h
	lemon-- src/parser.lemon
	clang++ -c src/parser.cpp

lex.yy.o: src/lexer.l
	flex -o src/lex.yy.c src/lexer.l
	clang++ -c src/lex.yy.c

error.o: src/error.cpp src/error.hpp
	clang++ -c src/error.cpp

ast.o: src/ast.cpp src/ast.hpp
	clang++ -c src/ast.cpp

codeGen.o: src/codeGen.cpp
	clang++ -c src/codeGen.cpp

symbolTable.o: src/symbolTable.cpp src/symbolTable.hpp
	clang++ -c src/symbolTable.cpp

clean:
	rm *.o
