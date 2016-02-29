#include "IRTree.h"

namespace Translate {

	

// ������-�����a ��� ������������� �����������, ������� ����� ���������� 
//	���������� ��� �� Tree � ����������� �� ��������:
	class ISubtreeWrapper {
	public:
		virtual ~ISubtreeWrapper() { }
		virtual const IRTree::IExp* ToExp() const = 0; // ��� Expr
		virtual const IRTree::IStm* ToStm() const = 0; // ��� Stm
		virtual const IRTree::IStm* ToConditional(
							 const Temp::CLabel* t, const Temp::CLabel* f) const = 0; // ��� if/jump
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

}