objects = parser.tab.o lex.yy.o
CXX = g++
CXXFLAGS = -g -Wno-deprecated
includes = AST.cpp

main:	$(objects) 
	$(CXX) $(CXXFLAGS) -o out $(objects)

parser.tab.hpp parser.tab.cpp: parser.ypp
	bison -d -v parser.ypp

lex.yy.c: scanner.l parser.tab.hpp
	flex scanner.l

parser.tab.o:	parser.tab.cpp

lex.yy.o:	parser.tab.hpp lex.yy.c
	$(CXX) -lfl $(CXXFLAGS) -c parser.tab.cpp lex.yy.c

.PHONY :	clean

clean:
	-rm -f out parser.tab.o lex.yy.o
	-rm -f parser.tab.cpp parser.tab.hpp parser.output lex.yy.c
