%option noyywrap
%option yylineno

%{
#include <iostream>
#include <cmath>
#include <cstring>
#include "parser.tab.hpp"
#define YY_DECL extern "C" int yylex()
%}

DIGIT [0-9]
LETTER [a-zA-Z_]
id {LETER}({DIGIT} | {LETER})

NUM {DIGIT}{DIGIT}*
COMMENT ("--"[a-z]*"\n") | (" "|"\n"|"\t")+


%%

"if" { return IF; }
"int" { return INT; }
"String" { return STRING; }
"Class" { return CLASS; }
"extends" { return EXTENDS; }
"public" { return PUBLIC; }
"return" { return RETURN; }
"boolean" { return BOOLEAN; }
"else" { return ELSE; }
"while" { return WHILE; }
"System.out.println" { return SYSTEM_OUT_PRINTLN; }
"length" { return LENGTH; }
"new" { return NEW; }
"this" { return THIS; }
"true" { return TRUE; }
"false" { return FALSE; }
NUM { yylval.ival = atoi( yytext ); return INTEGER_LITERAL; }
id {  strcpy(yylval.sval, yytext); return ID; }
COMMENT { ; }
"&&"  { return yytext[0]; }
[<>\=\+-.\*\\] { return yytext[0]; }

%%