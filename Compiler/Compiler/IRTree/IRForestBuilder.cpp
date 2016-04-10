#include "IRForestBuilder.h"
#include "../Visitor.h"
#include "StmConverter.h"
#include "ConditionalWrapper.cpp"

#include <iostream>
#include <string>
#include <stack>

namespace Translate {

void CIRForestBuilder::visit( const CProgram& program )
{
	// Здесь для IRTree ничего не нужно
	program.MainClass()->Accept( this );
	if( program.ClassDeclList() != 0 ) {
		program.ClassDeclList()->Accept( this );
	}
}

void CIRForestBuilder::visit( const CMainClass& mainClass )
{
	// Запоминаем в каком мы классе
	className = mainClass.ClassName()->GetString();
	// У main нет никаких переменных, потому что такая грамматика
	//	Программу можно будет начать если сделать временный объект какого нибудь класса
	//	например System.out.println( new Pr1() );
	currentFrame = new Frame::CFrame( className + "__main" );
	if( mainClass.Statement() != 0 ) {
		mainClass.Statement()->Accept( this );
	}
	currentFrame->Stm = lastReturnedStm;
	lastReturnedStm = nullptr;
	lastReturnedExp = nullptr;
	Methods.push_back( currentFrame );
	// Очищаем инфу о текущем фрейме
	currentFrame = 0;
	className = "";
}

void CIRForestBuilder::visit( const CClassDeclsList& classDeclList )
{
	// Здесь для IRTree ничего не нужно
	classDeclList.ClassDecls()->Accept( this );
	if ( classDeclList.ClassDeclsList() != 0 ) {
		classDeclList.ClassDeclsList()->Accept( this );
	}
}

void CIRForestBuilder::visit( const CClassDecls& classDecl )
{
	// Запоминаем в каком мы классе
	className = classDecl.ClassName()->GetString();
	if( classDecl.VarDeclList() != 0 ) {
		classDecl.VarDeclList()->Accept( this );
	}
	if( classDecl.MethodDeclList() != 0 ) {
		classDecl.MethodDeclList()->Accept( this );
	}
	lastReturnedExp = nullptr;
	lastReturnedStm = nullptr;
	className = "";
}

void CIRForestBuilder::visit( const CVarDeclList& varDeclList )
{
	// Здесь для IRTree ничего не нужно	
	varDeclList.VarDecl()->Accept( this );
	if ( varDeclList.VarDeclList() != 0 ) {
		varDeclList.VarDeclList()->Accept( this );
	}
}

void CIRForestBuilder::visit( const CVarDecl& varDecl )
{
	varDecl.Type()->Accept( this );
}

void CIRForestBuilder::visit( const CMethodDeclList& methodDeclList )
{	
	methodDeclList.MethodDecl()->Accept( this );
	if ( methodDeclList.MethodDeclList() != 0 ) {
		methodDeclList.MethodDeclList()->Accept( this );
	}
}

void CIRForestBuilder::visit( const CMethodDecl& methodDecl )
{
	// Все это мы игнорируем, это есть у таблицы символов
	methodDecl.Type()->Accept( this );
	if( methodDecl.FormalList() != 0 ) {
		methodDecl.FormalList()->Accept( this );
	}
	if( methodDecl.VarDeclList() != 0 ) {
		methodDecl.VarDeclList()->Accept( this );
	}
	// Строим фрейм
	currentFrame = new Frame::CFrame( className + "__" + methodDecl.Name()->GetString() );
	std::vector<const SymbolsTable::CClassInfo*> classNames;
	const SymbolsTable::CClassInfo* currentClass = symbolsTable.GetClass( className );
	while( currentClass != nullptr ) {
		classNames.push_back( currentClass );
		if( !currentClass->GetBaseClass()->empty() ) {
			currentClass = currentClass->GetBaseClass();
		} else {
			currentClass = nullptr;
		}
	}
	// Добавляем поля класса к фрейму symbolsTable.GetClass( className )
	for( int i = classNames.size() - 1; i >= 0; i-- ) {
		for( const auto& field : classNames.at( i )->Fields ) {
			currentFrame->AddField( field.Name(), new Frame::CInObject( currentFrame->ThisCounter ) );
			currentFrame->ThisCounter++;
		}
	}

	const std::vector<std::shared_ptr<SymbolsTable::CVarInfo> >* params = nullptr;
	const std::vector<std::shared_ptr<SymbolsTable::CVarInfo> >* locals = nullptr;
	for( auto& method : symbolsTable.GetClass( className )->GetMethods() ) {
		if( method->GetName() == methodDecl.Name()->GetString() ) {
			params = &method->GetParams();
			locals = &method->GetLocals();
			break;
		}
	}
	
	// Добавляем параметры функции фрейму
	for( size_t i = 0; i < params->size(); ++i ) {
		currentFrame->AddField( params->at( i )->GetName(), new Frame::CFormalParameterInStack( i + 1 ) );
	}
	// Добавляем локальные переменные фрейму
	for( const auto& field : *locals ) {
		currentFrame->AddField( field->GetName(), new Frame::CInFrame( currentFrame->LocalCounter ) );
		currentFrame->LocalCounter++;
	}
	if( methodDecl.StatementList() != 0 ) {
		methodDecl.StatementList()->Accept( this );
		// после этой строки есть сам код
	}
	if( methodDecl.Exp() != 0 ) {
		// Это обрабатываем как возвращаемое значение, оно проставляется return 
		// Переносим lastReturnedValue в регистр если оно было
		methodDecl.Exp()->Accept( this );
		if( lastReturnedExp != nullptr ) {
			if( lastReturnedStm != nullptr ) {
				lastReturnedStm = new IRTree::CSeq( lastReturnedStm, new IRTree::CMove( new IRTree::CTemp( *currentFrame->ReturnValue() ), lastReturnedExp ) );
			} else {
				lastReturnedStm = new IRTree::CMove( new IRTree::CTemp( *currentFrame->ReturnValue() ), lastReturnedExp );
			}
			
		}
	}
	currentFrame->Stm = lastReturnedStm;
	Methods.push_back( currentFrame );
	currentFrame = nullptr;
	lastReturnedStm = nullptr;
	lastReturnedExp = nullptr;
}

void CIRForestBuilder::visit( const CFormalList& formalList )
{
	// Эта инфа у таблицы символов
	// Нам тут делать нечего
	for( auto ptr = formalList.FormalList().begin(); ptr != formalList.FormalList().end(); ++ptr ) {
		ptr->first->Accept( this );
	}
}

void CIRForestBuilder::visit( const CType& type )
{
	// Здесь для IRTree ничего не нужно
	// Все у таблицы символов
}

void CIRForestBuilder::visit( const CStatementList& statementList )
{
	// Предполагается что есть хоть какие то statement
	const IRTree::IStm* listOfStm = nullptr;
	// Выполняем первый
	statementList.StatementList().front()->Accept( this );
	listOfStm = lastReturnedStm;
	lastReturnedStm = nullptr;
	lastReturnedExp = nullptr;
	if( statementList.StatementList().size() == 1 ) {
		lastReturnedStm = listOfStm;
		return;
	} else {
		auto iter = statementList.StatmentList().begin();
		iter++;
		// начинаем после первого!
		for( ; iter != statementList.StatmentList().end(); iter++ ) {
			(*iter)->Accept( this );
			const IRTree::IStm* statementToAdd = 0;
			if( lastReturnedStm == nullptr ) {
				// Нам нужны только IStm 
				statementToAdd = new IRTree::CExp( lastReturnedExp );
			} else {
				statementToAdd = lastReturnedStm;
			}
			listOfStm = new IRTree::CSeq( listOfStm, statementToAdd );
			lastReturnedStm = nullptr;
			lastReturnedExp = nullptr;
		}
		lastReturnedStm = listOfStm;
	}
}

void CIRForestBuilder::visit( const CAssignStatement& assignStatement )
{
	const IRTree::IExp* leftExp = currentFrame->GetAccess( assignStatement.LeftId() )->ToExp( currentFrame );
	if( assignStatement.IndexExp() != nullptr ) {
		assignStatement.IndexExp()->Accept( this );
		const IRTree::IExp* indexDeFacto = new IRTree::CBinop( IRTree::B_Plus, lastReturnedExp , new IRTree::CConst( 1 ) );
		const IRTree::IExp* realSize = new IRTree::CBinop( IRTree::B_Mul, indexDeFacto, new IRTree::CConst(  currentFrame->WordSize() ) );
		
		leftExp = new IRTree::CBinop( IRTree::B_Plus, new IRTree::CMem( leftExp ), realSize );
		leftExp = new IRTree::CMem( leftExp );
	}
	assignStatement.RightExp()->Accept( this );
	const IRTree::IExp* rightExp = lastReturnedExp;
	lastReturnedExp = nullptr;
	lastReturnedStm = new IRTree::CMove( leftExp, rightExp );
}

void CIRForestBuilder::visit( const CPrintStatement& printStatement )
{
	// Вычисляем то что надо напечатать
	printStatement.Exp()->Accept( this );
	const IRTree::IExp* exprForPrint = lastReturnedExp;
	lastReturnedExp = nullptr;
	lastReturnedStm = nullptr;
	// Вызываем функцию
	Temp::CLabel* funcName = new Temp::CLabel( "println" );
	const IRTree::CName* funcNameTree = new IRTree::CName( funcName );
	const IRTree::CExpList* args = new IRTree::CExpList( exprForPrint, nullptr );
	const IRTree::IExp* funcCall = new IRTree::CCall( funcNameTree, *args );
	lastReturnedStm = new IRTree::CExp( funcCall );
}

void CIRForestBuilder::visit( const CCurlyBraceStatement& curlyBraceStatement )
{
	// Здесь ничего делать не нужно, это обрамление из фигурных скобок для StatementList
	curlyBraceStatement.StatementList()->Accept( this );
}

void CIRForestBuilder::visit( const CIfStatement& ifStatement )
{
	ifStatement.Exp()->Accept( this );
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
	ifStatement.IfStatement()->Accept( this );
	IRTree::IStm* trueStm = new IRTree::CSeq( trueLabel, lastReturnedStm, trueJumpToEnd );
	lastReturnedExp = nullptr;
	lastReturnedStm = nullptr;
	IRTree::IStm* falseStm = 0;
	if( ifStatement.ElseStatement() != 0 ) {
		ifStatement.ElseStatement()->Accept( this );
		IRTree::CJump* falseJumpToEnd = new IRTree::CJump( endLabelTemp );
		falseStm = new IRTree::CSeq( falseLabel, lastReturnedStm, falseJumpToEnd );
		lastReturnedExp = nullptr;
		lastReturnedStm = nullptr;
	}
	Translate::CConditionalWrapper wrapper( ifExpr );
	lastReturnedStm = new IRTree::CSeq( wrapper.ToConditional( trueLabelTemp, falseLabelTemp ) , trueStm, falseStm, endLabel );
}

void CIRForestBuilder::visit( const CWhileStatement& whileStatement )
{
	Temp::CLabel* beforeConditionLabelTemp = new Temp::CLabel();
	Temp::CLabel* inLoopLabelTemp = new Temp::CLabel();
	Temp::CLabel* endLabelTemp = new Temp::CLabel();
	IRTree::CLabel* beforeConditionLabel = new IRTree::CLabel( beforeConditionLabelTemp );
	IRTree::CLabel* inLoopLabel = new IRTree::CLabel( inLoopLabelTemp );
	IRTree::CLabel* endLabel = new IRTree::CLabel( endLabelTemp );
	whileStatement.Exp()->Accept( this );
	Translate::CConditionalWrapper converter( lastReturnedExp );
	const IRTree::IStm* whileStm = converter.ToConditional( inLoopLabelTemp, endLabelTemp );
	lastReturnedExp = nullptr;
	lastReturnedStm = nullptr;
	IRTree::IStm* conditionStm = new IRTree::CSeq( beforeConditionLabel, whileStm, inLoopLabel );
	whileStatement.Statement()->Accept( this );
	lastReturnedStm = new IRTree::CSeq( conditionStm, lastReturnedStm, 
		new IRTree::CJump( beforeConditionLabelTemp ), endLabel );
	lastReturnedExp = nullptr;
}

void CIRForestBuilder::visit( const CExpList& expList )
{
	const IRTree::CExpList* irExpList = nullptr;
	for( const auto& decl : expList.ExpList() ) {
		decl->Accept( this );
		irExpList = new IRTree::CExpList( lastReturnedExp, irExpList );
	}
	lastReturnedExpList = irExpList;
}


void CIRForestBuilder::visit( const CExpBinOpExp& exp )
{
	// Забираем правый и левый операнды
	exp.LeftArg()->Accept( this );
	const IRTree::IExp* first = lastReturnedExp;
	exp.RightArg()->Accept( this );
	const IRTree::IExp* second = lastReturnedExp;
	IRTree::BINOP_ENUM binOp;
	switch( exp.Operation() ) {
		case '+':
			binOp = IRTree::B_Plus;
			break;
		case '-':
			binOp = IRTree::B_Minus;
			break;
		case '*':
			binOp = IRTree::B_Mul;
			break;
		case '/':
			binOp = IRTree::B_Division;
			break;
		case '^':
			binOp = IRTree::B_Xor;
			break;
		case '<':
			binOp = IRTree::B_Less;
			break;
		case '>':
			binOp = IRTree::B_Greater;
			break;
		case '&':
			binOp = IRTree::B_And;
			break;
	}
	// Берем то что лежит по first, second и применяем бинарную операцию
	lastReturnedExp = new IRTree::CBinop( binOp, first, second );
}

void CIRForestBuilder::visit( const CUnMinExp& exp )
{
	// Как в лекциях заменяем на (0 - exp)
	const IRTree::IExp* first = new IRTree::CConst( 0 );
	exp.Exp()->Accept( this );
	const IRTree::IExp* second = lastReturnedExp;
	// Аналогично binop
	lastReturnedExp = new IRTree::CBinop( IRTree::B_Minus, first, second );
}

void CIRForestBuilder::visit( const CExpWithIndex& exp )
{
	exp.Exp()->Accept( this );
	const IRTree::IExp* varExp = lastReturnedExp;
	exp.Index()->Accept( this );
	// в 0м элементе лежит размер массива
	const IRTree::IExp* indexExp = new IRTree::CBinop( IRTree::B_Plus, lastReturnedExp, new IRTree::CConst( 1 ) );
	IRTree::IExp* offset = new IRTree::CBinop( IRTree::B_Mul, new IRTree::CConst( Frame::CFrame::WordSize() ), indexExp );
	// Возвращаем значение переменной
	lastReturnedExp = new IRTree::CMem( new IRTree::CBinop( IRTree::B_Plus, new IRTree::CMem( varExp ), offset ) );
}

void CIRForestBuilder::visit( const CExpDotLength& exp )
{
	// Во время компиляции уже известен размер каждого массива, он должен проверяться на корректность при валидации
	exp.Exp()->Accept( this );
	const IRTree::IExp* varExp = lastReturnedExp;
	// Возвращаем длину
	lastReturnedExp = new IRTree::CMem( varExp );
}

void CIRForestBuilder::visit( const CExpIdExpList& exp )
{
	// Вычисляем выражение к которому надо применить метод
	exp.Exp()->Accept( this );
	auto findResult = nodesTypesLog.find( reinterpret_cast<const void*>( &exp ) );
	assert( findResult != nodesTypesLog.end() );
	std::string typeName = findResult->second;
	const IRTree::IExp* exprToBeCalled = lastReturnedExp;
	// Это просто метод который надо вызвать
	std::string methodName = exp.Id();
	Temp::CLabel* functionLabel = new Temp::CLabel( typeName + "__" + methodName );
	IRTree::CName* functionName = new IRTree::CName( functionLabel );

	// Добавляем this первым аргументом.
	IRTree::CExpList* args = new IRTree::CExpList( exprToBeCalled, nullptr );
	// Заполняем список аргументов.
	if( exp.ExpList() != 0 ) {
		exp.ExpList()->Accept( this );
		args->tail = std::shared_ptr<const IRTree::CExpList>( lastReturnedExpList );
	} else {
		args->tail = nullptr;
	}
	// Возвращаемое значение
	const IRTree::CTemp* returnedTemp = new IRTree::CTemp( *currentFrame->ReturnValue() );
	lastReturnedExp = new IRTree::CEseq( new IRTree::CMove( returnedTemp, new IRTree::CCall( functionName, *args ) ), returnedTemp );
}

void CIRForestBuilder::visit( const CExpIdVoidExpList& exp )
{
	// Вызов функции без аргументов
	// Вычисляем выражение к которому надо применить метод
	auto findResult = nodesTypesLog.find( reinterpret_cast< const void * >( &exp ) );
	assert( findResult != nodesTypesLog.end() );
	std::string typeName = findResult->second;

	exp.Exp()->Accept( this );
	const IRTree::IExp* exprToBeCalled = lastReturnedExp;
	lastReturnedExp = nullptr;
	// Это просто метод который надо вызвать
	std::string methodName = exp.Id();
	Temp::CLabel* functionLabel = new Temp::CLabel( typeName + "__" + methodName );
	IRTree::CName* functionName = new IRTree::CName( functionLabel );
	const IRTree::CExpList* args = new IRTree::CExpList( exprToBeCalled, nullptr );
	const IRTree::CTemp* returnedTemp = new IRTree::CTemp( *currentFrame->ReturnValue() );
	lastReturnedExp = new IRTree::CEseq( new IRTree::CMove( returnedTemp, new IRTree::CCall( functionName, *args ) ), returnedTemp );
}

void CIRForestBuilder::visit( const CIntegerLiteral& exp )
{
	lastReturnedExp = new IRTree::CConst( exp.Value() );
}

void CIRForestBuilder::visit( const CTrue& exp )
{
	// True у нас константа 1
	lastReturnedExp = new IRTree::CConst( 1 );
}

void CIRForestBuilder::visit( const CFalse& exp )
{
	// False у нас константа 0
	lastReturnedExp = new IRTree::CConst( 0 );
}

void CIRForestBuilder::visit( const CId& exp )
{
	// Найдем нужную инфу во фрейме
	lastReturnedExp = currentFrame->GetAccess( exp.Id() )->ToExp( currentFrame );
}

void CIRForestBuilder::visit( const CThis& exp )
{
	lastReturnedExp = currentFrame->ThisPointerExp();
}

void CIRForestBuilder::visit( const CNewIntExpIndex& exp )
{
	exp.Exp()->Accept( this );
	const IRTree::IExp* lengthOfArrray = lastReturnedExp;
	const IRTree::IExp* lengthDeFacto = new IRTree::CBinop( IRTree::B_Plus, lengthOfArrray, new IRTree::CConst( 1 ) );
	const IRTree::IExp* realSize = new IRTree::CBinop( IRTree::B_Mul, lengthDeFacto, new IRTree::CConst( currentFrame->WordSize() ) );
	// Выделяем память
	Temp::CLabel* mallocLabel = new Temp::CLabel( "malloc" );
	const IRTree::CName* mallocName = new IRTree::CName( mallocLabel );

	IRTree::CExpList* argsMalloc = new IRTree::CExpList( realSize, nullptr );
	const IRTree::CCall* mallocCall = new IRTree::CCall( mallocName, *argsMalloc );
	// Послу вызова mallocCall адрес памяти уже в EAX
	const IRTree::CTemp* returnedTemp = new IRTree::CTemp( *currentFrame->ReturnValue() );
	// Проставляем память нулями
	Temp::CLabel* memsetLabel = new Temp::CLabel( "memset" );
	const IRTree::CName* memsetName = new IRTree::CName( memsetLabel );
	IRTree::CExpList* argMemset = new IRTree::CExpList( returnedTemp, new IRTree::CExpList( realSize, nullptr ) );
	const IRTree::CCall* memsetCall = new IRTree::CCall( memsetName, *argMemset );

	const IRTree::IStm* setLength = new IRTree::CMove( returnedTemp, lengthOfArrray );

	lastReturnedExp = new IRTree::CEseq( new IRTree::CSeq( new IRTree::CExp( mallocCall ), new IRTree::CExp( memsetCall ), setLength ), returnedTemp );
}

void CIRForestBuilder::visit( const CNewId& exp )
{
	// Выделяем память
	Temp::CLabel* mallocLabel = new Temp::CLabel( "malloc" );

	// Здесь считается сколько всего полей у класса
	const IRTree::CName* mallocName = new IRTree::CName( mallocLabel );
	auto classDecriptor = symbolsTable.Classes().find( exp.TypeId() );
	assert( classDecriptor != symbolsTable.Classes().end() );
	int fieldsCount = classDecriptor->second.Fields.size();
	// Проходимся по предкам
	classDecriptor = symbolsTable.Classes().find( classDecriptor->second.BaseClass );
	while( classDecriptor != symbolsTable.Classes().end() ) {
		fieldsCount += classDecriptor->second.Fields.size();
	}
	// Выделяем память для полей самого класса и для полей базового класса
	// Первый аргумент всегда this
	const IRTree::IExp* realSize = new IRTree::CConst( fieldsCount * currentFrame->WordSize() );
	IRTree::CExpList* mallocArgs = new IRTree::CExpList( realSize, nullptr );
	const IRTree::CCall* mallocCall = new IRTree::CCall( mallocName, *mallocArgs );
	const IRTree::CTemp* returnedTemp = new IRTree::CTemp( *currentFrame->ReturnValue() );

	// Проставляем память нулями
	Temp::CLabel* memsetLabel = new Temp::CLabel( "memset" );
	const IRTree::CName* memsetName = new IRTree::CName( memsetLabel );
	IRTree::CExpList* argMemset = new IRTree::CExpList( returnedTemp, new IRTree::CExpList( realSize, nullptr ) );
	const IRTree::CCall* memsetCall = new IRTree::CCall( memsetName, *argMemset );

	lastReturnedExp = new IRTree::CEseq( new IRTree::CSeq( new IRTree::CExp( mallocCall ), new IRTree::CExp( memsetCall ) ), returnedTemp );
}

void CIRForestBuilder::visit( const CNotExp& exp )
{
	// Получаем lastReturnedExp и записываем туда конструкцию XOR c Const(0)
	exp.Exp()->Accept( this );
	lastReturnedExp = new IRTree::CBinop( IRTree::B_Xor,
		new IRTree::CConst( 0 ), lastReturnedExp );
}

void CIRForestBuilder::visit( const CExpInBrackets& exp )
{
	// Здесь все и так нормально, тут сохраняется lastReturnedExp
	exp.Exp()->Accept( this );
}


}