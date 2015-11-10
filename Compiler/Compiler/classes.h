#pragma once

#include "visitor.h"
#include "grammar.h"
#include "CLocation.h"
#include <string>
#include <memory>
#include "CSymbol.h"
#include "SymbolsTable.h"

class CProgram : public IProgram {
public:
	CProgram( IMainClass* _pMainClass, IClassDeclsList* _pClassDeclList, CLocation& location ) : 
		pMainClass( _pMainClass ), 
		pClassDeclList( _pClassDeclList ),
		_location( location )
	{ }

	void Accept( IVisitor* visitor ) const { visitor->visit( this ); }

	const IMainClass* MainClass() const { return pMainClass.get(); }

	const IClassDeclsList* ClassDeclList() const { return pClassDeclList.get(); }

private:
	std::shared_ptr<IMainClass> pMainClass;
	std::shared_ptr<IClassDeclsList> pClassDeclList;
	CLocation _location;
};

class CMainClass : public IMainClass {
public:
	CMainClass( IStatement* _pStatement, std::string name, std::string arg, CLocation& location ) : 
		_location( location ), 
		_name( CSymbol::GetSymbol( name ) ),
		_arg( CSymbol::GetSymbol( arg ) ),
		pStatement( _pStatement )
	{ }

	void Accept( IVisitor* visitor ) const { visitor->visit( this ); }

	const IStatement* Statement() const { return pStatement.get(); }
	
	const CSymbol* ClassName() const { return _name.get(); }

	const CSymbol* Arg() const { return _arg.get(); }

private:
	std::shared_ptr<IStatement> pStatement;
	std::shared_ptr<CSymbol> _name;
	std::shared_ptr<CSymbol> _arg;
	CLocation _location;
};

class CClassDeclsList : public IClassDeclsList {
public:
	CClassDeclsList( IClassDecls* _pClassDecls, IClassDeclsList* _pClassDeclsList, CLocation& location ) : 
		_location( location ), 
		pClassDecls( _pClassDecls ), 
		pClassDeclsList (_pClassDeclsList )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }

	const IClassDecls* ClassDecls() const { return pClassDecls.get(); }

	const IClassDeclsList* ClassDeclsList() const { return pClassDeclsList.get(); }

private:
	std::shared_ptr<IClassDecls> pClassDecls;
	std::shared_ptr<IClassDeclsList> pClassDeclsList;
	CLocation _location;
};

class CClassDecls : public IClassDecls {
public:
	CClassDecls( std::string name, std::string parent, IVarDeclList* _pVarDeclList, IMethodDeclList* _pMethodDeclList, CLocation& location ) : 
		_location( location ),
		_name( CSymbol::GetSymbol( name ) ),
		_parent( CSymbol::GetSymbol( parent ) ),
		pVarDeclList( _pVarDeclList ), 
		pMethodDeclList (_pMethodDeclList )
	{
	
	}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }

	const IVarDeclList* VarDeclList() const { return pVarDeclList.get(); }
	
	const IMethodDeclList* MethodDeclList() const { return pMethodDeclList.get(); }

	const CSymbol* ClassName() const { return _name.get(); }

	const CSymbol* ParentName() const { return _parent.get(); }

private:
	std::shared_ptr<IVarDeclList> pVarDeclList;
	std::shared_ptr<IMethodDeclList> pMethodDeclList;
	std::shared_ptr<CSymbol> _name;
	std::shared_ptr<CSymbol> _parent;
	CLocation _location;
};

class CVarDeclList : public IVarDeclList {
public:
	CVarDeclList( IVarDeclList* _pVarDeclList, IVarDecl* _pVarDecl, CLocation& location ) : 
		_location( location ), 
		pVarDeclList( _pVarDeclList ), 
		pVarDecl (_pVarDecl )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }

	const IVarDeclList* VarDeclList() const { return pVarDeclList.get(); }

	const IVarDecl* VarDecl() const { return pVarDecl.get(); }

private:
	std::shared_ptr<IVarDeclList> pVarDeclList;
	std::shared_ptr<IVarDecl> pVarDecl;
	CLocation _location;
};

class CVarDecl : public IVarDecl {
public:
	CVarDecl( IType* _pType, const std::string& name, CLocation& location ) : 
		_location( location ), 
		_name( CSymbol::GetSymbol( name ) ), 
		pType(_pType )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }
	
	const IType* Type() const { return pType.get(); }

	const CSymbol* Name() const { return _name.get(); }

private:
	std::shared_ptr<IType> pType;
	std::shared_ptr<CSymbol> _name;
	CLocation _location;
};

class CMethodDeclList : public IMethodDeclList {
public:
	CMethodDeclList( IMethodDecl* _pMethodDecl, IMethodDeclList* _pMethodDeclList, CLocation& location ) : 
		_location( location ), 
		pMethodDecl( _pMethodDecl ), 
		pMethodDeclList( _pMethodDeclList )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }

	const IMethodDecl* MethodDecl() const { return pMethodDecl.get(); }

	const IMethodDeclList* MethodDeclList() const { return pMethodDeclList.get(); }
	
private:
	std::shared_ptr<IMethodDecl> pMethodDecl;
	std::shared_ptr<IMethodDeclList> pMethodDeclList;
	CLocation _location;
};

class CMethodDecl : public IMethodDecl {
public:
	CMethodDecl( 
		IType* _type, 
		const std::string& name, 
		IFormalList* _pFormalList, 
		IVarDeclList* _pVarDeclList,
		IStatementList* _pStatementList, 
		IExp* _pExp, 
		CLocation& location ) :

		_location( location ), 
		pType( _type ), 
		_name( CSymbol::GetSymbol( name ) ), 
		pFormalList( _pFormalList ), 
		pVarDeclList( _pVarDeclList ),
		pStatementList( _pStatementList ), 
		pExp( _pExp )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }
	
	const IType* Type() const { return pType.get(); }

	const CSymbol* Name() const { return _name.get(); }

	const IExp* Exp() const { return pExp.get(); }

	const IFormalList* FormalList() const { return pFormalList.get(); }

	const IVarDeclList* VarDeclList() const { return pVarDeclList.get(); }

	const IStatementList* StatementList() const { return pStatementList.get(); }

private:
	std::shared_ptr<IType> pType;
	std::shared_ptr<CSymbol> _name;
	std::shared_ptr<IExp> pExp;
	std::shared_ptr<IFormalList> pFormalList;
	std::shared_ptr<IVarDeclList> pVarDeclList;
	std::shared_ptr<IStatementList> pStatementList;
	CLocation _location;
};

class CFormalList : public IFormalList {
public:
	CFormalList( IType* _pType, const std::string& id, IFormalRest* _pFormalRest, CLocation& location ) : 
		_location( location ), 
		_id( CSymbol::GetSymbol( id ) ), 
		pType(_pType ),
		pFormalRest( _pFormalRest )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }

	const IFormalRest* FormalRest() const { return pFormalRest.get(); }
	
	const IType* Type() const { return pType.get(); }

	const CSymbol* Id() const { return _id.get(); }
	
private:
	std::shared_ptr<IFormalRest> pFormalRest;
	std::shared_ptr<IType> pType;
	std::shared_ptr<CSymbol> _id;
	CLocation _location;
};

class CFormalRest : public IFormalRest {
public:
	CFormalRest( IType* _pType, const std::string& id, IFormalRest* _pFormalRest, CLocation& location ) : 
		_location( location ), 
		_id( CSymbol::GetSymbol( id ) ), 
		pType(_pType ),
		pFormalRest( _pFormalRest )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }

	const IFormalRest* FormalRest() const { return pFormalRest.get(); }
	
	const IType* Type() const { return pType.get(); }

	const CSymbol* Id() const { return _id.get(); }
	
private:
	std::shared_ptr<IFormalRest> pFormalRest;
	std::shared_ptr<IType> pType;
	std::shared_ptr<CSymbol> _id;
	CLocation _location;
};

class CType : public IType {
public:
	enum EType { INT, INT_ARRAY, BOOL };

	CType( EType type, CLocation& location ) :
	_type( type ),
	_location( location )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }
	
	EType Type() const { return _type; }

private:
	EType _type;
	CLocation _location;
};

class CUserType : public IType {
public:
	CUserType( const std::string& type, CLocation& location ) :
	_type( CSymbol::GetSymbol ( type ) ),
	_location( location )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }
	
	const CSymbol* Type() const { return _type.get(); }

private:
	std::shared_ptr<CSymbol> _type;
	CLocation _location;
};

class CStatementList : public IStatementList {
public:
	CStatementList( IStatement* _pStatement, IStatementList* _pStatementList, CLocation& location ) : 
		pStatement( _pStatement ), 
		pStatementList( _pStatementList ), 
		_location( location )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }
	
	const IStatement* Statement() const { return pStatement.get(); }

	const IStatementList* StatementList() const { return pStatementList.get(); }

private:
	std::shared_ptr<IStatement> pStatement;
	std::shared_ptr<IStatementList> pStatementList;
	CLocation _location;
};

class CStatement : public IStatement {
public:
	CStatement( IStatementList* _pStatementList, CLocation& location ) :
		_location( location ),
		pStatementList( _pStatementList )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }
	
	const IStatementList* StatementList() const { return pStatementList.get(); }

private:
	std::shared_ptr<IStatementList> pStatementList;
	CLocation _location;
};

class CIfStatement : public IStatement {
public:
	CIfStatement( 
		IExp* condition, 
		IStatement* statementIfTrue, 
		IStatement* statementIfFalse, 
		CLocation& location ) :

	_location( location ),
	_condition( condition ),
	_statementIfTrue( statementIfTrue ),
	_statementIfFalse( statementIfFalse )
	{}

	const IExp* Condition() const { return _condition.get(); }

	const IStatement* IfTrueStatement() const { return _statementIfTrue.get(); }

	const IStatement* IfFalseStatement() const { return _statementIfFalse.get(); }

	void Accept( IVisitor* visitor ) const { visitor->visit( this ); }

private:
	std::shared_ptr<IExp> _condition;
	std::shared_ptr<IStatement> _statementIfTrue;
	std::shared_ptr<IStatement> _statementIfFalse;
	CLocation _location;
};

class CWhileStatement : public IStatement {
public:
	CWhileStatement( IExp* condition, IStatement* cycleBody, CLocation& location ) :
		_condition( condition ),
		_cycleBody( cycleBody ),
		_location( location )
	{}

	const IExp* Condition() const { return _condition.get(); }

	const IStatement* BodyCycle() const { return _cycleBody.get(); }

	void Accept( IVisitor* visitor ) const { visitor->visit( this ); }

private:
	std::shared_ptr<IExp> _condition;
	std::shared_ptr<IStatement> _cycleBody;
	CLocation _location;
};

class CPrintStatement : public IStatement {
public:
	CPrintStatement( IExp* expression, CLocation& location ) :
		_expression( expression ),
		_location( location )
	{}

	const IExp* Expression() const { return _expression.get(); }

	void Accept( IVisitor* visitor ) const { visitor->visit( this ); }

private:
	std::shared_ptr<IExp> _expression;
	CLocation _location;
};

class CAssignStatement : public IStatement {
public:
	CAssignStatement( const std::string& left, IExp* right, CLocation& location ) :
		_left( CSymbol::GetSymbol( left ) ),
		_right( right ),
		_location( location )
	{}

	const CSymbol* LeftPart() const { return _left.get(); }

	const IExp* RightPart() const { return _right.get(); }

	void Accept( IVisitor* visitor ) const { visitor->visit( this ); }

private:
	std::shared_ptr<CSymbol> _left;
	std::shared_ptr<IExp> _right;
	CLocation _location;
};

class CArrayAssignStatement : public IStatement {
public:
	CArrayAssignStatement( const std::string& arrayId, IExp* elementNumber, IExp* rightPart, CLocation& location ) :
		_location( location ),
		_arrayId( CSymbol::GetSymbol( arrayId ) ),
		_elementNumber( elementNumber ),
		_rightPart( rightPart )
	{}

	const CSymbol* ArrayName() const { return _arrayId.get(); }

	const IExp* ElementNumber() const { return _elementNumber.get(); }

	const IExp* RightPart() const { return _rightPart.get(); }

	void Accept( IVisitor* visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<CSymbol> _arrayId;
	std::shared_ptr<IExp> _elementNumber;
	std::shared_ptr<IExp> _rightPart;
	CLocation _location;
};

class CExpList : public IExpList {
public:
	CExpList( IExp* _pExp, IExpList* _pExpList, IExpRest* _pExpRest, CLocation& location ) :
		pExp( _pExp ),
		pExpList( _pExpList ),
		pExpRest( _pExpRest ),
		_location( location )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }
	
	const IExp* Exp() const { return pExp.get(); }

	const IExpList* ExpList() const { return pExpList.get(); }

	const IExpRest* ExpRest() const { return pExpRest.get(); }

private:
	std::shared_ptr<IExp> pExp;
	std::shared_ptr<IExpList> pExpList;
	std::shared_ptr<IExpRest> pExpRest;
	CLocation _location;
};

class CBinOpExpression : public IExp {
public:
	enum EBinOp { AND, LESS, PLUS, MINUS, TIMES, DIVIDE };

	CBinOpExpression( IExp* _pLeftExp, EBinOp _binOp, IExp* _pRightExp, const CLocation& _location ) :
        pLeftExp( _pLeftExp ),
        pRightExp( _pRightExp ),
        location( _location ),
		binOp( _binOp )
    {}

	EBinOp BinOp() const { return binOp; };

	const IExp* LeftExp() const { return pLeftExp.get(); };

	const IExp* RightExp() const { return pRightExp.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };
private:
	std::shared_ptr<IExp> pLeftExp;
	std::shared_ptr<IExp> pRightExp;
	CLocation location;
	EBinOp binOp;
};

class CIndexExpression : public IExp {
public:
	CIndexExpression( IExp* _pExp, IExp* _pIndexExp, const CLocation& _location ) :
        pExp( _pExp ),
        pIndexExp( _pIndexExp ),
        location( _location )
    {}

	const IExp* Exp() const { return pExp.get(); };

	const IExp* IndexExp() const { return pIndexExp.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<IExp> pExp;
	std::shared_ptr<IExp> pIndexExp;
	CLocation location;
};

class CLenghtExpression : public IExp {
public:
	CLenghtExpression( IExp* _pExp, const CLocation& _location ) :
        pExp( _pExp ),
        location( _location )
	{}

	const IExp* Exp() const { return pExp.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<IExp> pExp;
	CLocation location;
};

class CMethodExpression : public IExp {
public:
	CMethodExpression( IExp* _pExp, const std::string& _id, IExpList* _pExpList, const CLocation& _location ) :
        pExp( _pExp ),
		id( CSymbol::GetSymbol( _id ) ),
        pExpList( _pExpList ),
        location( _location )
	{}

	const IExp* Exp() const { return pExp.get(); };

	const IExpList* IndexExp() const { return pExpList.get(); };

	const CSymbol* Id() const { return id.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<IExp> pExp;
	std::shared_ptr<IExpList> pExpList;
	std::shared_ptr<CSymbol> id;
	CLocation location;
};

class CIntLiteralExpression : public IExp {
public:
	CIntLiteralExpression( const std::string& _value, const CLocation& _location ) :
		value( CSymbol::GetSymbol( _value ) ),
        location( _location )
	{}

	const CSymbol* Value() const { return value.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<CSymbol> value;
	CLocation location;
};

class CBoolLiteralExpression : public IExp {
public:
	CBoolLiteralExpression( const std::string& _value, const CLocation& _location ) :
		value( CSymbol::GetSymbol( _value ) ),
        location( _location )
	{}

	const CSymbol* Value( ) const { return value.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<CSymbol> value;
	CLocation location;
};

class CIdentifierExpression : public IExp {
public:
	CIdentifierExpression( const std::string& _id, const CLocation& _location ) :
		id( CSymbol::GetSymbol( _id ) ),
        location( _location )
	{}

	const CSymbol* Id() const { return id.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<CSymbol> id;
	CLocation location;
};

class CThisExpression : public IExp {
public:
	CThisExpression( const CLocation& _location ) :
        location( _location )
	{}

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	CLocation location;
};

class CNewIntArrayExpression : public IExp {
public:
	CNewIntArrayExpression( IExp* _pExp, const CLocation& _location ) :
        pExp( _pExp ),
        location( _location )
	{}

	const IExp* Exp() const { return pExp.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<IExp> pExp;
	CLocation location;
};

class CNewExpression : public IExp {
public:
	CNewExpression( const std::string& _id, const CLocation& _location ) :
		id( CSymbol::GetSymbol( _id ) ),
        location( _location )
    {}

	const CSymbol* Id() const { return id.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<CSymbol> id;
	CLocation location;
};

class CUnaryOpExpression : public IExp {
public:
	enum UnaryOp { MINUS, NOT };

	CUnaryOpExpression( UnaryOp _op, IExp* _pExp, const CLocation& _location ) :
        op( _op ),
        pExp( _pExp ),
        location( _location )
	{}

	const IExp* Exp() const { return pExp.get(); };

	UnaryOp Op() const { return op; };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<IExp> pExp;
	CLocation location;
	UnaryOp op;
};

class CBracesExpression : public IExp {
public:
	CBracesExpression( IExp* _pExp, const CLocation& _location ) :
        pExp( _pExp ),
        location( _location )
	{}

	const IExp* Exp() const { return pExp.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<IExp> pExp;
	CLocation location;
};

/*
class CExpressionList : public IExpList {
public:
	CExpressionList( IExp* _pExp, IExpList* _pExpList, const CLocation& _location ) :
        pExp( _pExp ),
        pExpList( _pExpList ),
        location( _location )
	{}

	const IExp* Exp() const { return pExp.get(); };

	const IExpList* ExpList() const { return pExpList.get(); };

	void Accept( IVisitor*  visitor ) const { visitor->visit( this ); };

private:
	std::shared_ptr<IExp> pExp;
	std::shared_ptr<IExpList> pExpList;
	CLocation location;
};
*/

class CExpRest : public IExpRest {
public:
	CExpRest( IExp* _pExp, CLocation& location ) :
		pExp( _pExp ),
		_location( location )
	{}

	void Accept( IVisitor* visitor) const { visitor->visit( this ); }
	
	const IExp* Exp() const { return pExp.get(); }

private:
	std::shared_ptr<IExp> pExp;
	CLocation _location;
};

/*
class CExp : public IExp {
public:
	virtual ~CExp() {}
	virtual void Accept( IVisitor* ) const;

	void Accept( IVisitor* visitor) const { visitor->visit( *this ); }
	
private:
	std::shared_ptr<class VarDeclList> pVarDeclList;
	std::shared_ptr<class MethodDeclList> pMethodDeclList;
	CLocation _location;
};
*/