#pragma once
#include "IRTree.h"
#include "Temp.h"
#include "IRTree/SubtreeWrapper.h"

namespace Translate {

class CStmConverter : public ISubtreeWrapper {
public:
	CStmConverter( IRTree::IStm* e) : expr( e ) {}
	IRTree::IExp* ToExp() const { }
	IRTree::IStm* ToStm() const { return expr; }
	IRTree::IStm* ToConditional( const Temp::CLabel* t, const Temp::CLabel* f ) const { }
private:
	IRTree::IStm* expr;
};

};