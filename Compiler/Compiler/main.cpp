//int yyparse( int* );
#include "parser.tab.hpp"

int main()
{
	int a = 9;
	while( yyparse() != 0 );
	return 0;
}