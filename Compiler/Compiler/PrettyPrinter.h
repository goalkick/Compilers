#pragma once
#include "classes.h"
#include <iostream>

class CPrettyPrinter : public IVisitor {
public:
	void visit(const CProgram* n);
	void visit(const CMainClass* n);
	void visit(const CClassDeclsList* n);
	void visit(const CClassDecls* n);
	void visit(const CVarDeclList* n);
	void visit(const CVarDecl* n);
	void visit(const CMethodDeclList* n);
	void visit(const CMethodDecl* n);
	void visit(const CFormalList* n);
	void visit(const CFormalRest* n);
	void visit(const CType* n);
	void visit(const CUserType* n);
	void visit(const CStatementList* n);
	void visit(const CStatement* n);
	void visit(const CIfStatement* n);
	void visit(const CWhileStatement* n);
	void visit(const CPrintStatement* n);
	void visit(const CAssignStatement* n);
	void visit(const CArrayAssignStatement* n);
	void visit(const CExpList* n);
	void visit(const CExpRest* n);
	void visit(const CBinOpExpression* n);
	void visit(const CIndexExpression* n);
	void visit(const CLenghtExpression* n);
	void visit(const CMethodExpression* n);
	void visit(const CIntLiteralExpression* n);
	void visit(const CBoolLiteralExpression* n);
	void visit(const CIdentifierExpression* n);
	void visit(const CThisExpression* n);
	void visit(const CNewIntArrayExpression* n);
	void visit(const CNewExpression* n);
	void visit(const CUnaryOpExpression* n);
	void visit(const CBracesExpression* n);
	 //void visit(const CExpressionList* n);
};