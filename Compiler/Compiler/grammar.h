#pragma once
class IVisitor;

// �������� ��������� ���������
class IProgram {
public:
	virtual ~IProgram() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������� �����
class IMainClass {
public:
	virtual ~IMainClass() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������ �������
class IClassDeclsList {
public:
	virtual ~IClassDeclsList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// �������� ������
class IClassDecls {
public:
	virtual ~IClassDecls() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������ ���������� ����������
class IVarDeclList {
public:
	virtual ~IVarDeclList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ���������� ����������
class IVarDecl {
public:
	virtual ~IVarDecl() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������ ������� ������
class IMethodDeclList {
public:
	virtual ~IMethodDeclList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ����� ������
class IMethodDecl {
public:
	virtual ~IMethodDecl() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������ ����������
class IFormalList {
public:
	virtual ~IFormalList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

class IFormalRest {
public:
	virtual ~IFormalRest() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ���
class IType {
public:
	virtual ~IType() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������������������ ������
class IStatementList {
public:
	virtual ~IStatementList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ���� ������� (��� ����)
class IStatement {
public:
	virtual ~IStatement() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// ������������������ ��������� (��������� �������)
class IExpList {
public:
	virtual ~IExpList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

class IExpRest {
public:
	virtual ~IExpRest() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// �������������� ���������
class IExp {
public:
	virtual ~IExp() {}
	virtual void Accept( IVisitor* ) const = 0;
};