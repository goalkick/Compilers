#include <set>

#include "TypeChecker.h"
#include "SymbolsTable.h"
#include "classes.h"
#include <iostream>
CTypeCheckerVisitor::CTypeCheckerVisitor( SymbolsTable::CTable* table )
{
	symbolsTable = table;
	curClass = nullptr;
	curMethod = nullptr;
}

void CTypeCheckerVisitor::visit( const CProgram* program )
{
	if (program->MainClass() != nullptr) {
		program->MainClass()->Accept( this );
	}
	if (program->ClassDeclList() != nullptr) {
		program->ClassDeclList()->Accept( this );
	}
}

void CTypeCheckerVisitor::visit( const CMainClass* mainClass )
{
	curClass = symbolsTable->GetClass( mainClass->ClassName()->GetString() );
	curMethod = curClass->GetMethod( "main" );

	if (mainClass->Statement() != nullptr) {
		mainClass->Statement()->Accept( this );
	}

	curMethod = nullptr;
	curClass = nullptr;
}

void CTypeCheckerVisitor::visit( const CClassDeclsList* classDeclList )
{
	if (classDeclList->ClassDecls() != nullptr) {
		classDeclList->ClassDecls()->Accept( this );
	}
	if (classDeclList->ClassDeclsList() != nullptr) {
		classDeclList->ClassDeclsList()->Accept( this );
	}
}

void CTypeCheckerVisitor::visit( const CClassDecls* classDecl )
{
	curClass = symbolsTable->GetClass( classDecl->ClassName()->GetString() );

	if (classDecl->VarDeclList() != nullptr) {
		classDecl->VarDeclList()->Accept( this );
	}
	if (classDecl->MethodDeclList() != nullptr) {
		classDecl->MethodDeclList()->Accept( this );
	}

	curClass = nullptr;
}


bool CTypeCheckerVisitor::isPODType( const std::string& type ) const
{
	return  type == "int" || type == "boolean" || type == "int[]";
}

void CTypeCheckerVisitor::visit( const CVarDecl* varDecl )
{
	varDecl->Type()->Accept( this );

	if (!isPODType( _lastTypeValue ) && symbolsTable->GetClass( _lastTypeValue ) == nullptr) {
		std::cout << "There is no such type " << _lastTypeValue << std::endl;
		return;
	}
}

void CTypeCheckerVisitor::visit( const CVarDeclList* varDeclList )
{
	if (varDeclList->VarDeclList() != nullptr) {
		varDeclList->VarDeclList()->Accept( this );
	}
	if (varDeclList->VarDecl() != nullptr) {
		varDeclList->VarDecl()->Accept( this );
	}
}

void CTypeCheckerVisitor::visit( const CMethodDecl* methodDecl )
{
	curMethod = curClass->GetMethod( methodDecl->Name()->GetString() );
	methodDecl->Type()->Accept( this );

	if (methodDecl->FormalList() != nullptr) {
		methodDecl->FormalList()->Accept( this );
	}
	if (methodDecl->VarDeclList() != nullptr) {
		methodDecl->VarDeclList()->Accept( this );
	}
	if (methodDecl->StatementList() != nullptr) {
		methodDecl->StatementList()->Accept( this );
	}
}


void CTypeCheckerVisitor::visit( const CUserType* type )
{
	_lastTypeValue = type->Type()->GetString();
}

void CTypeCheckerVisitor::visit( const CType* type )
{
	_lastTypeValue = type->StringType();
}

void CTypeCheckerVisitor::visit( const CArrayAssignStatement* statement )
{
	SymbolsTable::CVarInfo* var = curMethod->GetVar( statement->ArrayName()->GetString() );
	statement->RightPart()->Accept( this );
	if ("int" != _lastTypeValue) {
		std::cout << "CArrayAssignStatement Incompatible types" << std::endl;
	}
}

void CTypeCheckerVisitor::visit( const CAssignStatement* statement )
{
	SymbolsTable::CVarInfo* var = curMethod->GetVar( statement->LeftPart()->GetString() );
	statement->RightPart()->Accept( this );
	if (var == nullptr) {
		std::cout << "Undeclared variable" << std::endl;
	} else if (var->GetType()->StringType() != _lastTypeValue) {
		std::cout << "CAssignStatement Incompatible types" << std::endl;
	}
}

void CTypeCheckerVisitor::visit( const CIfStatement* statement )
{
	statement->Condition()->Accept( this );

	if (_lastTypeValue != "boolean") {
		std::cout << "IfStatement has not boolean type" << std::endl;
	}

	if (statement->IfTrueStatement() != nullptr) {
		statement->IfTrueStatement()->Accept( this );
	}
	if (statement->IfFalseStatement() != nullptr) {
		statement->IfFalseStatement()->Accept( this );
	}
}

void CTypeCheckerVisitor::visit( const CWhileStatement* statement )
{
	statement->Condition()->Accept( this );

	if (_lastTypeValue != "boolean") {
		std::cout << "Not boolean expression in while" << std::endl;
	}

	if (statement->BodyCycle() != nullptr) {
		statement->BodyCycle()->Accept( this );
	}
}

void CTypeCheckerVisitor::visit( const CPrintStatement* statement )
{
	statement->Expression()->Accept( this );

	if (_lastTypeValue != "int") {
		std::cout << "Wrong type in println " << _lastTypeValue;
	}
}

void CTypeCheckerVisitor::visit( const CBinOpExpression* expr )
{
	expr->LeftExp()->Accept( this );
	auto left = _lastTypeValue;
	expr->RightExp()->Accept( this );
	auto right = _lastTypeValue;

	if (expr->BinOp() == CBinOpExpression::MINUS || expr->BinOp() == CBinOpExpression::PLUS ||
		expr->BinOp() == CBinOpExpression::TIMES || expr->BinOp() == CBinOpExpression::DIVIDE) {
		if (left != "int" || right != "int") {
			std::cout << "Errors in types of ifexpressions";
		}
		_lastTypeValue = "int";
	}
	if (expr->BinOp() == CBinOpExpression::AND) {
		if (left != "boolean" || right != "boolean") {
			std::cout << "Errors in types of ifexpressions";
		}
		_lastTypeValue = "boolean";
	}
	if (expr->BinOp() == CBinOpExpression::LESS) {
		if (left != "int" || right != "int") {
			std::cout << "Errors in types of ifexpressions";
		}
		_lastTypeValue = "boolean";
	}
}

void CTypeCheckerVisitor::visit( const CIndexExpression* expr )
{
	expr->Exp()->Accept( this );
	if (_lastTypeValue != "int[]") {
		std::cout << "Index only for int[]";
	}

	expr->IndexExp()->Accept( this );

	if (_lastTypeValue != "int") {
		std::cout << "You need int for index";
	}

	_lastTypeValue = "int";
}

void CTypeCheckerVisitor::visit( const CLenghtExpression* expr )
{
	expr->Exp()->Accept( this );

	if (_lastTypeValue != "int[]") {
		std::cout << "Wrong type! you need int[]";
	}

	_lastTypeValue = "int";
}
//problem with itype
void CTypeCheckerVisitor::visit( const CMethodExpression* expr )
{
	expr->Exp()->Accept( this );
	std::string expName = _lastTypeValue;
	if (isPODType( expName )) {
		std::cout << "Can't call method with pod type" << std::endl;
		error = true;
	}
	std::string methodName = expr->Id()->GetString();
	const SymbolsTable::CClassInfo* expInfo = symbolsTable->GetClass( expName );
	if (expInfo->GetMethod( methodName ) == nullptr) {
		std::cout << "No method with such name" << std::endl;
		error = true;
	}
	currMethodCall.push( expInfo->GetMethod( methodName ) );
	numOfArgument.push( 0 );
	expr->IndexExp()->Accept( this ); // Разбор аргументов метода
	_lastTypeValue = currMethodCall.top()->GetReturnType()->GetName(); // Запомнием последний тип
	currMethodCall.pop();
	numOfArgument.pop();
}

void CTypeCheckerVisitor::visit( const CIntLiteralExpression* expr )
{
	_lastTypeValue = "int";
}

void CTypeCheckerVisitor::visit( const CBoolLiteralExpression* expr )
{
	_lastTypeValue = "boolean";
}

//problem with Itype
void CTypeCheckerVisitor::visit( const CIdentifierExpression* expr )
{
	if (curMethod->GetVar( expr->Id()->GetString() ) != nullptr) {
		auto varInfo = curMethod->GetVar( expr->Id()->GetString() );
		_lastTypeValue = varInfo->GetType()->StringType();
	}
	else if (curClass->GetVar( expr->Id()->GetString() ) != nullptr) {
		_lastTypeValue = curClass->GetVar( expr->Id() ->GetString())->GetType()->StringType();
	}
	else {
		std::cout << "Undeclared variable " << expr->Id() << std::endl;
		error = true;
	}
}

void CTypeCheckerVisitor::visit( const CThisExpression* expr )
{
	_lastTypeValue = curClass->GetName();
}

void CTypeCheckerVisitor::visit( const CNewIntArrayExpression* expr )
{
	expr->Exp()->Accept( this );

	if (_lastTypeValue != "int") {
		std::cout << "Wrong type! You need int[]";
	}

	_lastTypeValue = "int[]";
}

void CTypeCheckerVisitor::visit( const CNewExpression* expr )
{
	_lastTypeValue = expr->Id()->GetString();

	if (symbolsTable->GetClass( _lastTypeValue ) == nullptr) {
		std::cout << "Bad type" << std::endl;
		error = true;
	}
}

void CTypeCheckerVisitor::visit( const CUnaryOpExpression* expr )
{
	if (expr->Op() == CUnaryOpExpression::MINUS) {
		expr->Exp()->Accept( this );
		if (_lastTypeValue != "int") {
			std::cout << "CUnaryOpExpression int";
		}
		else {
			_lastTypeValue = "int";
		}
	}

	if (expr->Op() == CUnaryOpExpression::NOT) {
		expr->Exp()->Accept( this );
		if (_lastTypeValue != "boolean") {
			std::cout << "CUnaryOpExpression boolean";
		}
		else {
			_lastTypeValue = "boolean";
		}
	}
}

void CTypeCheckerVisitor::visit( const CBracesExpression* expr )
{
	if (expr->Exp() != nullptr) {
		expr->Exp()->Accept( this );
	}
}

void CTypeCheckerVisitor::visit( const CExpList* exprList )
{
	if (exprList->Exp()) {
		exprList->Exp()->Accept( this );
		if (currMethodCall.top()->GetParamByNumber( numOfArgument.top() ) == nullptr) { // сюда зашло, если хотя бы 1 аргумент передали в метод
			std::cout << "Type mismatch: " << numOfArgument.top() + 1 << " argument of " << currMethodCall.top()->GetName() << std::endl;
			error = true;
		}
		else
			if (_lastTypeValue != currMethodCall.top()->GetParamByNumber( numOfArgument.top() )->GetType()->StringType()) {
				std::cout << "Type mismatch: " << numOfArgument.top() + 1 << " argument of " << currMethodCall.top()->GetName() << std::endl;
				error = true;
			}
		int num = numOfArgument.top() + 1;
		numOfArgument.pop();
		numOfArgument.push( num );
		return;
	}

	if (exprList->ExpList() != nullptr)
	{
		exprList->ExpList()->Accept( this );
	}
	
	if (exprList->ExpRest() != nullptr)
	{
		exprList->ExpRest()->Accept( this );
	}
}

void CTypeCheckerVisitor::visit( const CStatementList* stmtList )
{
	if (stmtList->Statement() != nullptr) {
		stmtList->Statement()->Accept( this );
	}
	if (stmtList->StatementList() != nullptr) {
		stmtList->StatementList()->Accept( this );
	}
}

void CTypeCheckerVisitor::visit( const CExpRest* expr )
{
	if (expr->Exp() != nullptr) {
		expr->Exp()->Accept( this );
		if (currMethodCall.top()->GetParamByNumber( numOfArgument.top() ) == nullptr) { // сюда зашло, если хотя бы 1 аргумент передали в метод
			std::cout << "Type mismatch: " << numOfArgument.top() + 1 << " argument of " << currMethodCall.top()->GetName() << std::endl;
			error = true;
		}
		else
			if (_lastTypeValue != currMethodCall.top()->GetParamByNumber( numOfArgument.top() )->GetType()->StringType()) {
				std::cout << "Type mismatch: " << numOfArgument.top() + 1 << " argument of " << currMethodCall.top()->GetName() << std::endl;
				error = true;
			}
		int num = numOfArgument.top() + 1;
		numOfArgument.pop();
		numOfArgument.push( num );
	}
}

void CTypeCheckerVisitor::visit( const CMethodDeclList* methodList )
{
	if (methodList->MethodDecl() != nullptr) {
		methodList->MethodDecl()->Accept( this );
	}
	if (methodList->MethodDeclList() != nullptr) {
		methodList->MethodDeclList()->Accept( this );
	}
}