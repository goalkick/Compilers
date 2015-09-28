%option noyywrap
%option yylineno

%{
#include <iostream>
#include <string>

#define YY_DECL extern "C" int yylex()
%}

%%
. { std::cout << "I'm symbol \"" + std::string( yytext ) + "\" at line: " << yylineno << std::endl; }

%%
extern int YYText();