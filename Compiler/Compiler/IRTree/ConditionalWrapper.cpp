#pragma once
#include "ConditionalWrapper.h"

namespace Translate {

const IRTree::IStm* CConditionalWrapper::ToStm() const {
	Temp::CLabel* tempLabel = new Temp::CLabel();
	IRTree::CLabel* irLabel = new IRTree::CLabel( tempLabel );
	const IRTree::IStm* cond = ToConditional( tempLabel, tempLabel );
	const IRTree::CSeq* seq = new IRTree::CSeq( cond, irLabel );
	return seq;
}

const IRTree::IExp* CConditionalWrapper::ToExp() const {
	Temp::CTemp* temp = new Temp::CTemp();
	IRTree::CTemp* irTemp = new IRTree::CTemp( *temp );
	IRTree::CMove* moveTrue = new IRTree::CMove( irTemp, new IRTree::CConst( 1 ) );
	IRTree::CMove* moveFalse = new IRTree::CMove( irTemp, new IRTree::CConst( 0 ) );
	Temp::CLabel* trueLabel = new Temp::CLabel();
	Temp::CLabel* falseLabel = new Temp::CLabel();
	IRTree::CLabel* trueIRLabel = new IRTree::CLabel( trueLabel );
	IRTree::CLabel* falseIRLabel = new IRTree::CLabel( falseLabel );
	IRTree::CSeq* seqTrue = new IRTree::CSeq( trueIRLabel, moveTrue );
	IRTree::CSeq* seqFalse = new IRTree::CSeq( falseIRLabel, moveFalse );
	const IRTree::IStm* cond = ToConditional( trueLabel, falseLabel );
	IRTree::CEseq* eseq = new IRTree::CEseq( cond, irTemp );
	return eseq;
}

const IRTree::IStm* CConditionalWrapper::ToConditional( const Temp::CLabel* t, const Temp::CLabel* f ) const
{
	auto asBinop = dynamic_cast< const IRTree::CBinop* >( exp );
	if( asBinop != nullptr ) {
		return binopToConditional( asBinop, t, f );
	} else {
		return new IRTree::CCJump( IRTree::CJ_NotEqual, exp, new IRTree::CConst( 0 ), t, f );
	}
}

const IRTree::IStm* CConditionalWrapper::binopToConditional( const IRTree::CBinop* binop, const Temp::CLabel* t, const Temp::CLabel* f ) const
{
	switch( binop->binop ) {
		case IRTree::B_And:
			return andBinopToConditional( binop, t, f );
		//case IRTree::LSHIFT:
			//return new IRTree::CCJump( IRTree::B_Less, binop->left.get(), binop->right.get(), t, f );
		//case IRTree::RSHIFT:
			return new IRTree::CCJump( IRTree::CJ_Greater, binop->left, binop->right, t, f );
		case IRTree::B_Plus:
		case IRTree::B_Minus:
		case IRTree::B_Mul:
		case IRTree::B_Division:
		case IRTree::B_Xor:
			return new IRTree::CCJump( IRTree::CJ_NotEqual, binop, new IRTree::CConst( 0 ), t, f );
		default:
			//assert( false );
			return nullptr;
	}
}

const IRTree::IStm* CConditionalWrapper::andBinopToConditional( const IRTree::CBinop* binop, const Temp::CLabel* t, const Temp::CLabel* f ) const
{
	Temp::CLabel* firstTrueLabel = new Temp::CLabel();
	IRTree::CLabel* firstTrueIRLabel = new IRTree::CLabel( firstTrueLabel );

	
	CConditionalWrapper leftWrapper( binop->left );
	CConditionalWrapper rightWrapper( binop->right );

	return new IRTree::CSeq( leftWrapper.ToConditional(firstTrueLabel, f), firstTrueIRLabel, rightWrapper.ToConditional( t, f ) );
}

} 