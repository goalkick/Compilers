#pragma once

#include <string>

namespace Temp {

	// ����� - ����� �������� � ����
	class Label {
	public:
		Label( const Label& src ) : name( src.name ) {}
		
		// ������� ����� � ���������� ������
		Label()
		{
			name = "tempLabel" + std::to_string( nextUniqueId );
			nextUniqueId++;
		}

		// ������� ����� � �������� ������
		Label( const std::string& _name ) :
			name( _name ) 
		{}

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
		Temp( const Temp& src ) : name( src.name ) {}
		
		// ����� ���������� � ���������� ������
		Temp()
		{
			name = "tempVar" + std::to_string( nextUniqueId );
			nextUniqueId++;
		}

		// ����� ���������� � �������� ������
		Temp( const std::string& _name ) :
			name( _name )
		{}

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

	int Label::nextUniqueId = 0;
	int Temp::nextUniqueId = 0;

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