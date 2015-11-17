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
	if (curClass == nullptr) {
		std::cout << "CVarDecl Error";
		return;
	}
	varDecl->Type()->Accept( this );

	std::string lastType = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (!isPODType( lastType ) && symbolsTable->GetClass( lastType ) == nullptr) {
		std::cout << "CVarDecl Error isPODType";
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
	if (curClass == nullptr) {
		std::cout << "CMethodDecl Error";
		return;
	}
	curMethod = curClass->GetMethod( methodDecl->Name()->GetString() );
	methodDecl->Type()->Accept( this );

	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (!isPODType( lastTypeValue ) && symbolsTable->GetClass( lastTypeValue ) == nullptr) {
		std::cout << "CMethodDecl Error isPODType";
	}

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
	lastTypeValueStack.push_back( type->Type()->GetString() );
}


void CTypeCheckerVisitor::visit( const CArrayAssignStatement* statement )
{
	if (curClass == nullptr || curMethod == nullptr) {
		std::cout << "CArrayAssignStatement";
		return;
	}

	SymbolsTable::CVarInfo* var = curMethod->GetVar( statement->ArrayName()->GetString() );
	statement->RightPart()->Accept( this );
	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if ("int" != lastTypeValue) {
		std::cout << "CArrayAssignStatement Incompatible types";
	}
}

void CTypeCheckerVisitor::visit( const CAssignStatement* statement )
{
	if (curClass == nullptr || curMethod == nullptr) {
		std::cout << "CAssignStatement";
		return;
	}

	SymbolsTable::CVarInfo* var = curMethod->GetVar( statement->LeftPart()->GetString() );
	statement->RightPart()->Accept( this );
	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (var->GetType()->StringType() != lastTypeValue) {
		std::cout << "CAssignStatement Incompatible types";
	}
}

void CTypeCheckerVisitor::visit( const CIfStatement* statement )
{
	if (curClass == nullptr || curMethod == nullptr) {
		std::cout << "CIfStatement";
		//errorStorage.PutError( "If statement out of scope " + statement->GetPosition().ToString() );
		return;
	}

	statement->Condition()->Accept( this );

	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (lastTypeValue != "boolean") {
		/*errorStorage.PutError( std::string( "[Type check] Node type - CIfStatement. " ) +
			"Expression of type " + lastTypeValue + " cannot be used as condition. " +
			"Line " + std::to_string( statement->GetPosition().GetBeginPos().first ) +
			", column " + std::to_string( statement->GetPosition().GetBeginPos().second ) + "." );*/
		std::cout << "CIfStatepent boolean";
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
	if (curClass == nullptr || curMethod == nullptr) {
		std::cout << "CWhileStatement";
		return;
	}

	statement->Condition()->Accept( this );

	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (lastTypeValue != "boolean") {
		std::cout << "CWhileStatement boolean";
	}

	if (statement->BodyCycle() != nullptr) {
		statement->BodyCycle()->Accept( this );
	}
}

void CTypeCheckerVisitor::visit( const CPrintStatement* statement )
{
	if (curClass == nullptr || curMethod == nullptr) {
		std::cout << "CPrintStatement";
		return;
	}

	statement->Expression()->Accept( this );

	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (lastTypeValue != "int") {
		std::cout << "CPrintStatement int";
	}
}

void CTypeCheckerVisitor::visit( const CBinOpExpression* expr )
{
	if (curClass == nullptr || curMethod == nullptr) {
		std::cout << "CBinOpExpression";
		lastTypeValueStack.push_back( "boolean" );
		return;
	}

	expr->LeftExp()->Accept( this );
	auto left = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	expr->RightExp()->Accept( this );
	auto right = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();

	if (expr->BinOp() == CBinOpExpression::MINUS || expr->BinOp() == CBinOpExpression::PLUS ||
		expr->BinOp() == CBinOpExpression::TIMES || expr->BinOp() == CBinOpExpression::DIVIDE) {
		if (left != "int" || right != "int") {
			std::cout << "CBinOpExpression int int";
		}
		lastTypeValueStack.push_back( "int" );
	}
	if (expr->BinOp() == CBinOpExpression::AND) {
		if (left != "boolean" || right != "boolean") {
			std::cout << "CBinOpExpression boolean";
		}
		lastTypeValueStack.push_back( "boolean" );
	}
	if (expr->BinOp() == CBinOpExpression::LESS) {
		if (left != "int" || right != "int") {
			std::cout << "CBinOpExpression int int second";
		}
		lastTypeValueStack.push_back( "boolean" );
	}
}

void CTypeCheckerVisitor::visit( const CIndexExpression* expr )
{
	if (curClass == nullptr || curMethod == nullptr) {
		std::cout << "CIndexExpression";
		lastTypeValueStack.push_back( "int" );
		return;
	}

	expr->Exp()->Accept( this );
	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (lastTypeValue != "int[]") {
		std::cout << "CIndexExpression int[]";
	}

	expr->IndexExp()->Accept( this );
	lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (lastTypeValue != "int") {
		std::cout << "CIndexExpression int";
	}

	lastTypeValueStack.push_back( "int" );
}

void CTypeCheckerVisitor::visit( const CLenghtExpression* expr )
{
	if (curClass == nullptr || curMethod == nullptr) {
		std::cout << "CLengthExpression";
		lastTypeValueStack.push_back( "int" );
		return;
	}

	expr->Exp()->Accept( this );

	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (lastTypeValue != "int[]") {
		std::cout << "CLengthExpression int[]";
	}

	lastTypeValueStack.push_back( "int" );
}
//problem with itype
void CTypeCheckerVisitor::visit( const CMethodExpression* expr )
{
	expr->Exp()->Accept( this );
	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	SymbolsTable::CClassInfo* usedClass = symbolsTable->GetClass( lastTypeValue );
	if (usedClass == nullptr) {
		std::cout << "CMethodExpression usedClass";
		lastTypeValueStack.push_back( "int" );
	}
	else {
		SymbolsTable::CMethodInfo* usedMethod = usedClass->GetMethod( expr->Id()->GetString() );
		if (expr->IndexExp() != nullptr) {
			int typeValuePointer = lastTypeValueStack.size();
			expr->IndexExp()->Accept( this );
			auto params = usedMethod->GetParams();
			if (lastTypeValueStack.size() - typeValuePointer != params.size()) {
				std::cout << "CMethodExpression else";
			}
			for (int i = typeValuePointer; i < lastTypeValueStack.size(); ++i) {
				if (params[i - typeValuePointer]->GetType()->StringType() != lastTypeValueStack[i]) {
					std::cout << "CMethodExpression else for";
				}
			}
			for (int i = 0, size = lastTypeValueStack.size() - typeValuePointer; i < size; ++i) {
				lastTypeValueStack.pop_back();
			}
		}
		else {
			auto params = usedMethod->GetParams();
			if (params.size() != 0) {
				std::cout << "CMethodExpression second else";
			}
		}
		lastTypeValueStack.push_back( usedMethod->GetReturnType()->GetName() );
	}
}

void CTypeCheckerVisitor::visit( const CIntLiteralExpression* expr )
{
	lastTypeValueStack.push_back( "int" );
}

void CTypeCheckerVisitor::visit( const CBoolLiteralExpression* expr )
{
	lastTypeValueStack.push_back( "boolean" );
}

//problem with Itype
void CTypeCheckerVisitor::visit( const CIdentifierExpression* expr )
{
	if (curClass == nullptr) {
		std::cout << "CIdentifierExpression";
		lastTypeValueStack.push_back( "int" );
		return;
	}

	if (curMethod == nullptr) {
		auto varInfo = curClass->GetVar( expr->Id()->GetString() );
		if (varInfo == nullptr) {
			std::cout << "CIdentifierExpression varInfo";
			lastTypeValueStack.push_back( "int" );
			return;
		}
		lastTypeValueStack.push_back( varInfo->GetType()->StringType() );
		return;
	}

	auto varInfo = curMethod->GetVar( expr->Id()->GetString() );
	if (varInfo == nullptr) {
		varInfo = curClass->GetVar( expr->Id()->GetString() );
		if (varInfo == nullptr) {
			std::cout << "CIdentifierExpression varInfo";
			lastTypeValueStack.push_back( "int" );
			return;
		}
	}
	lastTypeValueStack.push_back( varInfo->GetType()->StringType() );
}

void CTypeCheckerVisitor::visit( const CThisExpression* expr )
{
	if (curClass == nullptr) {
		std::cout << "CThisExpression";
		lastTypeValueStack.push_back( curClass->GetName() );
		return;
	}
	lastTypeValueStack.push_back( curClass->GetName() );
}

void CTypeCheckerVisitor::visit( const CNewIntArrayExpression* expr )
{
	if (curClass == nullptr || curMethod == nullptr) {
		std::cout << "CNewIntArrayExpression";
		lastTypeValueStack.push_back( "int[]" );
		return;
	}

	expr->Exp()->Accept( this );

	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (lastTypeValue != "int") {
		std::cout << "CNewIntArrayExpression int";
	}

	lastTypeValueStack.push_back( "int[]" );
}

void CTypeCheckerVisitor::visit( const CNewExpression* expr )
{
	if (curClass == nullptr || curMethod == nullptr) {
		std::cout << "CNewExpression";
		if (expr->Id() != nullptr) {
			lastTypeValueStack.push_back( expr->Id()->GetString() );
		}
		else {
			lastTypeValueStack.push_back( "int" );
		}
		return;
	}

	if (symbolsTable->GetClass( expr->Id()->GetString() ) == nullptr) {
		std::cout << "CNewExpression second";
	}

	lastTypeValueStack.push_back( expr->Id()->GetString() );
}

//No LeftExp CUnaryOpExpression
void CTypeCheckerVisitor::visit( const CUnaryOpExpression* expr )
{
	if (curClass == nullptr || curMethod == nullptr) {
		//errorStorage.PutError( "Expression out of scope " + expr->GetPosition().ToString() );
		std::cout << "CUnaryOpExpression";
		lastTypeValueStack.push_back( "int" );
		return;
	}

//	expr->LeftExp()->Accept( this );

	std::string lastTypeValue = lastTypeValueStack.back();
	lastTypeValueStack.pop_back();
	if (expr->Op() == CUnaryOpExpression::MINUS) {
		if (lastTypeValue != "int") {
			std::cout << "CUnaryOpExpression int";
		}
		else {
			lastTypeValueStack.push_back( "int" );
		}
	}

	if (expr->Op() == CUnaryOpExpression::NOT) {
		if (lastTypeValue != "boolean") {
			std::cout << "CUnaryOpExpression boolean";
		}
		else {
			lastTypeValueStack.push_back( "boolean" );
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
	if (exprList->Exp() != nullptr) {
		exprList->Exp()->Accept( this );
	}
	if (exprList->ExpList() != nullptr) {
		exprList->ExpList()->Accept( this );
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

