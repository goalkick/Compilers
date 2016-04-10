#pragma once
#include <utility>

class CLocation {
	public:
		CLocation( int beginLine, int beginColumn, int endLine, int endColumn) :
			_beginLine( beginLine ),
			_beginColumn( beginColumn ),
			_endLine( endLine ),
			_endColumn( endColumn )
		{}

		std::pair<int, int> GetBeginPos() const
		{
			return std::make_pair( _beginLine, _beginColumn );
		}

		std::pair<int, int> GetEndPos() const
		{
			return std::make_pair( _endLine, _endColumn );
		}

	private:
		int _beginLine;
		int _beginColumn;
		int _endLine;
		int _endColumn;
};