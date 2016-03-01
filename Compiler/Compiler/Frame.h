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

	// Интерфейс для переменной фрейма
	class IAccess {
	public:
		virtual const IRTree::IExp* ToExp( const Frame::CFrame* frame ) const = 0;
		virtual ~IAccess() {}
	};

	// для локальных переменных, которые лежат со смещением у FramePointer
	class CInFrame : public IAccess {
	public:
		explicit CInFrame( int _number ) : number( _number ) {}
		virtual const IRTree::IExp* ToExp( const Frame::CFrame* frame ) const override;

	private:
		// Порядковый номер локальной переменной
		const int number;
	};

	// Для полей класса, которые лежат по this
	class CInObject : public IAccess {
	public:
		CInObject( int _offsetInWords ) : offsetInWords( _offsetInWords ) {}
		virtual const IRTree::IExp* ToExp( const Frame::CFrame* frame ) const override;

	private:
		const int offsetInWords;
	};

	// Аргумент функции, лежащий на стеке.
	class CFormalParameterInStack : public IAccess {
	public:
		explicit CFormalParameterInStack( int _number ) : number( _number ) {}
		virtual const IRTree::IExp* ToExp( const Frame::CFrame* frame ) const;

	private:
		// Порядковый номер аргумента, переданного как формальный параметр функции
		// Считать начинаем с 1
		// 0 резервируется для this который мы договорились передавать через стек
		const int number;
	};

	// Класс-контейнер с платформозависимой информацией о функции
	class CFrame {
	public:
		// Корень IRTree для текущей функции
		const IRTree::IStm* Stm;
		// Задекорированное имя функции
		//	Имя_класса__имя_функции
		const std::string Name;
		// Счетчик отступов полей класса.
		int ThisCounter;
		// Счетчик отступов локальных переменных.
		int LocalCounter;
		// Машинно зависимая информация
		static int WordSize() { return 4; }

		explicit CFrame( const std::string _name );

		// Зарезервированные регистры
		const Temp::Temp* GetRegister( TRegisters registerType ) const;
		// FP нужен для того чтобы получать смещение для локальных переменных внутри функции
		const Temp::Temp* FramePointer() const;
		// this нужен чтобы получать смещения на поля объекта класса
		const IRTree::IExp* ThisPointerExp() const;
		// Temp для возвращаемого значения.
		const Temp::Temp* ReturnValue() const;

		// Доступ к формальным параметрам
		const IAccess* GetFormal( std::string name ) const;
		void AddFormal( const std::string _name, const IAccess* _var );
		// Доступ к локальным переменным
		const IAccess* GetLocal( std::string name ) const;
		void AddLocal( const std::string _name, const IAccess* _var );
		// Доступ к полям класса
		const IAccess* GetField( std::string name ) const;
		void AddField( const std::string _name, const IAccess* _var );
		// Доступ к переменной (не известно какой local, formal или какой-то другой)
		const IAccess* GetAccess( std::string _name ) const;

	private:
		std::map<const std::string, const IAccess* > formals;
		std::map<const std::string, const IAccess* > locals;
		std::map<const std::string, const IAccess* > fields;

		std::vector< const Temp::Temp* > registers;
	};

} 