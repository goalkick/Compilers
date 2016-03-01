#pragma once

#include <vector>
#include "IRTree.h"
#include <map>

namespace Frame {

	enum TRegisters {
		R_EAX,
		R_EBX,
		R_EDX,
		R_ECX,
		R_EBP,
		R_ESI,
		R_EDI,
		R_ESP,

		R_Count
	};

	std::string to_string( TRegisters registerType );

	class CFrame;

	// ��������� ��� ���������� ������
	class IAccess {
	public:
		virtual const IRTree::IExp* ToExp( const Frame::CFrame* frame ) const = 0;
		virtual ~IAccess() {}
	};

	// ��� ��������� ����������, ������� ����� �� ��������� � FramePointer
	class CInFrame : public IAccess {
	public:
		explicit CInFrame( int _number ) : number( _number ) {}
		virtual const IRTree::IExp* ToExp( const Frame::CFrame* frame ) const override;

	private:
		// ���������� ����� ��������� ����������
		const int number;
	};

	// ��� ����� ������, ������� ����� �� this
	class CInObject : public IAccess {
	public:
		CInObject( int _offsetInWords ) : offsetInWords( _offsetInWords ) {}
		virtual const IRTree::IExp* ToExp( const Frame::CFrame* frame ) const override;

	private:
		const int offsetInWords;
	};

	// �������� �������, ������� �� �����.
	class CFormalParameterInStack : public IAccess {
	public:
		explicit CFormalParameterInStack( int _number ) : number( _number ) {}
		virtual const IRTree::IExp* ToExp( const Frame::CFrame* frame ) const;

	private:
		// ���������� ����� ���������, ����������� ��� ���������� �������� �������
		// ������� �������� � 1
		// 0 ������������� ��� this ������� �� ������������ ���������� ����� ����
		const int number;
	};

	// �����-��������� � ������������������ ����������� � �������
	class CFrame {
	public:
		// ������ IRTree ��� ������� �������
		const IRTree::IStm* Stm;
		// ���������������� ��� �������
		//	���_������__���_�������
		const std::string Name;
		// ������� �������� ����� ������.
		int ThisCounter;
		// ������� �������� ��������� ����������.
		int LocalCounter;
		// ������� ��������� ����������
		static int WordSize() { return 4; }

		explicit CFrame( const std::string _name );

		// ����������������� ��������
		const Temp::Temp* GetRegister( TRegisters registerType ) const;
		// FP ����� ��� ���� ����� �������� �������� ��� ��������� ���������� ������ �������
		const Temp::Temp* FramePointer() const;
		// this ����� ����� �������� �������� �� ���� ������� ������
		const IRTree::IExp* ThisPointerExp() const;
		// Temp ��� ������������� ��������.
		const Temp::Temp* ReturnValue() const;

		// ������ � ���������� ����������
		const IAccess* GetFormal( std::string name ) const;
		void AddFormal( const std::string _name, const IAccess* _var );
		// ������ � ��������� ����������
		const IAccess* GetLocal( std::string name ) const;
		void AddLocal( const std::string _name, const IAccess* _var );
		// ������ � ����� ������
		const IAccess* GetField( std::string name ) const;
		void AddField( const std::string _name, const IAccess* _var );
		// ������ � ���������� (�� �������� ����� local, formal ��� �����-�� ������)
		const IAccess* GetAccess( std::string _name ) const;

	private:
		std::map<const std::string, const IAccess* > formals;
		std::map<const std::string, const IAccess* > locals;
		std::map<const std::string, const IAccess* > fields;

		std::vector< const Temp::Temp* > registers;
	};

} 