#pragma once 
#include "Visitor.h"
#include "IRTree.h"
#include "SymbolsTable.h"
#include "IRTree/Frame.h"
#include <unordered_map>
#include <list>

using std::string;
using std::vector;

namespace Translate {

class CIRForestBuilder : public IVisitor {
public:
	CIRForestBuilder( const SymbolsTable::CTable& _symbolsTable, std::unordered_map<const void*, std::string>& _nodesTypesLog ) :
		currentFrame( 0 ), lastReturnedExp( 0 ), 
		lastReturnedStm( 0 ), lastReturnedExpList( 0 ),
		symbolsTable( _symbolsTable ), nodesTypesLog( _nodesTypesLog ) 
	{}

	
	virtual void visit( const CProgram& program );
	virtual void visit( const CMainClass& mainClass );
	virtual void visit( const CClassDeclsList& classDeclList );
	virtual void visit( const CClassDecls& classDecl );
	virtual void visit( const CVarDeclList& varDeclList );
	virtual void visit( const CVarDecl& varDecl );
	virtual void visit( const CMethodDeclList& methodDeclList );
	virtual void visit( const CMethodDecl& methodDecl );
	virtual void visit( const CFormalList& formalList );
	virtual void visit( const CFormalRest& formalList );
	virtual void visit( const CType& type );
	virtual void visit( const CUserType& type );
	virtual void visit( const CStatementList& statementList );
	virtual void visit( const CStatement& ifStatement );
	virtual void visit( const CIfStatement& ifStatement );
	virtual void visit( const CWhileStatement& whileStatement );
	virtual void visit( const CPrintStatement& printStatement );
	virtual void visit( const CAssignStatement& assignStatement );
	virtual void visit( const CArrayAssignStatement& assignStatement );
	virtual void visit( const CExpList& expList );
	virtual void visit( const CBinOpExpression& exp );
	virtual void visit( const CIndexExpression& exp );
	virtual void visit( const CLenghtExpression& exp );
	virtual void visit( const CMethodExpression& exp );
	virtual void visit( const CIntLiteralExpression& exp );
	virtual void visit( const CBoolLiteralExpression& exp );
	virtual void visit( const CIdentifierExpression& exp );
	virtual void visit( const CThisExpression& exp );
	virtual void visit( const CNewIntArrayExpression& exp );
	virtual void visit( const CNewExpression& exp );
	virtual void visit( const CUnaryOpExpression& exp );
	virtual void visit( const CBracesExpression& exp );

	vector<const Frame::CFrame* > Methods;
private:
	Frame::CFrame* currentFrame;
	const SymbolsTable::CTable& symbolsTable;
	std::unordered_map<const void*, std::string>& nodesTypesLog;
	std::string className;
	const IRTree::IExp* lastReturnedExp;
	const IRTree::IStm* lastReturnedStm;
	const IRTree::CExpList* lastReturnedExpList;
};

}