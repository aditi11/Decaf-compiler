/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    RETURN = 261,
    BREAK = 262,
    CONTINUE = 263,
    CALLOUT = 264,
    CLASS = 265,
    PROGRAM = 266,
    TRUE = 267,
    FALSE = 268,
    INT = 269,
    BOOLEAN = 270,
    VOID = 271,
    EQUAL = 272,
    MINUS_EQUAL = 273,
    PLUS_EQUAL = 274,
    PLUS = 275,
    MINUS = 276,
    MULTIPLY = 277,
    DIVIDE = 278,
    MOD = 279,
    LESS_THAN = 280,
    LESS_THAN_EQUAL = 281,
    GREATER_THAN = 282,
    GREATER_THAN_EQUAL = 283,
    EQUAL_EQUAL = 284,
    NOT_EQUAL = 285,
    AND = 286,
    OR = 287,
    OPEN_CURLY = 288,
    CLOSE_CURLY = 289,
    OPEN_SQUARE = 290,
    CLOSE_SQUARE = 291,
    OPEN_PAREN = 292,
    CLOSE_PAREN = 293,
    IDENTIFIER = 294,
    SEMI_COLON = 295,
    COMMA = 296,
    EXCLAMATION = 297,
    HEX_LITERAL = 298,
    DECIMAL_LITERAL = 299,
    STRING_LITERAL = 300,
    CHAR_LITERAL = 301,
    UMINUS = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 37 "parser.ypp" /* yacc.c:1909  */

  int ival;
  char* cval;
  char* sval;
  bool bval;
  expression* e;
  vector<expression*>* ve;
  statement* s;
  vector<statement*>* vs;
  vector<char*>* vsval;
  head* h;
  block* blk;
  assignmentoperators a;
  parameters* par;
  location* loc;
  methodcall* mc;
  vector<arguments*>* va;

#line 121 "parser.tab.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
