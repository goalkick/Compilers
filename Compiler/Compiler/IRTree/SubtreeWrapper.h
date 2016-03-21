#pragma once
#include <IRTree.h>
#include <Temp.h>

namespace Translate {

class ISubtreeWrapper {
public:
	const virtual IRTree::IExp* ToExp( ) const = 0;
	const virtual IRTree::IStm* ToStm( ) const = 0;
	const virtual IRTree::IStm* ToConditional( const Temp::CLabel* t, const Temp::CLabel* f ) const = 0;

};

};