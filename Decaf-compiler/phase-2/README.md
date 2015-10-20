### GENERAL ###
The directory contains a scanner file ("scanner.l") made in flex which is performs the job of a tokenizer for the parser.
The parser file ("parser.y") is made in bison which contains the grammer of the decaf language.
The AST file ("AST.hpp") contains the definations of the classes which will be used to generate the AST represenation of the given program.

### RUNNING ###
* Run command "make" to compile all the given files.
* A file named "out" will be formed. This is the compiler.
* Now run this will with the decaf program as an input to file using the redirection ("<").
* You can user command "make clean" to delete the files which have been generated via the make file.

