#pragma once

#include "grammar.h"

class CProgram : public Program {
public:
	virtual ~CProgram() {}
	virtual void Accept( IVisitor* ) const;
};

// Главный класс
class CMainClass : public MainClass {
public:
	virtual ~CMainClass() {}
	virtual void Accept( IVisitor* ) const;
};

// Список классов
class CClassDeclsList : public ClassDeclsList {
public:
	virtual ~CClassDeclsList() {}
	virtual void Accept( IVisitor* ) const;
};

// Описание класса
class CClassDecls : public ClassDecls {
public:
	virtual ~CClassDecls() {}
	virtual void Accept( IVisitor* ) const;
};

// Список объявлений переменных
class CVarDeclList : public VarDeclList {
public:
	virtual ~CVarDeclList() {}
	virtual void Accept( IVisitor* ) const;
};

// Объявление переменной
class CVarDecl : public VarDecl {
public:
	virtual ~CVarDecl() {}
	virtual void Accept( IVisitor* ) const;
};

// Список методов класса
class CMethodDeclList : public MethodDeclList {
public:
	virtual ~CMethodDeclList() {}
	virtual void Accept( IVisitor* ) const;
};

// Метод класса
class CMethodDecl : public MethodDecl {
public:
	virtual ~CMethodDecl() {}
	virtual void Accept( IVisitor* ) const;
};

// Список параметров
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

// Тип
class CType : public Type {
public:
	virtual ~CType() {}
	virtual void Accept( IVisitor* ) const;
};

// Последовательность команд
class CStatementList : public StatementList {
public:
	virtual ~CStatementList() {}
	virtual void Accept( IVisitor* ) const;
};

// Одна команда (или блок)
class CStatement : public Statement {
public:
	virtual ~CStatement() {}
	virtual void Accept( IVisitor* ) const;
};

// Последовательность выражений (аргументы функции)
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

// Арифметическое выражение
class CExp : public Exp {
public:
	virtual ~CExp() {}
	virtual void Accept( IVisitor* ) const;
};