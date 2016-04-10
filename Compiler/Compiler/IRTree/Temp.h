#pragma once

#include <string>

namespace Temp {

// ����� - ����� �������� � ����
class CLabel {
public:		
	CLabel()
	{
		name = "tempLabel" + std::to_string( nextUniqueId );
		nextUniqueId++;
	}

	CLabel( const CLabel& src ) : name( src.name ) {}

	CLabel( const std::string& _name ) :
		name( _name ) 
	{}

	const std::string& Name() const 
	{ 
		return name; 
	}

	bool operator==(const CLabel& label) const
	{ 
		return name == label.name; 
	}

	bool operator!=(const CLabel& label) const
	{ 
		return !this->operator==( label ); 
	}

private:
	static int nextUniqueId; // ������� ��� �������� ���������� ���������������
	std::string name;
};

// ��������� ����������
class CTemp {
public:	
	CTemp()
	{
		name = "tempVar" + std::to_string( nextUniqueId );
		nextUniqueId++;
	}

	CTemp( const CTemp* src ) : 
		name( src->name ) 
	{}
		
	CTemp( const std::string& _name ) :
		name( _name )
	{}

	const std::string& Name() const 
	{ 
		return name; 
	}

	bool operator==( const CTemp& temp ) const
	{ 
		return name == temp.name; 
	}
	bool operator!=( const CTemp& temp ) const
	{ 
		return !this->operator==( temp ); 
	}

private:	
	static int nextUniqueId; // ������� ��� �������� ���������� ���
	std::string name;
};


} 

namespace std {

// what is it?
template <> 
struct hash<Temp::CTemp> {
	size_t operator()( const Temp::CTemp& value ) const
	{
		return hash<std::string>()( value.Name() );
	}
};

template <>
struct hash<Temp::CLabel> {
	size_t operator()( const Temp::CLabel& value ) const
	{
		return hash<std::string>()( value.Name() );
	}
};

} 

