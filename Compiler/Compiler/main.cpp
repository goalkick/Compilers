//#include "parser.tab.hpp"
#include "PrettyPrinter.h"
#include "SymbolsTableVisitor.h"

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

	return 0;
}