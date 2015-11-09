#pragma once
#include <string>
#include <unordered_map>

class CSymbol {
public:
	static CSymbol* GetSymbol( const std::string& key ) 
	{
		if ( table.find( key ) == table.end() ) 
		{
			CSymbol *symbol = new CSymbol( key );
			table[key] = symbol;
			return symbol;
		}
		else 
		{
			return table.find( key )->second;
		}
	}

	const std::string& GetString() const { return name; }

private:
	const std::string name;
	static std::unordered_map<std::string, CSymbol*> table;

	CSymbol(const std::string& s) : name(s) {}
};

std::unordered_map<std::string, CSymbol*> CSymbol::table;