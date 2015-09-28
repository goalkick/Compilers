%option noyywrap
%option yylineno

%{
#include <iostream>
#include <cmath>
#include <cstring>
#define YY_DECL extern "C" int yylex()
%}

DIGIT [0-9]
LETTER [a-zA-Z_]
id {LETER}({DIGIT} | {LETER})

NUM {DIGIT}{DIGIT}*
REAL ([0-9]+"."[]*) | ([0-9]*"."[0-9]+)
COMMENT ("--"[a-z]*"\n") | (" "|"\n"|"\t")+


%%

NUM { std::cout << yytext; }
REAL { std::cout << yytext; }
COMMENT { std::cout << yytext; }
id { std::cout << yytext; }
"if" { std::cout << yytext; }
"&&" { std::cout << yytext; }
"<"  { std::cout << yytext; }
">"  { std::cout << yytext; }
"==" { std::cout << yytext; }
"*"  { std::cout << yytext; }
"+"  { std::cout << yytext; }
"-"  { std::cout << yytext; }

%%