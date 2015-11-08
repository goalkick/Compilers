%{
#include <iostream>
#include "Classes.h"
#include "PrettyPrinter.h"
extern "C" int yylex();
void yyerror( std::shared_ptr<CProgram>& , const char * );
%}

%parse-param { std::shared_ptr<CProgram>& root }

%code requires { 
	#include "Classes.h" 
	#include "PrettyPrinter.h" 
}

%union{
	int ival;
	char sval[255];
	char* val;
	IProgram* programVal; 
	IMainClass* mainClassDeclarationVal; 
	IClassDeclsList* classDeclarationListVal; 
	IClassDecls* classDeclarationVal; 
	IVarDeclList* variableDeclarationListVal; 
	IVarDecl* variableDeclarationVal; 
	IMethodDecl* methodDeclarationVal; 
	IMethodDeclList* methodDeclarationListVal; 
	IFormalList* formalListVal; 
	IFormalRest* formalRestVal; 
	IStatement* statementVal; 
	IType* typeVal; 
	IExp* expressionVal; 
	IExpRest* expressionRest; 
	IExpList* expressionListVal; 
	IStatementList* statementListVal;
}

/* Определение лево-ассоцитивности. Аналогично есть %right.
Порядок объявление важен - чем позже объявлен оператор, тем больше его приоритет.
В данном случае оба оператора лево-ассоциативные, но - имеет более высокий приоритет, чем & и |. */
%left '&' '+' '-'
%left '*' '/'
%left '<' '>'
%left '.' '[' ']' '!'

/* Определение токенов. Можно задать ассоциируемый с токеном тип из Union. */

%token <ival> INTEGER_LITERAL
%token <sval> ID
%token STRING 
%token INT
%token IF
%token CLASS
%token PUBLIC
%token BOOL
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

%type <programVal> Program
%type <mainClassDeclarationVal> MainClass
%type <classDeclarationListVal> ClassDeclsList
%type <classDeclarationVal> ClassDecls
%type <variableDeclarationListVal> VarDeclList
%type <variableDeclarationVal> VarDecl
%type <methodDeclarationVal> MethodDecl
%type <methodDeclarationListVal> MethodDeclList
%type <formalListVal> FormalList 
%type <formalRestVal> FormalRest
%type <statementVal> Statement
%type <typeVal> Type
%type <expressionVal> Exp
%type <expressionRest> ExpRest
%type <expressionListVal> ExpList 
%type <statementListVal> StatementList

%start Program

/* Секция с описанием правил парсера. */
%%

Program : 
	MainClass { root = std::make_shared<CProgram>( $1, nullptr, CLocation( 0, 0, 0, 0 ) ); } 
	| MainClass ClassDeclsList { root = std::make_shared<CProgram>( $1, $2, CLocation( 0, 0, 0, 0 ) ); }
	;

MainClass :
	CLASS ID '{' PUBLIC STATIC VOID MAIN '(' STRING '['']' ID ')' '{' Statement '}' '}' 
	{ 
		$$ = new CMainClass( $15, $2, $12, CLocation( 0, 0, 0, 0 ) );	
	}
	;

ClassDeclsList :
	ClassDecls { $$ = new CClassDeclsList( $1, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| ClassDeclsList ClassDecls { $$ = new CClassDeclsList( $2, $1, CLocation( 0, 0, 0, 0 ) ); }
	;

ClassDecls : 
	CLASS ID '{' '}' { $$ = new CClassDecls( $2, "", nullptr, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| CLASS ID '{' VarDeclList '}' { $$ = new CClassDecls( $2, "", $4, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| CLASS ID '{' MethodDeclList '}' { $$ = new CClassDecls( $2, "", nullptr, $4, CLocation( 0, 0, 0, 0 ) ); }
	| CLASS ID '{' VarDeclList MethodDeclList '}' { $$ = new CClassDecls( $2, "", $4, $5, CLocation( 0, 0, 0, 0 ) ); }
	| CLASS ID EXTENDS ID '{' '}' { $$ = new CClassDecls( $2, $4, nullptr, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| CLASS ID EXTENDS ID '{' VarDeclList '}' { $$ = new CClassDecls( $2, $4, $6, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| CLASS ID EXTENDS ID '{' MethodDeclList '}' { $$ = new CClassDecls( $2, $4, nullptr, $6, CLocation( 0, 0, 0, 0 ) ); }
	| CLASS ID EXTENDS ID '{' VarDeclList MethodDeclList '}' { $$ = new CClassDecls( $2, $4, $6, $7, CLocation( 0, 0, 0, 0 ) ); }
	;

VarDeclList :
	VarDecl { $$ = new CVarDeclList( nullptr, $1, CLocation( 0, 0, 0, 0 ) ); }
	| VarDeclList VarDecl { $$ = new CVarDeclList( $1, $2, CLocation( 0, 0, 0, 0 ) ); }
	;

MethodDeclList :
	MethodDecl { $$ = new CMethodDeclList( $1, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| MethodDeclList MethodDecl { $$ = new CMethodDeclList( $2, $1, CLocation( 0, 0, 0, 0 ) ); }
	;

VarDecl : 
	Type ID ';' { $$ = new CVarDecl( $1, $2, CLocation( 0, 0, 0, 0 ) ); }
	;

MethodDecl :
	PUBLIC Type ID '(' ')' '{' RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, nullptr, nullptr, nullptr, $8, CLocation( 0, 0, 0, 0 ) ); }
	| PUBLIC Type ID '(' ')' '{' VarDeclList RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, nullptr, $7, nullptr, $9, CLocation( 0, 0, 0, 0 ) ); }
	| PUBLIC Type ID '(' ')' '{' StatementList RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, nullptr, nullptr, $7, $9, CLocation( 0, 0, 0, 0 ) ); }
	| PUBLIC Type ID '(' ')' '{' VarDeclList StatementList RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, nullptr, $7, $8, $10, CLocation( 0, 0, 0, 0 ) ); }
	| PUBLIC Type ID '(' FormalList ')' '{' RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, nullptr, nullptr, $9, CLocation( 0, 0, 0, 0 ) ); }
	| PUBLIC Type ID '(' FormalList ')' '{' VarDeclList RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, $8, nullptr, $10, CLocation( 0, 0, 0, 0 ) ); }
	| PUBLIC Type ID '(' FormalList ')' '{' StatementList RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, nullptr, $8, $10, CLocation( 0, 0, 0, 0 ) ); }
	| PUBLIC Type ID '(' FormalList ')' '{' VarDeclList StatementList RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, $8, $9, $11, CLocation( 0, 0, 0, 0 ) ); }
	;

StatementList :
	Statement { $$ = new CStatementList( $1, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| StatementList Statement { $$ = new CStatementList( $2, $1, CLocation( 0, 0, 0, 0 ) ); }
	;

FormalList :
	Type ID { $$ = new CFormalList( $1, $2, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| Type ID FormalRest { $$ = new CFormalList( $1, $2, $3, CLocation( 0, 0, 0, 0 ) ); }
	;

FormalRest : 
	',' Type ID { $$ = new CFormalRest( $2, $3, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| FormalRest ',' Type ID { $$ = new CFormalRest( $3, $4, $1, CLocation( 0, 0, 0, 0 ) ); }
	;

Type :
	INT '['']' { $$ = new CType( CType::EType::INT_ARRAY, CLocation( 0, 0, 0, 0 ) ); }
	| BOOL { $$ = new CType( CType::EType::BOOL, CLocation( 0, 0, 0, 0 ) ); }
	| INT { $$ = new CType( CType::EType::INT, CLocation( 0, 0, 0, 0 ) ); }
	| ID { $$ = new CUserType( $1, CLocation( 0, 0, 0, 0 ) ); }
	;

Statement :
	'{' StatementList '}' { $$ = new CStatement( $2, CLocation(0, 0, 0, 0 ) ); }
	| '{' '}' { $$ = new CStatement( nullptr, CLocation(0, 0, 0, 0 ) ); }
	| IF '(' Exp ')' Statement ELSE Statement { $$ = new CIfStatement( $3, $5, $7, CLocation(0, 0, 0, 0 ) ); }
	| WHILE '(' Exp ')' Statement { $$ = new CWhileStatement( $3, $5, CLocation(0, 0, 0, 0 ) ); }
	| SYSTEM_OUT_PRINTLN '(' Exp ')' ';' { 
	$$ = new CPrintStatement( $3, CLocation(0, 0, 0, 0 ) ); 
	}
	| ID '=' Exp ';' { $$ = new CAssignStatement( $1, $3, CLocation(0, 0, 0, 0 ) ); }
	| ID '[' Exp ']' '=' Exp ';' { $$ = new CArrayAssignStatement( $1, $3, $6, CLocation(0, 0, 0, 0 ) ); }
	;

Exp :
	Exp '+' Exp { $$ = new CBinOpExpression( $1, CBinOpExpression::PLUS, $3, CLocation( 0, 0, 0, 0 ) ); }
	| Exp '-' Exp { $$ = new CBinOpExpression( $1, CBinOpExpression::MINUS, $3, CLocation( 0, 0, 0, 0 ) ); }
	| Exp '*' Exp { $$ = new CBinOpExpression( $1, CBinOpExpression::TIMES, $3, CLocation( 0, 0, 0, 0 ) ); }
	| Exp '/' Exp { $$ = new CBinOpExpression( $1, CBinOpExpression::DIVIDE, $3, CLocation( 0, 0, 0, 0 ) ); }
	| Exp '[' Exp ']' { $$ = new CIndexExpression( $1, $3, CLocation( 0, 0, 0, 0 ) ); }
	| Exp '.' LENGTH { $$ = new CLenghtExpression( $1, CLocation( 0, 0, 0, 0 ) ); }
	| Exp '.' ID '(' ExpList ')' { $$ = new CMethodExpression( $1, $3, $5, CLocation( 0, 0, 0, 0 ) ); }
	| Exp '.' ID '(' ')' { $$ = new CMethodExpression( $1, $3, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| Exp '<' Exp { $$ = new CBinOpExpression( $1, CBinOpExpression::LESS, $3, CLocation( 0, 0, 0, 0 ) ); }
	| Exp '&' Exp { $$ = new CBinOpExpression( $1, CBinOpExpression::AND, $3, CLocation( 0, 0, 0, 0 ) ); }
	| INTEGER_LITERAL { $$ = new CIntLiteralExpression( yyval.ival, CLocation( 0, 0, 0, 0 ) ); }
	| TRUE {}
	| FALSE {}
	| ID { $$ = new CIdentifierExpression( $1, CLocation( 0, 0, 0, 0 ) ); }
	| THIS { $$ = new CThisExpression( CLocation( 0, 0, 0, 0 ) ); }
	| NEW INT '[' Exp ']' { $$ = new CNewIntArrayExpression( $4, CLocation( 0, 0, 0, 0 ) ); }
	| NEW ID '(' ')' { $$ = new CNewExpression( $2, CLocation( 0, 0, 0, 0) ); }
	| '!' Exp { $$ =  new CUnaryOpExpression( CUnaryOpExpression::NOT, $2, CLocation( 0, 0, 0, 0 ) ); }
	| '(' Exp ')' { $$ = new CBracesExpression( $2, CLocation( 0, 0, 0, 0 ) ); }
	;

ExpList :
	Exp { $$ = new CExpList( $1, nullptr, nullptr, CLocation( 0, 0, 0, 0 ) ); }
	| ExpList ExpRest { $$ = new CExpList( nullptr, $1, $2, CLocation( 0, 0, 0, 0 ) ); }
	;

ExpRest :
	',' Exp { $$ = new CExpRest( $2, CLocation( 0, 0, 0, 0 ) ); }
	;

%%
/* Функция обработки ошибки. */
void yyerror( std::shared_ptr<CProgram>& root, const char* str )
{
	std::cout << "ERROR!" << str << std::endl;
}