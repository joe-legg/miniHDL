miniHDL: main.o parser.o lex.yy.o error.o ast.o codeGen.o symbolTable.o
	g++ -o bin/minihdl main.o parser.o lex.yy.o error.o ast.o codeGen.o symbolTable.o

main.o: src/main.cpp
	g++ -c src/main.cpp

parser.o: src/parser.cpp src/parser.h
	g++ -c src/parser.cpp

parser.cpp:
	lemon-- src/parser.lemon

lex.yy.o: src/lex.yy.c
	g++ -c src/lex.yy.c

lex.yy.c:
	flex -o src/lex.yy.c src/lexer.l

error.o: src/error.cpp src/error.hpp
	g++ -c src/error.cpp

ast.o: src/ast.cpp src/ast.hpp
	g++ -c src/ast.cpp

codeGen.o: src/codeGen.cpp
	g++ -c src/codeGen.cpp

symbolTable.o: src/symbolTable.cpp src/symbolTable.hpp
	g++ -c src/symbolTable.cpp

clean:
	rm *.o
