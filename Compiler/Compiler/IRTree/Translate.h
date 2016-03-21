#include "IRTree.h"

namespace Translate {

	

// ������-�����a ��� ������������� �����������, ������� ����� ���������� 
//	���������� ��� �� Tree � ����������� �� ��������:
	class ISubtreeWrapper {
	public:
		virtual ~ISubtreeWrapper() { }
		virtual const IRTree::IExp* ToExp() const = 0; // ��� Expr
		virtual const IRTree::IStm* ToStm() const = 0; // ��� Stm
		virtual const IRTree::IStm* ToConditional( const Temp::Label* t, const Temp::Label* f) const = 0; // ��� if/jump
	};

	class CExpConverter : public ISubtreeWrapper {
	public:
		CExpConverter(const IRTree::IExp* e) : expr( e ) {}
		const IRTree::IExp* ToExp() const {return expr;}
		const IRTree::IStm* ToStm() const { ... ?... }
		const IRTree::IStm* ToConditional(const CLabel* t, const CLabel* f) const { ... ?... }
	private:
		const IRTree::IExp* expr;
	};

	class CConditionalWrapper : public ISubtreeWrapper {
	public:
		CConditionalWrapper( const IRTree::IExp* _exp ) : exp( _exp ) {}
		const IRTree::IExp* ToExp() const;
		const IRTree::IStm* ToStm() const;
		const IRTree::IStm* ToConditional( const Temp::Label* t, const Temp::Label* f ) const;
	private:
		const IRTree::IExp* exp;

		const IRTree::IStm* binopToConditional( const IRTree::BINOP_ENUM* binop, const Temp::Label* t, const Temp::Label* f ) const;
		const IRTree::IStm* andBinopToConditional( const IRTree::BINOP_ENUM* binop, const Temp::Label* t, const Temp::Label* f ) const;
	};

}