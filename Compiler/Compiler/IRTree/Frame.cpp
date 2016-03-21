#pragma once

#include "Frame.h"

namespace Frame {

	CFrame::CFrame( const std::string _name ) :
		Name( _name ),
		ThisCounter( 0 ),
		LocalCounter( 0 )
	{
		for( int i = 0; i < R_Count; ++i ) {
			registers.emplace_back( const Temp::Temp( new const Temp::Temp( to_string( static_cast< TRegisters >( i ) ) ) ) );
		}
	}

	const Temp::Temp* CFrame::GetRegister( TRegisters registerType ) const
	{
		//assert( registerType >= R_EAX && registerType < R_Count );
		return registers.at( registerType ).get();
	}

	const Temp::Temp* CFrame::FramePointer() const
	{
		return GetRegister( R_EBP );
	}

	const IRTree::IExp* CFrame::ThisPointerExp() const
	{
		return new IRTree::MEM( new IRTree::TEMP( *FramePointer() ) );
	}

	const Temp::Temp* CFrame::ReturnValue() const
	{
		return GetRegister( R_EAX );
	}

	const IAccess* CFrame::GetFormal( std::string name ) const
	{
		auto result = formals.find( name );
		if (result == formals.end()) {
			return 0;
		}
		return result->second;
	}

	void CFrame::AddFormal(const std::string _name, const IAccess* _var)
	{
		formals.insert( std::make_pair( _name, _var ) );
	}

	const IAccess* CFrame::GetLocal( std::string name ) const
	{
		auto result = locals.find(name);
		if (result == locals.end()) {
			return 0;
		}
		return result->second;
	}

	void CFrame::AddLocal( const std::string _name, const IAccess* _var )
	{
		locals.insert( std::make_pair( _name, _var ) );
	}

	const IAccess* CFrame::GetAccess( std::string _name ) const
	{
		const IAccess* result = GetFormal( _name );
		if( result != 0 ) {
			return result;
		}
		result = GetLocal( _name );
		if( result != 0 ) {
			return result;
		}
		result = GetField( _name );
		if( result != 0 ) {
			return result;
		}
		return nullptr;
	}

	const IAccess* CFrame::GetField( std::string name ) const
	{
		auto result = fields.find( name );
		if( result == fields.end() ) {
			return 0;
		}
		return result->second;
	}

	void CFrame::AddField( const std::string _name, const IAccess* _var )
	{
		fields.insert( std::make_pair( _name, _var ) );
	}

	const IRTree::IExp* CInFrame::ToExp( const Frame::CFrame* frame ) const
	{
		// ��������� � ������� ������� �������.
		// ��������� 7 = 6 ��������� + ����� ��������.
		return new IRTree::MEM( new IRTree::BINOP(
			IRTree::MINUS, new IRTree::TEMP( *( frame->FramePointer() ) ),
			new IRTree::BINOP( IRTree::MUL, new IRTree::CONST( number + 7 ), new IRTree::CONST( frame->WordSize() ) ) ) );
	}

	const IRTree::IExp* CInObject::ToExp( const Frame::CFrame* frame ) const
	{
		return new IRTree::MEM( new IRTree::BINOP(
			IRTree::PLUS, frame->ThisPointerExp(), new IRTree::BINOP( IRTree::MUL,
			new IRTree::CONST( offsetInWords ), new IRTree::CONST( frame->WordSize() ) ) ) );
	}

	const IRTree::IExp* CFormalParameterInStack::ToExp( const Frame::CFrame* frame ) const
	{
		return new IRTree::MEM( new IRTree::BINOP(
			IRTree::PLUS, new IRTree::TEMP( *( frame->FramePointer() ) ), new IRTree::BINOP( IRTree::MUL,
				new IRTree::CONST( number ), new IRTree::CONST( frame->WordSize() ) ) ) );
	}

	std::string to_string( TRegisters registerType )
	{
		switch( registerType ) {
			case Frame::R_EAX:
				return std::string( "EAX" );
			case Frame::R_EBX:
				return std::string( "EBX" );
			case Frame::R_EDX:
				return std::string( "EDX" );
			case Frame::R_ECX:
				return std::string( "ECX" );
			case Frame::R_EBP:
				return std::string( "EBP" );
			case Frame::R_ESI:
				return std::string( "ESI" );
			case Frame::R_EDI:
				return std::string( "EDI" );
			case Frame::R_ESP:
				return std::string( "ESP" );
			default:
				return std::string( "Unknown register" );
		}
	}

} 