/* -*-mode: c-*- : To change mode in Emacs */

%{
  #include <iostream>
  #include <vector>

  using namespace std;

  #include "AST.cpp"
  #include "parser.tab.hpp"
%}

%option noyywrap

CHAR ([\40-\176]{-}['"\\])|\\n|\\t|\\\\|\\\"|\\\'

%%

  /* ' just for syntax highligting in emacs - ignore */

  /* keywords */
if                              { return (IF); }
else                            { return (ELSE); }
for                             { return (FOR); }
return                          { return (RETURN); }
break                           { return (BREAK); }
continue                        { return (CONTINUE); }
callout                         { return (CALLOUT); }
class                           { return (CLASS); }
Program                         { return (PROGRAM); }

  /* boolean literal */
true                            { return (TRUE); }
false                           { return (FALSE); }

  /* data type */
int                             { yylval.sval = strdup(yytext); return (INT); }
boolean                         { yylval.sval = strdup(yytext); return (BOOLEAN); }
void                            { yylval.sval = strdup(yytext); return (VOID); }

  /* equality operators  */
\=\=                            { return (EQUAL_EQUAL); }
\!\=                            { return (NOT_EQUAL); }

  /* assignment operators */
\=                              { return (EQUAL); }
\-\=                            { return (MINUS_EQUAL); }
\+\=                            { return (PLUS_EQUAL); }

 /* comment */
\/\/.*				;

  /* arithmetic operators  */
\+                              { return (PLUS); }
\-                              { return (MINUS); }
\*                              { return (MULTIPLY); }
\/                              { return (DIVIDE); }
\%                              { return (MOD); }

  /* relational operators  */
\<\=                            { return (LESS_THAN_EQUAL); }
\>\=                            { return (GREATER_THAN_EQUAL); }
\<                              { return (LESS_THAN); }
\>                              { return (GREATER_THAN); }


  /* conditional operators  */
\&\&                            { return (AND); }
\|\|                            { return (OR); }

  /* brackets  */
\{                              { return (OPEN_CURLY); }
\}                              { return (CLOSE_CURLY); }
"["                             { return (OPEN_SQUARE); }
\]                              { return (CLOSE_SQUARE); }
\(                              { return (OPEN_PAREN); }
\)                              { return (CLOSE_PAREN); }

  /* literals */
0x[0-9a-fA-F][0-9a-fA-F]*       { yylval.sval = strdup(yytext); return (HEX_LITERAL); }
[0-9]+                          { yylval.ival = atoi(yytext); return (DECIMAL_LITERAL); }
\"{CHAR}*\"                     { yylval.sval = strdup(yytext); return (STRING_LITERAL); }
\'{CHAR}?\'                     { yylval.sval = strdup(yytext); return (CHAR_LITERAL); }


[a-zA-Z_][a-zA-Z0-9_]*          { yylval.sval = strdup(yytext);  return (IDENTIFIER); }

!                               { return (EXCLAMATION); }
;                               { return (SEMI_COLON); }
,                               { return (COMMA); }
\/\/(.*)"\n"
[ \t\n]			                 
.				                {printf("Error here\n");}
%% 
