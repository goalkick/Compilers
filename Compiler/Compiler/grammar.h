#pragma once

class IVisitor;

// Корневой интерфейс программы
class Program {
public:
	virtual ~Program() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Главный класс
class MainClass {
public:
	virtual ~MainClass() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Список классов
class ClassDeclsList {
public:
	virtual ~ClassDeclsList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Описание класса
class ClassDecls {
public:
	virtual ~ClassDecls() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Список объявлений переменных
class VarDeclList {
public:
	virtual ~VarDeclList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Объявление переменной
class VarDecl {
public:
	virtual ~VarDecl() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Список методов класса
class MethodDeclList {
public:
	virtual ~MethodDeclList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Метод класса
class MethodDecl {
public:
	virtual ~MethodDecl() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Список параметров
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

// Тип
class Type {
public:
	virtual ~Type() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Последовательность команд
class StatementList {
public:
	virtual ~StatementList() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Одна команда (или блок)
class Statement {
public:
	virtual ~Statement() {}
	virtual void Accept( IVisitor* ) const = 0;
};

// Последовательность выражений (аргументы функции)
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

// Арифметическое выражение
class Exp {
public:
	virtual ~Exp() {}
	virtual void Accept( IVisitor* ) const = 0;
};