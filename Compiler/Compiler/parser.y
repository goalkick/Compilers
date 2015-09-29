/* Данный пример скорее всего даже не является рабочим, нужен для того, чтобы была возможность найти и загуглить то, что нужно гуглить */

/* Секция с кодом, который попадет в парсер.*/
%{
#include <iostream>
extern "C" int yylex();
void yyerror( int*, const char * );
%}

/* Этот код будет помещен до определения Union
Обычно используется для описания классов, реализующих синтаксическое дерево. */
/* Параметры функции парсера. */
%parse-param { int* hasError }

/* Определение возможных типов выражения. */
%union{
	int ival;
	char sval[255];
}

/* Определение лево-ассоцитивности. Аналогично есть %right.
Порядок объявление важен - чем позже объявлен оператор, тем больше его приоритет.
В данном случае оба оператора лево-ассоциативные, но - имеет более высокий приоритет, чем & и |. */
%left '&'  '|'
%left '-'

/* Определение токенов. Можно задать ассоциируемый с токеном тип из Union. */
%token <ival> INTEGER_LITERAL
%token <sval> ID
%token STRING 
%token INT
%token IF
%token CLASS
%token PUBLIC
%token BOOLEAN
%token EXTENDS
%token RETURN
%token WHILE
%token VOID
%token MAIN
%token SYSTEM_OUT_PRINTLN
%token LENGTH
%token TRUE
%token FALSE
%token NEW
%token ELSE
%token THIS

/* Секция с описанием правил парсера. */
%%
Program:
%%

/* Функция обработки ошибки. */
void yyerror( int*, const char* str )
{
	std::cout << str << std::endl;
}