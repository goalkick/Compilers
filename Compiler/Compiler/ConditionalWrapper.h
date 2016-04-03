#include "SubtreeWrapper.h"
#include "IRTree.h"

namespace Translate {
	
class CConditionalWrapper : public ISubtreeWrapper {
public:
	CConditionalWrapper( const IRTree::IExp* _exp ) : exp( _exp ) {}
	const IRTree::IExp* ToExp() const;
	const IRTree::IStm* ToStm() const;
	const IRTree::IStm* ToConditional( const Temp::CLabel* t, const Temp::CLabel* f ) const;
private:
	const IRTree::IExp* exp;

	const IRTree::IStm* binopToConditional( const IRTree::CBinop* binop, const Temp::CLabel* t, const Temp::CLabel* f ) const;
	const IRTree::IStm* andBinopToConditional( const IRTree::CBinop* binop, const Temp::CLabel* t, const Temp::CLabel* f ) const;
};

}