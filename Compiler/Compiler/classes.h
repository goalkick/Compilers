#pragma once

#include "grammar.h"

class CProgram : public Program {
public:
	virtual ~CProgram() {}
	virtual void Accept( IVisitor* ) const;
};

// ������� �����
class CMainClass : public MainClass {
public:
	virtual ~CMainClass() {}
	virtual void Accept( IVisitor* ) const;
};

// ������ �������
class CClassDeclsList : public ClassDeclsList {
public:
	virtual ~CClassDeclsList() {}
	virtual void Accept( IVisitor* ) const;
};

// �������� ������
class CClassDecls : public ClassDecls {
public:
	virtual ~CClassDecls() {}
	virtual void Accept( IVisitor* ) const;
};

// ������ ���������� ����������
class CVarDeclList : public VarDeclList {
public:
	virtual ~CVarDeclList() {}
	virtual void Accept( IVisitor* ) const;
};

// ���������� ����������
class CVarDecl : public VarDecl {
public:
	virtual ~CVarDecl() {}
	virtual void Accept( IVisitor* ) const;
};

// ������ ������� ������
class CMethodDeclList : public MethodDeclList {
public:
	virtual ~CMethodDeclList() {}
	virtual void Accept( IVisitor* ) const;
};

// ����� ������
class CMethodDecl : public MethodDecl {
public:
	virtual ~CMethodDecl() {}
	virtual void Accept( IVisitor* ) const;
};

// ������ ����������
class CFormalList : public FormalList {
public:
	virtual ~CFormalList() {}
	virtual void Accept( IVisitor* ) const;
};

class CFormalRest : public FormalRest {
public:
	virtual ~CFormalRest() {}
	virtual void Accept( IVisitor* ) const;
};

// ���
class CType : public Type {
public:
	virtual ~CType() {}
	virtual void Accept( IVisitor* ) const;
};

// ������������������ ������
class CStatementList : public StatementList {
public:
	virtual ~CStatementList() {}
	virtual void Accept( IVisitor* ) const;
};

// ���� ������� (��� ����)
class CStatement : public Statement {
public:
	virtual ~CStatement() {}
	virtual void Accept( IVisitor* ) const;
};

// ������������������ ��������� (��������� �������)
class CExpList : public ExpList {
public:
	virtual ~CExpList() {}
	virtual void Accept( IVisitor* ) const;
};

class CExpRest : public ExpRest {
public:
	virtual ~CExpRest() {}
	virtual void Accept( IVisitor* ) const;
};

// �������������� ���������
class CExp : public Exp {
public:
	virtual ~CExp() {}
	virtual void Accept( IVisitor* ) const;
};