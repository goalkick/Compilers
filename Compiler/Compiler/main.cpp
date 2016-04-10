//#include "parser.tab.hpp"
#include "PrettyPrinter.h"
#include "SymbolsTableVisitor.h"
#include "TypeChecker.h"
#include "IRTree\IRForestBuilder.h"

extern int yyparse( std::shared_ptr<CProgram>& );

int main()
{
	std::shared_ptr<CProgram> root;
	// ����������� � �������������� ������
	while( yyparse( root ) != 0 );

	// ����� ������������ ������
	CPrettyPrinter* printer( new CPrettyPrinter );
	root->Accept( printer );
	
	// ���������� ������� ��������
	CSymbolTableBuilderVisitor* symbolTableBuilder( new CSymbolTableBuilderVisitor );
	root->Accept( symbolTableBuilder );

	// �������� �����
	CTypeCheckerVisitor* typeChecker( new CTypeCheckerVisitor((symbolTableBuilder->GetSymbolsTable()).get()) );
	root->Accept( typeChecker );

	// ���������� IR ������
	Translate::CIRForestBuilder* irForestBuilder( new Translate::CIRForestBuilder( (symbolTableBuilder->GetSymbolsTable()).get() ) );
	root->Accept( irForestBuilder );
	// ������������ IR-��������
	for( const auto& frame : irForestBuilder.Methods ) {
		// �������� ������� ��� ��������� �������
		IRTree::CIRTreeToDigraphConverter irTreeToDigraphConverter( std::string( "IRTree_" ) 
			+ frame->Name + std::string( ".dot" ) );
		frame->Stm->Accept( irTreeToDigraphConverter );
		irTreeToDigraphConverter.Flush();
	}

	return 0;
}