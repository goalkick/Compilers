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

"if" { std::cout << "0"; return IF; }
"int" { std::cout << "1"; return INT; }
"String" { std::cout << "2"; return STRING; }
"class" { std::cout << "3"; return CLASS; }
"extends" { std::cout << "4"; return EXTENDS; }
"public" { std::cout << "5"; return PUBLIC; }
"return" { std::cout << "6"; return RETURN; }
"boolean" { std::cout << "7"; return BOOLEAN; }
"else" { std::cout << "8"; return ELSE; }
"while" { std::cout << "9"; return WHILE; }
"System.out.println" { std::cout << "10"; return SYSTEM_OUT_PRINTLN; }
"length" { std::cout << "11"; return LENGTH; }
"new" { std::cout << "12"; return NEW; }
"this" { std::cout << "13"; return THIS; }
"true" { std::cout << "14"; return TRUE; }
"false" { std::cout << "15"; return FALSE; }
"static" { std::cout << "16"; return STATIC; }
"void" { std::cout << "17"; return VOID; }
"main" { std::cout << "18"; return MAIN; }
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
"//"[a-z]*"\n" { ; }
{NUM} { std::cout << "NUMM"; yylval.ival = atoi( yytext ); return INTEGER_LITERAL; }
{id} {  std::cout << "iddddd"; strcpy(yylval.sval, yytext); return ID; }
%%