//#include "parser.tab.hpp"
#include "PrettyPrinter.h"
#include "SymbolsTableVisitor.h"
#include "TypeChecker.h"

extern int yyparse( std::shared_ptr<CProgram>& );

int main()
{
	std::shared_ptr<CProgram> root;
	//while( yyparse() != 0 );
	yyparse( root );
	std::shared_ptr<CPrettyPrinter> printer( new CPrettyPrinter );
	root->Accept( printer.get() );
	
	std::shared_ptr<CSymbolTableBuilderVisitor> symbolTableBuilder( new CSymbolTableBuilderVisitor );
	root->Accept( symbolTableBuilder.get() );
	std::shared_ptr<CTypeCheckerVisitor> typeChecker( new CTypeCheckerVisitor((symbolTableBuilder->GetSymbolsTable()).get()) );
	root->Accept( typeChecker.get() );


	return 0;
}