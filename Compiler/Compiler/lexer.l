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
id [a-zA-Z_]*[a-zA-Z_][a-zA-Z_0-9]*

NUM {DIGIT}{DIGIT}*

%%

"if" { return IF; }
"int" { return INT; }
"String" { return STRING; }
"class" { return CLASS; }
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
"static" { return STATIC; }
"void" { return VOID; }
"main" { return MAIN; }
"-" {return '-';} 
"+" return('+'); 
"*" return('*'); 
"%" return('%'); 
"/" return('/'); 

"!" return('!'); 

"[" return('['); 
"]" return(']'); 
"{" return('{'); 
"}" return('}'); 
"(" return('('); 
")" return(')'); 
";" return(';'); 
"," return(','); 

"=" return('='); 

"<" return('<'); 
">" return('>');
"." return('.');
"&&"  { return '&'; }	
" "|"\n"|"\t" { ; }
[/][/].*\n { ; }
{NUM} { yylval.ival = atoi( yytext ); return INTEGER_LITERAL; }
{id} { strcpy(yylval.sval, yytext); return ID; }
%%