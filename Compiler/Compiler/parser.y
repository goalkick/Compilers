/* ������ � �����, ������� ������� � ������.*/
%{
#include <iostream>
extern "C" int yylex();
void yyerror( const char * );
%}

/* ���� ��� ����� ������� �� ����������� Union
������ ������������ ��� �������� �������, ����������� �������������� ������. */
/* ��������� ������� �������. */

/* ����������� ��������� ����� ���������. */
%union{
	int ival;
	char sval[255];
}

/* ����������� ����-��������������. ���������� ���� %right.
������� ���������� ����� - ��� ����� �������� ��������, ��� ������ ��� ���������.
� ������ ������ ��� ��������� ����-�������������, �� - ����� ����� ������� ���������, ��� & � |. */
%left '&' '+' '-'
%left '*' '/'
%left '<' '>'
%left '.' '[' ']' '!'

/* ����������� �������. ����� ������ ������������� � ������� ��� �� Union. */
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
%token STATIC

%start Program

/* ������ � ��������� ������ �������. */
%%

Program : 
	MainClass { } 
	| MainClass ClassDeclsList {}
	;

MainClass :
	CLASS ID '{' PUBLIC STATIC VOID MAIN '(' STRING '['']' ID ')' '{' Statement '}' '}' {}
	;

ClassDeclsList :
	ClassDecls {}
	| ClassDeclsList ClassDecls {}
	;

ClassDecls : 
	CLASS ID '{' '}' { std::cout << 1; }
	| CLASS ID '{' VarDeclList '}' {}
	| CLASS ID '{' MethodDeclList '}' {}
	| CLASS ID '{' VarDeclList MethodDeclList '}' {}
	| CLASS ID EXTENDS ID '{' '}' {}
	| CLASS ID EXTENDS ID '{' VarDeclList '}' {}
	| CLASS ID EXTENDS ID '{' MethodDeclList '}' {}
	| CLASS ID EXTENDS ID '{' VarDeclList MethodDeclList '}' {}
	;

VarDeclList :
	VarDecl {}
	| VarDeclList VarDecl {}
	;

MethodDeclList :
	MethodDecl {}
	| MethodDeclList MethodDecl {}
	;

VarDecl : 
	Type ID ';' {}
	;

MethodDecl :
	PUBLIC Type ID '(' ')' '{' RETURN Exp ';' '}' {}
	| PUBLIC Type ID '(' ')' '{' VarDeclList RETURN Exp ';' '}' {}
	| PUBLIC Type ID '(' ')' '{' StatementList RETURN Exp ';' '}' {}
	| PUBLIC Type ID '(' ')' '{' VarDeclList StatementList RETURN Exp ';' '}' {}
	| PUBLIC Type ID '(' FormalList ')' '{' RETURN Exp ';' '}' {}
	| PUBLIC Type ID '(' FormalList ')' '{' VarDeclList RETURN Exp ';' '}' {}
	| PUBLIC Type ID '(' FormalList ')' '{' StatementList RETURN Exp ';' '}' {}
	| PUBLIC Type ID '(' FormalList ')' '{' VarDeclList StatementList RETURN Exp ';' '}' {}
	;

StatementList :
	Statement {}
	| StatementList Statement {}
	;

FormalList :
	Type ID {}
	| Type ID FormalRest {}
	;

FormalRest : 
	',' Type ID {}
	| FormalRest ',' Type ID {}
	;

Type :
	INT '['']' {}
	| BOOLEAN {}
	| INT {}
	| ID {}
	;

Statement :
	'{' StatementList '}' {}
	| '{' '}' {}
	| IF '(' Exp ')' Statement ELSE Statement {}
	| WHILE '(' Exp ')' Statement {}
	| SYSTEM_OUT_PRINTLN '(' Exp ')' ';' {}
	| ID '=' Exp ';' {}
	| ID '[' Exp ']' '=' Exp ';' {}
	;

Exp :
	Exp '+' Exp {}
	| Exp '-' Exp {}
	| Exp '*' Exp {}
	| Exp '/' Exp {}
	| Exp '[' Exp ']' {}
	| Exp '.' LENGTH {}
	| Exp '.' ID '(' ExpList ')' {}
	| Exp '.' ID '(' ')' {}
	| Exp '<' Exp {}
	| Exp '>' Exp {}
	| Exp '&' Exp {}
	| INTEGER_LITERAL {}
	| TRUE {}
	| FALSE {}
	| ID {}
	| THIS {}
	| NEW INT '[' Exp ']' {}
	| NEW ID '(' ')' {}
	| '!' Exp {}
	| '(' Exp ')' {}
	;

ExpList :
	Exp {}
	| ExpList ExpRest {}
	;

ExpRest :
	',' Exp {}
	;

%%
/* ������� ��������� ������. */
void yyerror( const char* str )
{
	std::cout << "ERROR!" << str << std::endl;
}