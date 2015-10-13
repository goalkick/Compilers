#pragma once

class IVisitor;

// �������� ��������� ���������
class Program {
public:
	virtual ~Program() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������� �����
class MainClass {
public:
	virtual ~MainClass() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������ �������
class ClassDeclsList {
public:
	virtual ~ClassDeclsList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// �������� ������
class ClassDecls {
public:
	virtual ~ClassDecls() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������ ���������� ����������
class VarDeclList {
public:
	virtual ~VarDeclList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ���������� ����������
class VarDecl {
public:
	virtual ~VarDecl() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������ ������� ������
class MethodDeclList {
public:
	virtual ~MethodDeclList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ����� ������
class MethodDecl {
public:
	virtual ~MethodDecl() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������ ����������
class FormalList {
public:
	virtual ~FormalList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

class FormalRest {
public:
	virtual ~FormalRest() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ���
class Type {
public:
	virtual ~Type() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������������������ ������
class StatementList {
public:
	virtual ~StatementList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ���� ������� (��� ����)
class Statement {
public:
	virtual ~Statement() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������������������ ��������� (��������� �������)
class ExpList {
public:
	virtual ~ExpList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

class ExpRest {
public:
	virtual ~ExpRest() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// �������������� ���������
class Exp {
public:
	virtual ~Exp() {}
	virtual void Accept( IVisitor* ) const = 0;
};