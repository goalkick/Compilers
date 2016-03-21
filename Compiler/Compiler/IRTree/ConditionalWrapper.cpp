#include "Translate.h"
#include "IRTree.h"

namespace Translate {

const IRTree::IStm* CConditionalWrapper::ToStm() const {
	Temp::Label* tempLabel = new Temp::Label();
	IRTree::LABEL* irLabel = new IRTree::LABEL( tempLabel );
	const IRTree::IStm* cond = ToConditional( tempLabel, tempLabel );
	const IRTree::SEQ* seq = new IRTree::SEQ( cond, irLabel );
	return seq;
}

const IRTree::IExp* CConditionalWrapper::ToExp() const {
	Temp::Temp* temp = new Temp::Temp();
	IRTree::TEMP* irTemp = new IRTree::TEMP( *temp );
	IRTree::MOVE* moveTrue = new IRTree::MOVE( irTemp, new IRTree::CONST( 1 ) );
	IRTree::MOVE* moveFalse = new IRTree::MOVE( irTemp, new IRTree::CONST( 0 ) );
	Temp::Label* trueLabel = new Temp::Label();
	Temp::Label* falseLabel = new Temp::Label();
	IRTree::LABEL* trueIRLabel = new IRTree::LABEL( trueLabel );
	IRTree::LABEL* falseIRLabel = new IRTree::LABEL( falseLabel );
	IRTree::SEQ* seqTrue = new IRTree::SEQ( trueIRLabel, moveTrue );
	IRTree::SEQ* seqFalse = new IRTree::SEQ( falseIRLabel, moveFalse );
	const IRTree::IStm* cond = ToConditional( trueLabel, falseLabel );
	IRTree::ESEQ* eseq = new IRTree::ESEQ( cond, irTemp );
	return eseq;
}

const IRTree::IStm* CConditionalWrapper::ToConditional( const Temp::Label* t, const Temp::Label* f ) const
{
	auto asBinop = dynamic_cast< const IRTree::BINOP_ENUM* >( exp );
	if( asBinop != nullptr ) {
		return binopToConditional( asBinop, t, f );
	} else {
		return new IRTree::CJUMP( IRTree::NOT_EQUAL, exp, new IRTree::CONST( 0 ), t, f );
	}
}

const IRTree::IStm* CConditionalWrapper::binopToConditional( const IRTree::BINOP_ENUM* binop, const Temp::Label* t, const Temp::Label* f ) const
{
	switch( binop->binop ) {
		case IRTree::AND:
			return andBinopToConditional( binop, t, f );
		case IRTree::LSHIFT:
			return new IRTree::CJUMP( IRTree::LESS, binop->left.get(), binop->right.get(), t, f );
		case IRTree::RSHIFT:
			return new IRTree::CJUMP( IRTree::GREATER, binop->left.get(), binop->right.get(), t, f );
		case IRTree::PLUS:
		case IRTree::MINUS:
		case IRTree::MUL:
		case IRTree::DIV:
		case IRTree::XOR:
			return new IRTree::CJUMP( IRTree::NOT_EQUAL, binop, new IRTree::CONST( 0 ), t, f );
		default:
			//assert( false );
			return nullptr;
	}
}

const IRTree::IStm* CConditionalWrapper::andBinopToConditional( const IRTree::BINOP_ENUM* binop, const Temp::Label* t, const Temp::Label* f ) const
{
	Temp::Label* firstTrueLabel = new Temp::Label();
	IRTree::LABEL* firstTrueIRLabel = new IRTree::LABEL( firstTrueLabel );

	
	CConditionalWrapper leftWrapper( binop->left.get() );
	CConditionalWrapper rightWrapper( binop->right.get() );

	return new IRTree::SEQ( leftWrapper.ToConditional(firstTrueLabel, f), firstTrueIRLabel, rightWrapper.ToConditional( t, f ) );
}

} 