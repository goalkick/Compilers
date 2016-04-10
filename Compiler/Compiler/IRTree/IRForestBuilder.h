#pragma once 
#include "IRTreeVisitor.h"
#include "IRTree.h"
#include "../SymbolsTable.h"
#include "Frame.h"
#include <unordered_map>
#include <list>

using std::string;
using std::vector;

namespace Translate {

class CIRForestBuilder : public IRTree::IVisitor {
public:
	CIRForestBuilder( const SymbolsTable::CTable* _symbolsTable/*, std::unordered_map<const void*, std::string>& _nodesTypesLog*/ ) :
		currentFrame( 0 ), lastReturnedExp( 0 ), 
		lastReturnedStm( 0 ), lastReturnedExpList( 0 ),
		symbolsTable( _symbolsTable )/*, nodesTypesLog( _nodesTypesLog ) */
	{}

	
	void visit( const CProgram& program );
	void visit( const CMainClass& mainClass );
	void visit( const CClassDeclsList& classDeclList );
	void visit( const CClassDecls& classDecl );
	void visit( const CVarDeclList& varDeclList );
	void visit( const CVarDecl& varDecl );
	void visit( const CMethodDeclList& methodDeclList );
	void visit( const CMethodDecl& methodDecl );
	void visit( const CFormalList& formalList );
	void visit( const CFormalRest& formalList );
	void visit( const CType& type );
	void visit( const CUserType& type );
	void visit( const CStatementList& statementList );
	void visit( const CStatement& ifStatement );
	void visit( const CIfStatement& ifStatement );
	void visit( const CWhileStatement& whileStatement );
	void visit( const CPrintStatement& printStatement );
	void visit( const CAssignStatement& assignStatement );
	void visit( const CArrayAssignStatement& assignStatement );
	void visit( const CExpList& expList );
	void visit( const CBinOpExpression& exp );
	void visit( const CIndexExpression& exp );
	void visit( const CLenghtExpression& exp );
	void visit( const CMethodExpression& exp );
	void visit( const CIntLiteralExpression& exp );
	void visit( const CBoolLiteralExpression& exp );
	void visit( const CIdentifierExpression& exp );
	void visit( const CThisExpression& exp );
	void visit( const CNewIntArrayExpression& exp );
	void visit( const CNewExpression& exp );
	void visit( const CUnaryOpExpression& exp );
	void visit( const CBracesExpression& exp );

	vector<const Frame::CFrame* > Methods;
private:
	Frame::CFrame* currentFrame;
	const SymbolsTable::CTable* symbolsTable;
	// std::unordered_map<const void*, std::string>& nodesTypesLog;
	std::string className;
	const IRTree::IExp* lastReturnedExp;
	const IRTree::IStm* lastReturnedStm;
	const IRTree::CExpList* lastReturnedExpList;
};

}