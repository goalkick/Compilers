#include <iostream>
#include "SymbolsTableVisitor.h"

CSymbolTableBuilderVisitor::CSymbolTableBuilderVisitor() :
	curClass( nullptr ),
	curMethod( nullptr ),
	isDebug( true )
{
	symbolsTable = std::make_shared<SymbolsTable::CTable>();
}

std::shared_ptr<SymbolsTable::CTable> CSymbolTableBuilderVisitor::GetSymbolsTable()
{
	return symbolsTable;
}

void CSymbolTableBuilderVisitor::visit( const CProgram* program )
{
	if( program->MainClass() != nullptr )
	{
		program->MainClass()->Accept( this );
	}
	if( program->ClassDeclList() != nullptr )
	{
		program->ClassDeclList()->Accept( this );
	}
}

void CSymbolTableBuilderVisitor::visit( const CMainClass* program )
{
	if( !symbolsTable->AddClass( program->ClassName()->GetString() ) )
	{
		std::cout << "Class " + program->ClassName()->GetString() + " redefined" << std::endl;
	}
	curClass = symbolsTable->GetClass( program->ClassName()->GetString() );
	
	if( !curClass->AddMethod( "main", nullptr ) )
	{
		std::cout << "Method main in class " + curClass->GetName() + " redefined" << std::endl;
	} else if( isDebug ) 
	{
		std::cout << program->ClassName() << " main method was added" << std::endl;
	}

	curMethod = curClass->GetMethod( "main" );
	if( program->Statement() != nullptr )
	{
		program->Statement()->Accept( this );
	}
}

void CSymbolTableBuilderVisitor::visit( const CClassDeclsList* program )
{
	if( program->ClassDecls() != nullptr )
	{
		program->ClassDecls()->Accept( this );
	}
	
	if( program->ClassDeclsList() != nullptr )
	{
		program->ClassDeclsList()->Accept( this );
	}
}

void CSymbolTableBuilderVisitor::visit( const CClassDecls* program )
{
	if( !symbolsTable->AddClass( program->ClassName()->GetString()) )
	{
		std::cout << "Class " + program->ClassName()->GetString() + " redefined" << std::endl;
	}

	curClass = symbolsTable->GetClass( program->ClassName()->GetString() );
	
	if ( !program->ParentName()->GetString().empty() )
	{
		SymbolsTable::CClassInfo* parentClass = symbolsTable->GetClass( program->ParentName()->GetString() );
		for( auto method : parentClass->GetMethods() ) 
		{
			method->GetReturnType()->GetType()->Accept( this );
			curClass->AddMethod( method->GetName(), lastTypeValue.get() );
		}
		for( auto var : parentClass->GerVars() )
		{
			var->GetType()->Accept( this );
			curClass->AddVar( var->GetName(), lastTypeValue.get() );
		}
	}

	if( program->VarDeclList() != nullptr )
	{
		program->VarDeclList()->Accept( this );
	}
	if( program->MethodDeclList() != nullptr )
	{
		program->MethodDeclList()->Accept( this );
	}
}

void CSymbolTableBuilderVisitor::visit( const CVarDecl* program )
{
	program->Type()->Accept( this );
	IType* type = lastTypeValue.get();
	std::string id = program->Name()->GetString();

	if( curClass == nullptr )
	{
		std::cout << "Var " + id + " is defined out of scope" << std::endl;
	} 
	else if( curMethod == nullptr )
	{
		if( !curClass->AddVar( id, type ) )
		{
			std::cout << "Var " + id + " is already defined in " + curClass->GetName() << std::endl;
		}
	} 
	else if( !curMethod->AddLocalVar( id, type ) )
	{
		std::cout << "Var " + id + " is already defined in " + curMethod->GetName() << std::endl;
	}
}

void CSymbolTableBuilderVisitor::visit( const CVarDeclList* program )
{
	if( program->VarDecl() != nullptr )
	{
		program->VarDecl()->Accept( this );
	}
	if( program->VarDeclList() != nullptr )
	{
		program->VarDeclList()->Accept( this );
	}
}

void CSymbolTableBuilderVisitor::visit( const CFormalList* list )
{
	list->Type()->Accept( this );
	IType* type = lastTypeValue.get();
	std::string id = list->Id()->GetString();

	if( curMethod == nullptr )
	{
		std::cout << "Var " + id + " is defined out of scope" << std::endl;
	}
	else if( !curMethod->AddLocalVar( id, type ) )
	{
		std::cout << "Var " + id + " is already defined in " + curMethod->GetName() << std::endl;
	}

	if( list->FormalRest() != nullptr )
	{
		list->FormalRest()->Accept( this );
	}
}

void CSymbolTableBuilderVisitor::visit( const CFormalRest* list )
{
	if( list->FormalRest() != nullptr )
	{
		list->FormalRest()->Accept( this );
	}
}

void CSymbolTableBuilderVisitor::visit( const CMethodDecl* program )
{
	program->Type()->Accept( this );
	IType* returnType = lastTypeValue.get();

	if( curClass == nullptr )
	{
		std::cout << "Method " << program->Name()->GetString() + " is defined out of scope" << std::endl;
	} else if( !curClass->AddMethod( program->Name()->GetString(), returnType ) ) {
		std::cout << "Method " << program->Name()->GetString() + " is already defined in class " << curClass->GetName() << std::endl;
	} else {
		curMethod = curClass->GetMethod( program->Name()->GetString() );
		if( program->FormalList() != nullptr )
		{
			program->FormalList()->Accept( this );
		}
		if( program->VarDeclList() != nullptr )
		{
			program->VarDeclList()->Accept( this );
		}
	}
}

void CSymbolTableBuilderVisitor::visit( const CMethodDeclList* methodList )
{
	if( methodList->MethodDecl() != nullptr ) {
		methodList->MethodDecl()->Accept( this );
	}
	if( methodList->MethodDeclList() != nullptr ) {
		methodList->MethodDeclList()->Accept( this );
	}
}

void CSymbolTableBuilderVisitor::visit( const CType* program )
{
	lastTypeValue = std::make_shared<CType>( *program );
}

void CSymbolTableBuilderVisitor::visit( const CUserType* program )
{
	lastTypeValue = std::make_shared<CUserType>( *program );
}