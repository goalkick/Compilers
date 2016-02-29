#pragma once

#include <string>

namespace Temp {

// ����� - ����� �������� � ����
class Label {
public:
	// ������� ����� � ���������� ������
	Label();
	Label( const Label& src ) : name( src.name ) {}
	// ������� ����� � �������� ������
	explicit Label( const std::string& name );

	const std::string& Name() const { return name; }

	bool operator == (const Label& other) const
		{ return name == other.name; }
	bool operator != (const Label& other) const
		{ return !this->operator==( other ); }

private:
	// ������� ��� �������� ���������� ���������������
	static int nextUniqueId;
	std::string name;
};

// ��������� ����������
class Temp {
public:
	// ����� ���������� � ���������� ������
	Temp();
	Temp( const Temp& src ) : name( src.name ) {}
	// ����� ���������� � �������� ������
	explicit Temp( const std::string& name );

	const std::string& Name() const { return name; }

	bool operator == (const Temp& other) const
		{ return name == other.name; }
	bool operator != (const Temp& other) const
		{ return !this->operator==( other ); }

private:
	// ������� ��� �������� ���������� ���
	static int nextUniqueId;
	std::string name;
};

} 

namespace std {

template <> 
struct hash<Temp::Temp> {
	size_t operator()( const Temp::Temp& value ) const
	{
		return hash<std::string>()( value.Name() );
	}
};

template <>
struct hash<Temp::Label> {
	size_t operator()( const Temp::Label& value ) const
	{
		return hash<std::string>()( value.Name() );
	}
};

} 