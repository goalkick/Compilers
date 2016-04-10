#pragma once
#include "IRTree.h"
#include "Temp.h"
#include "SubtreeWrapper.h"

namespace Translate {

class CStmConverter : public ISubtreeWrapper {
public:
	CStmConverter( IRTree::IStm* e) : expr( e ) {}
	const IRTree::IExp* ToExp() const { }
	const IRTree::IStm* ToStm() const { return expr; }
	const IRTree::IStm* ToConditional( const Temp::CLabel* t, const Temp::CLabel* f ) const { }
private:
	IRTree::IStm* expr;
};

};