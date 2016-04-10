#pragma once

class CProgram;
class CMainClass;
class CClassDeclsList;
class CClassDecls;
class CVarDeclList;
class CVarDecl;
class CMethodDeclList;
class CMethodDecl;
class CFormalList;
class CFormalRest;
class CType;
class CUserType;
class CStatementList;
class CStatement;
class CIfStatement;
class CWhileStatement;
class CPrintStatement;
class CAssignStatement;
class CArrayAssignStatement;
class CExpList;
class CExpRest;
//class CExp;
class CBinOpExpression;
class CIndexExpression;
class CLenghtExpression;
class CMethodExpression;
class CIntLiteralExpression;
class CBoolLiteralExpression;
class CIdentifierExpression;
class CThisExpression;
class CNewIntArrayExpression;
class CNewExpression;
class CUnaryOpExpression;
class CBracesExpression;
//class CExpressionList;

class IVisitor {
public:
	virtual ~IVisitor() {}

	virtual void visit(const CProgram* n) = 0;
	virtual void visit(const CMainClass* n) = 0;
	virtual void visit(const CClassDeclsList* n) = 0;
	virtual void visit(const CClassDecls* n) = 0;
	virtual void visit(const CVarDeclList* n) = 0;
	virtual void visit(const CVarDecl* n) = 0;
	virtual void visit(const CMethodDeclList* n) = 0;
	virtual void visit(const CMethodDecl* n) = 0;
	virtual void visit(const CFormalList* n) = 0;
	virtual void visit(const CFormalRest* n) = 0;
	virtual void visit(const CType* n) = 0;
	virtual void visit(const CUserType* n) = 0;
	virtual void visit(const CStatementList* n) = 0;
	virtual void visit(const CStatement* n) = 0;
	virtual void visit(const CIfStatement* n) = 0;
	virtual void visit(const CWhileStatement* n) = 0;
	virtual void visit(const CPrintStatement* n) = 0;
	virtual void visit(const CAssignStatement* n) = 0;
	virtual void visit(const CArrayAssignStatement* n) = 0;
	virtual void visit(const CExpList* n) = 0;
	virtual void visit(const CExpRest* n) = 0;
	virtual void visit(const CBinOpExpression* n) = 0;
	virtual void visit(const CIndexExpression* n) = 0;
	virtual void visit(const CLenghtExpression* n) = 0;
	virtual void visit(const CMethodExpression* n) = 0;
	virtual void visit(const CIntLiteralExpression* n) = 0;
	virtual void visit(const CBoolLiteralExpression* n) = 0;
	virtual void visit(const CIdentifierExpression* n) = 0;
	virtual void visit(const CThisExpression* n) = 0;
	virtual void visit(const CNewIntArrayExpression* n) = 0;
	virtual void visit(const CNewExpression* n) = 0;
	virtual void visit(const CUnaryOpExpression* n) = 0;
	virtual void visit(const CBracesExpression* n) = 0;
	//virtual void visit(const CExpressionList* n) = 0;
};