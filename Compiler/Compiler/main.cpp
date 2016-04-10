//#include "parser.tab.hpp"
#include "PrettyPrinter.h"
#include "SymbolsTableVisitor.h"
#include "TypeChecker.h"
#include "IRTree\IRForestBuilder.h"

extern int yyparse( std::shared_ptr<CProgram>& );

int main()
{
	std::shared_ptr<CProgram> root;
	// лексический и синтаксический анализ
	while( yyparse( root ) != 0 );

	// вывод абстрактного дерева
	CPrettyPrinter* printer( new CPrettyPrinter );
	root->Accept( printer );
	
	// построение таблицы символов
	CSymbolTableBuilderVisitor* symbolTableBuilder( new CSymbolTableBuilderVisitor );
	root->Accept( symbolTableBuilder );

	// проверка типов
	CTypeCheckerVisitor* typeChecker( new CTypeCheckerVisitor((symbolTableBuilder->GetSymbolsTable()).get()) );
	root->Accept( typeChecker );

	// построение IR дерева
	Translate::CIRForestBuilder* irForestBuilder( new Translate::CIRForestBuilder( (symbolTableBuilder->GetSymbolsTable()).get() ) );
	root->Accept( irForestBuilder );
	// визуализация IR-деревьев
	for( const auto& frame : irForestBuilder.Methods ) {
		// Печатаем деревья для отдельной функции
		IRTree::CIRTreeToDigraphConverter irTreeToDigraphConverter( std::string( "IRTree_" ) 
			+ frame->Name + std::string( ".dot" ) );
		frame->Stm->Accept( irTreeToDigraphConverter );
		irTreeToDigraphConverter.Flush();
	}

	return 0;
}