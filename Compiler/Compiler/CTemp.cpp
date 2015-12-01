#include "CTemp.h"

namespace Temp {
	int Label::nextUniqueId = 0;

	Label::Label()
	{
		name = std::to_string( nextUniqueId++ );
	}

	Label::Label( const CSymbol& label ) :
		name( label.GetString() )
	{}

	int Temp::nextUniqueId = 0;

	Temp::Temp()
	{
		name = std::to_string( nextUniqueId++ );
	}

	Temp::Temp( const CSymbol& symbol ) :
		name( symbol.GetString() )
	{}
} // namespace Temp
