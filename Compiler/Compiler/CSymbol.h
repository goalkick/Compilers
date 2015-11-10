#pragma once
#include <string>
#include <unordered_map>
#include <memory>

class CSymbol {
public:
	static CSymbol* GetSymbol( const std::string& key ) 
	{
		if ( table.find( key ) == table.end() ) 
		{
			CSymbol *symbol = new CSymbol( key );
			table[key] = std::make_shared<CSymbol>( symbol );
			return symbol;
		}
		else 
		{
			return table.find( key )->second.get();
		}
	}

	const std::string& GetString() const { return name; }

private:
	const std::string name;
	static std::unordered_map< std::string, std::shared_ptr<CSymbol> > table;

	CSymbol(const std::string& s) : name(s) {}
};

