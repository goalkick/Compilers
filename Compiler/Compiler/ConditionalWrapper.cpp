#include "Translate.h"
#include "IRTree.h"

namespace Translate {

const IRTree::IStm* CConditionalWrapper::ToStm() const {
	Temp::Label* tempLabel = new Temp::Label();
	IRTree::CLabel* irLabel = new IRTree::CLabel( tempLabel );
	const IRTree::IStm* cond = ToConditional( tempLabel, tempLabel );
	const IRTree::CSeq* seq = new IRTree::CSeq( cond, irLabel );
	return seq;
}

const IRTree::IExp* CConditionalWrapper::ToExp() const {
	Temp::Temp* temp = new Temp::Temp();
	IRTree::CTemp* irTemp = new IRTree::CTemp( *temp );
	IRTree::CMove* moveTrue = new IRTree::CMove( irTemp, new IRTree::CConst( 1 ) );
	IRTree::CMove* moveFalse = new IRTree::CMove( irTemp, new IRTree::CConst( 0 ) );
	Temp::Label* trueLabel = new Temp::Label();
	Temp::Label* falseLabel = new Temp::Label();
	IRTree::CLabel* trueIRLabel = new IRTree::CLabel( trueLabel );
	IRTree::CLabel* falseIRLabel = new IRTree::CLabel( falseLabel );
	IRTree::CSeq* seqTrue = new IRTree::CSeq( trueIRLabel, moveTrue );
	IRTree::CSeq* seqFalse = new IRTree::CSeq( falseIRLabel, moveFalse );
	const IRTree::IStm* cond = ToConditional( trueLabel, falseLabel );
	IRTree::ECSeq* eseq = new IRTree::ECSeq( cond, irTemp );
	return eseq;
}

const IRTree::IStm* CConditionalWrapper::ToConditional( const Temp::Label* t, const Temp::Label* f ) const
{
	auto asBinop = dynamic_cast< const IRTree::BINOP_ENUM* >( exp );
	if( asBinop != nullptr ) {
		return binopToConditional( asBinop, t, f );
	} else {
		return new IRTree::CCJump( IRTree::NOT_EQUAL, exp, new IRTree::CConst( 0 ), t, f );
	}
}

const IRTree::IStm* CConditionalWrapper::binopToConditional( const IRTree::BINOP_ENUM* binop, const Temp::Label* t, const Temp::Label* f ) const
{
	switch( binop->binop ) {
		case IRTree::AND:
			return andBinopToConditional( binop, t, f );
		case IRTree::LSHIFT:
			return new IRTree::CCJump( IRTree::LESS, binop->left.get(), binop->right.get(), t, f );
		case IRTree::RSHIFT:
			return new IRTree::CCJump( IRTree::GREATER, binop->left.get(), binop->right.get(), t, f );
		case IRTree::B_Plus:
		case IRTree::MINUS:
		case IRTree::MUL:
		case IRTree::DIV:
		case IRTree::XOR:
			return new IRTree::CCJump( IRTree::NOT_EQUAL, binop, new IRTree::CConst( 0 ), t, f );
		default:
			//assert( false );
			return nullptr;
	}
}

const IRTree::IStm* CConditionalWrapper::andBinopToConditional( const IRTree::BINOP_ENUM* binop, const Temp::Label* t, const Temp::Label* f ) const
{
	Temp::Label* firstTrueLabel = new Temp::Label();
	IRTree::CLabel* firstTrueIRLabel = new IRTree::CLabel( firstTrueLabel );

	
	CConditionalWrapper leftWrapper( binop->left.get() );
	CConditionalWrapper rightWrapper( binop->right.get() );

	return new IRTree::CSeq( leftWrapper.ToConditional(firstTrueLabel, f), firstTrueIRLabel, rightWrapper.ToConditional( t, f ) );
}

} 