#pragma once
#include "IRForestBuilder.h"
#include "../Visitor.h"
//#include "StmConverter.h"
#include "ConditionalWrapper.h"

#include <iostream>
#include <string>
#include <stack>

namespace Translate {

void CIRForestBuilder::visit( const CProgram* program )
{
	// ����� ��� IRTree ������ �� �����
	program->MainClass()->Accept( this );
	if( program->ClassDeclList() != 0 ) {
		program->ClassDeclList()->Accept( this );
	}
}

void CIRForestBuilder::visit( const CMainClass* mainClass )
{
	// ���������� � ����� �� ������
	className = mainClass->ClassName()->GetString();
	// � main ��� ������� ����������, ������ ��� ����� ����������
	// ��������� ����� ����� ������ ���� ������� ��������� ������ ������ ������ ������
	// �������� System.out.println( new Pr1() );
	currentFrame = new Frame::CFrame( className + "__main" );
	if( mainClass->Statement() != 0 ) {
		mainClass->Statement()->Accept( this );
	}
	currentFrame->Stm = lastReturnedStm;
	lastReturnedStm = nullptr;
	lastReturnedExp = nullptr;
	Methods.push_back( currentFrame );
	// ������� ���� � ������� ������
	currentFrame = 0;
	className = "";
}

void CIRForestBuilder::visit( const CClassDeclsList* classDeclList )
{
	// ����� ��� IRTree ������ �� �����
	classDeclList->ClassDecls()->Accept( this );
	if ( classDeclList->ClassDeclsList() != 0 ) {
		classDeclList->ClassDeclsList()->Accept( this );
	}
}

void CIRForestBuilder::visit( const CClassDecls* classDecl )
{
	// ���������� � ����� �� ������
	className = classDecl->ClassName()->GetString();
	if( classDecl->VarDeclList() != 0 ) {
		classDecl->VarDeclList()->Accept( this );
	}
	if( classDecl->MethodDeclList() != 0 ) {
		classDecl->MethodDeclList()->Accept( this );
	}
	lastReturnedExp = nullptr;
	lastReturnedStm = nullptr;
	className = "";
}

void CIRForestBuilder::visit( const CVarDeclList* varDeclList )
{
	// ����� ��� IRTree ������ �� �����	
	varDeclList->VarDecl()->Accept( this );
	if ( varDeclList->VarDeclList() != 0 ) {
		varDeclList->VarDeclList()->Accept( this );
	}
}

void CIRForestBuilder::visit( const CVarDecl* varDecl )
{
	varDecl->Type()->Accept( this );
}

void CIRForestBuilder::visit( const CMethodDeclList* methodDeclList )
{	
	methodDeclList->MethodDecl()->Accept( this );
	if ( methodDeclList->MethodDeclList() != 0 ) {
		methodDeclList->MethodDeclList()->Accept( this );
	}
}

void CIRForestBuilder::visit( const CMethodDecl* methodDecl )
{
	// ��� ��� �� ����������, ��� ���� � ������� ��������
	methodDecl->Type()->Accept( this );
	if( methodDecl->FormalList() != 0 ) {
		methodDecl->FormalList()->Accept( this );
	}
	if( methodDecl->VarDeclList() != 0 ) {
		methodDecl->VarDeclList()->Accept( this );
	}
	// ������ �����
	currentFrame = new Frame::CFrame( className + "__" + methodDecl->Name()->GetString() );
	std::vector<const SymbolsTable::CClassInfo*> classNames;
	const SymbolsTable::CClassInfo* currentClass = symbolsTable->GetClass( className );
	while( currentClass != nullptr ) {
		classNames.push_back( currentClass );
		if( currentClass->GetBaseClass() ) {
			currentClass = currentClass->GetBaseClass();
		} else {
			currentClass = nullptr;
		}
	}
	// ��������� ���� ������ � ������ symbolsTable.GetClass( className )
	for( int i = classNames.size() - 1; i >= 0; i-- ) {
		for( const auto& field : classNames.at( i )->GetVars() ) {
			currentFrame->AddField( field->GetName(), new Frame::CInObject( currentFrame->ThisCounter ) );
			currentFrame->ThisCounter++;
		}
	}

	std::vector<std::shared_ptr<SymbolsTable::CVarInfo> > params ;
	std::vector<std::shared_ptr<SymbolsTable::CVarInfo> > locals ;
	for( auto& method : symbolsTable->GetClass( className )->GetMethods() ) {
		if( method->GetName() == methodDecl->Name()->GetString() ) {
			params = method->GetParams();
			locals = method->GetLocals();
			break;
		}
	}
	
	// ��������� ��������� ������� ������
	for( size_t i = 0; i < params.size(); ++i ) {
		currentFrame->AddField( params.at( i )->GetName(), new Frame::CFormalParameterInStack( i + 1 ) );
	}
	// ��������� ��������� ���������� ������
	for( size_t i = 0; i < locals.size(); ++i ) {
		currentFrame->AddField( locals.at( i )->GetName(), new Frame::CInFrame( currentFrame->LocalCounter ) );
		currentFrame->LocalCounter++;
	}
	IRTree::IStm* stm;
	if( methodDecl->StatementList() != 0 ) {
		methodDecl->StatementList()->Accept( this );
		stm = lastReturnedStm;
		lastReturnedStm = nullptr;
	}
	IRTree::IStm* methodStm;
	if( methodDecl->Exp() != 0 ) {
		// ��� ������������ ������������ ��������
		// ��������� lastReturnedExp � �������, ���� ��� ����
		methodDecl->Exp()->Accept( this );
		IRTree::IExp* returnedExp = lastReturnedExp;
		if( returnedExp != nullptr ) {
			IRTree::IStm* moveResult = new IRTree::CMove( new IRTree::CTemp( *currentFrame->ReturnValue() ), returnedExp );
			methodStm = moveResult;
			if( stm != nullptr ) {
				// lastReturnedStm = new IRTree::CSeq( stm, new IRTree::CMove( new IRTree::CTemp( *currentFrame->ReturnValue() ), lastReturnedExp ) );
				methodStm = new IRTree::CSeq( stm, moveResult );
			} 
			
		}
	}
	currentFrame->Stm = methodStm;
	Methods.push_back( currentFrame );
	currentFrame = nullptr;
	lastReturnedStm = nullptr;
	lastReturnedExp = nullptr;
}

void CIRForestBuilder::visit( const CFormalList* formalList )
{
	// ��� ���� � ������� ��������
	// ��� ��� ������ ������
	formalList->Type()->Accept( this );
	if( formalList->FormalRest() != nullptr )
	{
		formalList->FormalRest()->Accept( this );
	}
}

void CIRForestBuilder::visit( const CType* type )
{
	// ����� ��� IRTree ������ �� �����
	// ��� � ������� ��������
}

void CIRForestBuilder::visit( const CStatementList* statementList )
{
	// �������������� ��� ���� ���� �����-�� statement
	IRTree::IStm* listOfStm = nullptr;
	// ��������� ������
	statementList->Statement()->Accept( this );
	listOfStm = lastReturnedStm;
	lastReturnedStm = nullptr;
	lastReturnedExp = nullptr;
	if( statementList->StatementList() == nullptr ) {
		lastReturnedStm = listOfStm;
		return;
	} else {
		statementList->StatementList()->Accept( this );
		IRTree::IStm* statementToAdd = 0;
		if( lastReturnedStm == nullptr ) {
			// ��� ����� ������ IStm 
			statementToAdd = new IRTree::CExp( lastReturnedExp );
		} else {
			statementToAdd = lastReturnedStm;
		}
		listOfStm = new IRTree::CSeq( listOfStm, statementToAdd );
		lastReturnedStm = nullptr;
		lastReturnedExp = nullptr;
	
		lastReturnedStm = listOfStm;
	}
}

void CIRForestBuilder::visit( const CArrayAssignStatement* assignStatement )
{
	IRTree::IExp* leftExp = const_cast<IRTree::IExp*>( currentFrame->GetAccess( assignStatement->ArrayName()->GetString() )->ToExp( currentFrame ) );
	assignStatement->ElementNumber()->Accept( this );
	IRTree::IExp* indexDeFacto = new IRTree::CBinop( IRTree::B_Plus, lastReturnedExp , new IRTree::CConst( 1 ) );
	IRTree::IExp* realSize = new IRTree::CBinop( IRTree::B_Mul, indexDeFacto, new IRTree::CConst(  currentFrame->WordSize() ) );
		
	leftExp = new IRTree::CBinop( IRTree::B_Plus, new IRTree::CMem( leftExp ), realSize );
	leftExp = new IRTree::CMem( leftExp );
	assignStatement->RightPart()->Accept( this );
	IRTree::IExp* rightExp = lastReturnedExp;
	lastReturnedExp = nullptr;
	lastReturnedStm = new IRTree::CMove( leftExp, rightExp );
}

void CIRForestBuilder::visit( const CAssignStatement* assignStatement )
{
	IRTree::IExp* leftExp = const_cast<IRTree::IExp*>( currentFrame->GetAccess( assignStatement->LeftPart()->GetString() )->ToExp( currentFrame ) );
	assignStatement->RightPart()->Accept( this );
	IRTree::IExp* rightExp = lastReturnedExp;
	lastReturnedExp = nullptr;
	lastReturnedStm = new IRTree::CMove( leftExp, rightExp );
}

void CIRForestBuilder::visit( const CPrintStatement* printStatement )
{
	// ��������� �� ��� ���� ����������
	printStatement->Expression()->Accept( this );
	IRTree::IExp* exprForPrint = lastReturnedExp;
	lastReturnedExp = nullptr;
	lastReturnedStm = nullptr;
	// �������� �������
	Temp::CLabel* funcName = new Temp::CLabel( "println" );
	IRTree::CName* funcNameTree = new IRTree::CName( funcName );
	IRTree::CExpList* args = new IRTree::CExpList( exprForPrint, nullptr );
	IRTree::IExp* funcCall = new IRTree::CCall( funcNameTree, args );
	lastReturnedStm = new IRTree::CExp( funcCall );
}

void CIRForestBuilder::visit( const CIfStatement* ifStatement )
{
	ifStatement->Condition()->Accept( this );
	const IRTree::IExp* ifExpr = lastReturnedExp;
	lastReturnedExp = nullptr;
	lastReturnedStm = nullptr;

	Temp::CLabel* trueLabelTemp = new Temp::CLabel();
	Temp::CLabel* falseLabelTemp = new Temp::CLabel();
	Temp::CLabel* endLabelTemp = new Temp::CLabel();
	IRTree::CLabel* trueLabel = new IRTree::CLabel( trueLabelTemp );
	IRTree::CLabel* falseLabel = new IRTree::CLabel( falseLabelTemp );
	IRTree::CLabel* endLabel = new IRTree::CLabel( endLabelTemp );

	IRTree::CJump* trueJumpToEnd = new IRTree::CJump( endLabelTemp );
	ifStatement->IfTrueStatement()->Accept( this );
	IRTree::IStm* trueStm = new IRTree::CSeq( trueLabel, lastReturnedStm, trueJumpToEnd );
	lastReturnedExp = nullptr;
	lastReturnedStm = nullptr;
	IRTree::IStm* falseStm = 0;
	if( ifStatement->IfFalseStatement() != 0 ) {
		ifStatement->IfFalseStatement()->Accept( this );
		IRTree::CJump* falseJumpToEnd = new IRTree::CJump( endLabelTemp );
		falseStm = new IRTree::CSeq( falseLabel, lastReturnedStm, falseJumpToEnd );
		lastReturnedExp = nullptr;
		lastReturnedStm = nullptr;
	}
	Translate::CConditionalWrapper wrapper( ifExpr );
	lastReturnedStm = new IRTree::CSeq( const_cast<IRTree::IStm*>( wrapper.ToConditional( trueLabelTemp, falseLabelTemp ) ), trueStm, falseStm, endLabel );
}

void CIRForestBuilder::visit( const CWhileStatement* whileStatement )
{
	Temp::CLabel* beforeConditionLabelTemp = new Temp::CLabel();
	Temp::CLabel* inLoopLabelTemp = new Temp::CLabel();
	Temp::CLabel* endLabelTemp = new Temp::CLabel();
	IRTree::CLabel* beforeConditionLabel = new IRTree::CLabel( beforeConditionLabelTemp );
	IRTree::CLabel* inLoopLabel = new IRTree::CLabel( inLoopLabelTemp );
	IRTree::CLabel* endLabel = new IRTree::CLabel( endLabelTemp );
	whileStatement->Condition()->Accept( this );
	Translate::CConditionalWrapper converter( lastReturnedExp );
	IRTree::IStm* whileStm = const_cast<IRTree::IStm*>( converter.ToConditional( inLoopLabelTemp, endLabelTemp ) );
	lastReturnedExp = nullptr;
	lastReturnedStm = nullptr;
	IRTree::IStm* conditionStm = new IRTree::CSeq( beforeConditionLabel, whileStm, inLoopLabel );
	whileStatement->Condition()->Accept( this );
	lastReturnedStm = new IRTree::CSeq( conditionStm, lastReturnedStm, 
		new IRTree::CJump( beforeConditionLabelTemp ), endLabel );
	lastReturnedExp = nullptr;
}

void CIRForestBuilder::visit( const CExpList* expList )
{
	IRTree::CExpList* irExpList = nullptr;
	expList->Exp()->Accept( this );
	irExpList = new IRTree::CExpList( lastReturnedExp, irExpList );
	lastReturnedExpList = irExpList;
	if ( expList->ExpList() != 0 ) 
	{
		expList->ExpList()->Accept( this );
		irExpList = new IRTree::CExpList( lastReturnedExp, irExpList );
		lastReturnedExpList = irExpList;
	}
}

void CIRForestBuilder::visit( const CBinOpExpression* exp )
{
	// �������� ������ � ����� ��������
	exp->LeftExp()->Accept( this );
	IRTree::IExp* first = lastReturnedExp;
	exp->RightExp()->Accept( this );
	IRTree::IExp* second = lastReturnedExp;
	IRTree::BINOP_ENUM binOp;
	switch( exp->BinOp() ) { 
	case CBinOpExpression::EBinOp::PLUS:
			binOp = IRTree::B_Plus;
			break;
		case CBinOpExpression::EBinOp::MINUS:
			binOp = IRTree::B_Minus;
			break;
		case CBinOpExpression::EBinOp::TIMES:
			binOp = IRTree::B_Mul;
			break;
		case CBinOpExpression::EBinOp::DIVIDE:
			binOp = IRTree::B_Division;
			break;
		/*case CBinOpExpression::EBinOp:::
			binOp = IRTree::B_Xor;
			break;*/
		case CBinOpExpression::EBinOp::LESS:
			binOp = IRTree::B_Less;
			break;
		/*case CBinOpExpression::EBinOp:::
			binOp = IRTree::B_Greater;
			break;*/
		case CBinOpExpression::EBinOp::AND:
			binOp = IRTree::B_And;
			break;
	}
	// ����� �� ��� ����� �� first, second � ��������� �������� ��������
	lastReturnedExp = new IRTree::CBinop( binOp, first, second );
}

void CIRForestBuilder::visit( const CUnaryOpExpression* exp )
{
	// �������� �� (0 - exp)
	IRTree::IExp* first = new IRTree::CConst( 0 );
	exp->Exp()->Accept( this );
	IRTree::IExp* second = lastReturnedExp;
	// ���������� binop
	lastReturnedExp = new IRTree::CBinop( IRTree::B_Minus, first, second );
}

void CIRForestBuilder::visit( const CIndexExpression* exp )
{
	exp->Exp()->Accept( this );
	IRTree::IExp* varExp = lastReturnedExp;
	exp->IndexExp()->Accept( this );
	// � 0� �������� ����� ������ �������
	IRTree::IExp* indexExp = new IRTree::CBinop( IRTree::B_Plus, lastReturnedExp, new IRTree::CConst( 1 ) );
	IRTree::IExp* offset = new IRTree::CBinop( IRTree::B_Mul, new IRTree::CConst( Frame::CFrame::WordSize() ), indexExp );
	// ���������� �������� ����������
	lastReturnedExp = new IRTree::CMem( new IRTree::CBinop( IRTree::B_Plus, new IRTree::CMem( varExp ), offset ) );
}

void CIRForestBuilder::visit( const CLenghtExpression* exp )
{
	// �� ����� ���������� ��� �������� ������ ������� �������, �� ������ ����������� �� ������������ ��� ���������
	exp->Exp()->Accept( this );
	IRTree::IExp* varExp = lastReturnedExp;
	// ���������� �����
	lastReturnedExp = new IRTree::CMem( varExp );
}

/*
void CIRForestBuilder::visit( const CExpIdVoidExpList* exp )
{
	// ����� ������� ��� ����������
	// ��������� ��������� � �������� ���� ��������� �����
	auto findResult = nodesTypesLog.find( reinterpret_cast< const void * >( &exp ) );
	assert( findResult != nodesTypesLog.end() );
	std::string typeName = findResult->second;

	exp.Exp()->Accept( this );
	const IRTree::IExp* exprToBeCalled = lastReturnedExp;
	lastReturnedExp = nullptr;
	// ��� ������ ����� ������� ���� �������
	std::string methodName = exp.Id();
	Temp::CLabel* functionLabel = new Temp::CLabel( typeName + "__" + methodName );
	IRTree::CName* functionName = new IRTree::CName( functionLabel );
	const IRTree::CExpList* args = new IRTree::CExpList( exprToBeCalled, nullptr );
	const IRTree::CTemp* returnedTemp = new IRTree::CTemp( *currentFrame->ReturnValue() );
	lastReturnedExp = new IRTree::CEseq( new IRTree::CMove( returnedTemp, new IRTree::CCall( functionName, *args ) ), returnedTemp );
}
*/
void CIRForestBuilder::visit( const CIntLiteralExpression* exp )
{
	lastReturnedExp = new IRTree::CConst( stoi(exp->Value()->GetString()) );
}

void CIRForestBuilder::visit( const CBoolLiteralExpression* exp )
{
	lastReturnedExp = new IRTree::CConst( exp->Value()->GetString() == "0" ? 0 : 1);
}

void CIRForestBuilder::visit( const CIdentifierExpression* exp )
{
	// ������ ������ ���� �� ������
	lastReturnedExp = const_cast<IRTree::IExp*>( currentFrame->GetAccess( exp->Id()->GetString() )->ToExp( currentFrame ) );
}

void CIRForestBuilder::visit( const CThisExpression* exp )
{
	lastReturnedExp = const_cast<IRTree::IExp*>( currentFrame->ThisPointerExp() );
}

void CIRForestBuilder::visit( const CNewIntArrayExpression* exp )
{
	exp->Exp()->Accept( this );
	IRTree::IExp* lengthOfArrray = lastReturnedExp;
	IRTree::IExp* lengthDeFacto = new IRTree::CBinop( IRTree::B_Plus, lengthOfArrray, new IRTree::CConst( 1 ) );
	IRTree::IExp* realSize = new IRTree::CBinop( IRTree::B_Mul, lengthDeFacto, new IRTree::CConst( currentFrame->WordSize() ) );
	// �������� ������
	Temp::CLabel* mallocLabel = new Temp::CLabel( "malloc" );
	IRTree::CName* mallocName = new IRTree::CName( mallocLabel );

	IRTree::CExpList* argsMalloc = new IRTree::CExpList( realSize, nullptr );
	IRTree::CCall* mallocCall = new IRTree::CCall( mallocName, argsMalloc );
	// ����e ������ mallocCall ����� ������ ��� � EAX
	IRTree::CTemp* returnedTemp = new IRTree::CTemp( *currentFrame->ReturnValue() );
	// ����������� ������ ������
	Temp::CLabel* memsetLabel = new Temp::CLabel( "memset" );
	IRTree::CName* memsetName = new IRTree::CName( memsetLabel );
	IRTree::CExpList* argMemset = new IRTree::CExpList( returnedTemp, new IRTree::CExpList( realSize, nullptr ) );
	IRTree::CCall* memsetCall = new IRTree::CCall( memsetName, argMemset );

	IRTree::IStm* setLength = new IRTree::CMove( returnedTemp, lengthOfArrray );

	lastReturnedExp = new IRTree::CEseq( new IRTree::CSeq( new IRTree::CExp( mallocCall ), new IRTree::CExp( memsetCall ), setLength ), returnedTemp );
}

void CIRForestBuilder::visit( const CNewExpression* exp )
{
	// �������� ������
	Temp::CLabel* mallocLabel = new Temp::CLabel( "malloc" );

	// ����� ��������� ������� ����� ����� � ������
	IRTree::CName* mallocName = new IRTree::CName( mallocLabel );
	auto classDecriptor = symbolsTable->GetClass( exp->Id()->GetString() );
	// assert( classDecriptor != symbolsTable.Classes().end() );
	int fieldsCount = classDecriptor->GetVars().size();
	
	// ���������� �� �������, ���� ��� ����
	if ( classDecriptor->GetBaseClass() != 0 )
	{
		classDecriptor = symbolsTable->GetClass( classDecriptor->GetBaseClass()->GetName() );
		while( classDecriptor != symbolsTable->classes.end()->get() ) {
			fieldsCount += classDecriptor->GetVars().size();
		}
	}
	// �������� ������ ��� ����� ������ ������ � ��� ����� �������� ������
	// ������ �������� ������ this
	IRTree::IExp* realSize = new IRTree::CConst( fieldsCount * currentFrame->WordSize() );
	IRTree::CExpList* mallocArgs = new IRTree::CExpList( realSize, nullptr );
	IRTree::CCall* mallocCall = new IRTree::CCall( mallocName, mallocArgs );
	IRTree::CTemp* returnedTemp = new IRTree::CTemp( *currentFrame->ReturnValue() );

	// ����������� ������ ������
	Temp::CLabel* memsetLabel = new Temp::CLabel( "memset" );
	IRTree::CName* memsetName = new IRTree::CName( memsetLabel );
	IRTree::CExpList* argMemset = new IRTree::CExpList( returnedTemp, new IRTree::CExpList( realSize, nullptr ) );
	IRTree::CCall* memsetCall = new IRTree::CCall( memsetName, argMemset );

	lastReturnedExp = new IRTree::CEseq( new IRTree::CSeq( new IRTree::CExp( mallocCall ), new IRTree::CExp( memsetCall ) ), returnedTemp );
}

void CIRForestBuilder::visit( const CBracesExpression* exp )
{
	// ����� ��� � ��� ���������, ��� ����������� lastReturnedExp
	exp->Exp()->Accept( this );
}

void CIRForestBuilder::visit( const CFormalRest* exp )
{

}

void CIRForestBuilder::visit( const CUserType* exp )
{

}

void CIRForestBuilder::visit( const CStatement* exp )
{

}

void CIRForestBuilder::visit( const CExpRest* exp )
{

}

void CIRForestBuilder::visit( const CMethodExpression* rule )
{
	if( rule->Exp() != nullptr )
	{
		rule->Exp()->Accept( this );
		IRTree::IExp* varExp = lastReturnedExp;
		lastReturnedStm = nullptr;
		lastReturnedExp = nullptr;

		rule->IndexExp()->Accept( this );
		IRTree::IExp* argExp = lastReturnedExp;
		lastReturnedStm = nullptr;
		lastReturnedExp = nullptr;

		Temp::CLabel* funcName = new Temp::CLabel( rule->Id()->GetString() );
		IRTree::CName* funcNameTree = new IRTree::CName( funcName );
		IRTree::CExpList* args = new IRTree::CExpList( varExp, new IRTree::CExpList( argExp, 0 ) );
		IRTree::IExp* funcCall = new IRTree::CCall( funcNameTree, args );
		IRTree::CTemp* returnedTemp = new IRTree::CTemp( *currentFrame->ReturnValue() );
		lastReturnedExp = new IRTree::CEseq( new IRTree::CMove( new IRTree::CTemp( *currentFrame->ReturnValue() ), funcCall ), returnedTemp );
		
	}
	
}

}