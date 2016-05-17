#include "Canonization.h"

using namespace IRTree;

void CCanonizer::visit( CMove* node ) {
	node->dst->Accept( this );
	IExp* arg1 = dynamic_cast<IExp*>( current_node );
	node->src->Accept( this );
	IExp* arg2 = dynamic_cast<IExp*>( current_node );
	current_node = ( doStm( new CMove( arg1, arg2 ) ) );
}

void CCanonizer::visit( CExp* node ) {
	node->exp->Accept( this );
	IExp* arg = dynamic_cast<IExp*>( current_node );
	current_node = doStm( new CExp( arg ) );
}

void CCanonizer::visit( CJump* node ) {
	if ( node->exp != 0 ) {
		node->exp->Accept( this );
		IExp* arg = dynamic_cast<IExp*>( current_node );
		current_node = doStm( new CJump( arg, node->target ) );
	} else {
		current_node = doStm( new CJump( node->target ) );
	}
}

void CCanonizer::visit( CCJump* node ) {
	node->left->Accept( this );
	IExp* arg1 = dynamic_cast<IExp*>( current_node );
	node->right->Accept( this );
	IExp* arg2 = dynamic_cast<IExp*>( current_node );
	current_node = doStm( new CCJump( node->relop, arg1, arg2, node->iftrue, node->iffalse ) );
}

void CCanonizer::visit( CSeq* node ) {
	node->left->Accept( this );
	IStm* arg1 = dynamic_cast<IStm*>( current_node );
	node->right->Accept( this );
	IStm* arg2 = dynamic_cast<IStm*>( current_node );
	current_node = doStm( new CSeq( arg1, arg2 ) );
}

void CCanonizer::visit( CLabel* node ) {
	current_node = node;
}

void CCanonizer::visit( CConst* node ) {
	current_node = node;
}

void CCanonizer::visit( CName* node ){
	current_node = node;
}

void CCanonizer::visit( TEMP* node ) {
	current_node = node;
}

void CCanonizer::visit( BINOP* node ) {
	node->left->Accept( this );
	IExp* arg1 = dynamic_cast<IExp*>( current_node );
	node->right->Accept( this );
	IExp* arg2 = dynamic_cast<IExp*>( current_node );
	current_node = doExp( new BINOP( node->binop, arg1, arg2 ) );
}

void CCanonizer::visit( MEM* node ) {
	node->exp->Accept( this );
	IExp* arg = dynamic_cast<IExp*>( current_node );
	current_node = doExp( new MEM( arg ) );
}

void CCanonizer::visit( CCall* node ) {
	node->func->Accept( this );
	IExp* func = dynamic_cast<IExp*>( current_node );
	IExp* arg = node->args.get( )->head;

	ExpList* newNode = nullptr;
	if ( node->args != nullptr ) {
		Visit( node->args.get( ), newNode );
		shared_ptr<ExpList> ptr( newNode );
		current_node = doExp( new CCall( func, ptr ) );
	}
}

void CCanonizer::visit( ExpList* node, ExpList*& newNode ) {
	if ( node != nullptr ){
		if ( node->tail != nullptr ){
			Visit( node->tail.get( ), newNode );
		}

		shared_ptr<ExpList> ptr( newNode );
		node->head->Accept( this );
		IExp* arg = dynamic_cast<IExp*>( current_node );
		newNode = new ExpList( doExp( arg ), ptr );
	} else {
		newNode = nullptr;
	}

}

void CCanonizer::visit( CEseq* node )  {
	node->stm->Accept( this );
	IStm* arg1 = dynamic_cast<IStm*>( current_node );
	node->exp->Accept( this );

	IExp* arg2 = dynamic_cast<IExp*>( current_node );
	current_node = doExp( new CEseq( arg1, arg2 ) );

}

void CCanonizer::visit( IRTree::MoveCall* node ) {
	assert( 0 );
}

void CCanonizer::visit( IRTree::ExpCall* node ) {
	assert( 0 );
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
bool isNop( IStm* stm ) {
	CExp* exp = dynamic_cast<CExp*>( stm );
	return ( exp != 0 ) && ( dynamic_cast<const CConst*>( exp->exp ) != 0 );
}

bool commute( IStm* stm, IExp* exp ) {
	return isNop( stm ) || ( dynamic_cast<CExp*>( exp ) != 0 ) || ( dynamic_cast<const CName*>( exp ) != 0 );
}

IStm* seq( IStm* arg1, IStm* arg2 ) {
	if ( isNop( arg1 ) ) return arg2;
	if ( isNop( arg2 ) ) return arg1;
	return new CSeq( arg1, arg2 );
}

// DoStm
IStm* doStm( CSeq* stm ) {
	return seq( doStm( stm->left ), doStm( stm->right ) );
}

IStm* doStm( CMove* stm ) {
	TEMP* temp = dynamic_cast<TEMP*>( stm->dst );
	CCall* call = dynamic_cast<CCall*>( stm->src );
	CEseq* eseq = dynamic_cast<CEseq*>( stm->dst );

	if ( ( temp != 0 ) && ( call != 0 ) )
		return reorderStm( new MoveCall( temp, call ) );
	if ( eseq != 0 )
		return doStm( new CSeq( eseq->stm, new CMove( eseq->exp, stm->src ) ) );
	return reorderStm( stm );
}

IStm* doStm( CExp* stm ) {
	CCall* call = dynamic_cast<CCall*>( stm->exp );

	if ( call != 0 )
		return reorderStm( new ExpCall( call ) );
	return reorderStm( stm );
}

IStm* doStm( IStm* stm ) {
	CSeq* seq = dynamic_cast<CSeq*>( stm );
	CMove* move = dynamic_cast<CMove*>( stm );
	CExp* exp = dynamic_cast<CExp*>( stm );

	if ( seq != 0 ) return doStm( seq );
	if ( move != 0 ) return doStm( move );
	if ( exp != 0 ) return doStm( exp );
	return reorderStm( stm );
}

// DoExp
CEseq* doExp( IExp* exp ) {
	CEseq* eseq = dynamic_cast<CEseq*>( exp );
	if ( eseq != 0 )
		return doExp( eseq );
	return reorderExp( exp );
}


CEseq* doExp( CEseq* exp ) {
	if( exp != 0 ) {
		IStm* stms = doStm( exp->stm );
		CEseq* eseq = doExp( exp->exp );
		return new CEseq( seq( stms, eseq->stm ), eseq->exp );
	}
}

// Reorder
StmExpList* reorder( ExpList* list ) {
	if ( list == nullptr ) {
		return new StmExpList( new CExp( new CConst( 0 ) ), 0 );
	}
	IExp* head = list->head;
	CCall* call = dynamic_cast<CCall*>( head );

	if ( call != 0 ) {
		shared_ptr<const Temp::CTemp> t = make_shared<const Temp::CTemp>( );
		IExp* eseq = new CEseq( new CMove( new TEMP( t ), head ), new TEMP( t ) );
		return reorder( make_shared<ExpList>( eseq, list->tail ) );
	}

	CEseq* eseq = doExp( head );
	StmExpList* stmtList = reorder( list->tail );
	if ( commute( stmtList->stm, eseq->exp ) ) {
		return new StmExpList( seq( eseq->stm, stmtList->stm ),
							   make_shared<ExpList>( eseq->exp, stmtList->exps ) );
	} else {
		shared_ptr<const Temp::CTemp> t = make_shared<const Temp::CTemp>( );
		return new StmExpList( seq( eseq->stm, seq( new CMove( new TEMP( t ), eseq->exp ), stmtList->stm ) ),
							   make_shared<ExpList>( new TEMP( t ), stmtList->exps ) );
	}
}

CEseq* reorderExp( IExp* exp ) {
	StmExpList* l = reorder( exp->kids( ) );
	return new CEseq( l->stm, exp->build( l->exps ) );
}

IStm* reorderStm( IStm* stm ) {
	StmExpList* list = reorder( stm->kids( ) );
	return seq( list->stm, stm->build( list->exps ) );
}

// Linearize
shared_ptr<StmtList> linear( IStm* s, shared_ptr<StmtList> l ) {
	CSeq* seq = dynamic_cast<CSeq*>( s );
	if ( seq != 0 )
		return linear( seq, l );
	return make_shared<StmtList>( s, l );
}

shared_ptr<StmtList> linear( CSeq* s, shared_ptr<StmtList> l ) {
	return linear( s->left, linear( s->right, l ) );
}

shared_ptr<StmtList> linearize( IStm* s ) {
	return linear( doStm( s ), nullptr );
}