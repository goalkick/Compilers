#include "Canonization.h"

using namespace IRTree;

void CCanonizer::visit( CMove* node ) {
	node->dst->Accept( *this );
	IExp* arg1 = dynamic_cast<IExp*>( current_node );
	node->src->Accept( *this );
	IExp* arg2 = dynamic_cast<IExp*>( current_node );
	current_node = ( doStm( new CMove( arg1, arg2 ) ) );
}

void CCanonizer::visit( CExp* node ) {
	node->exp->Accept( *this );
	IExp* arg = dynamic_cast<IExp*>( current_node );
	current_node = doStm( new CExp( arg ) );
}

void CCanonizer::visit( CJump* node ) {
	if ( node->exp != 0 ) {
		node->exp->Accept( *this );
		IExp* arg = dynamic_cast<IExp*>( current_node );
		current_node = doStm( new CJump( arg, node->label ) );
	} else {
		current_node = doStm( new CJump( node->label ) );
	}
}

void CCanonizer::visit( CCJump* node ) {
	node->left->Accept( *this );
	IExp* arg1 = dynamic_cast<IExp*>( current_node );
	node->right->Accept( *this );
	IExp* arg2 = dynamic_cast<IExp*>( current_node );
	current_node = doStm( new CCJump( node->relop, arg1, arg2, node->iftrue, node->iffalse ) );
}

void CCanonizer::visit( CSeq* node ) {
	node->left->Accept( *this );
	IStm* arg1 = dynamic_cast<IStm*>( current_node );
	node->right->Accept( *this );
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

void CCanonizer::visit( CTemp* node ) {
	current_node = node;
}

void CCanonizer::visit( CBinop* node ) {
	node->left->Accept( *this );
	IExp* arg1 = dynamic_cast<IExp*>( current_node );
	node->right->Accept( *this );
	IExp* arg2 = dynamic_cast<IExp*>( current_node );
	current_node = doExp( new CBinop( node->binop, arg1, arg2 ) );
}

void CCanonizer::visit( CMem* node ) {
	node->exp->Accept( *this );
	IExp* arg = dynamic_cast<IExp*>( current_node );
	current_node = doExp( new CMem( arg ) );
}

void CCanonizer::visit( CCall* node ) {
	node->func->Accept( *this );
	IExp* func = dynamic_cast<IExp*>( current_node );
	const IExp* arg = node->args->head;

	IRTree::CExpList* newNode = nullptr;
	if ( node->args != nullptr ) {
		visit( node->args, newNode );
		IRTree::CExpList* ptr( newNode );
		current_node = doExp( new CCall( func, ptr ) );
	}
}

void CCanonizer::visit( IRTree::CExpList* node, IRTree::CExpList*& newNode ) 
{
	if ( node != nullptr )
	{
		if ( node->tail != nullptr )
		{
			visit( node->tail, newNode );
		}

		IRTree::CExpList* ptr( newNode );
		node->head->Accept( *this );
		IExp* arg = dynamic_cast<IExp*>( current_node );
		newNode = new IRTree::CExpList( doExp( arg ), ptr );
	} 
	else 
	{
		newNode = nullptr;
	}

}

void CCanonizer::visit( CEseq* node )  
{
	node->stm->Accept( *this );
	IStm* arg1 = dynamic_cast<IStm*>( current_node );
	node->exp->Accept( *this );

	IExp* arg2 = dynamic_cast<IExp*>( current_node );
	current_node = doExp( new CEseq( arg1, arg2 ) );

}

void CCanonizer::visit( IRTree::CMoveCall* node ) 
{
	//assert( 0 );
}

void CCanonizer::visit( IRTree::CExpCall* node ) 
{
	//assert( 0 );
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

IStm* seq( IStm* arg1, IStm* arg2 ) 
{
	if ( isNop( arg1 ) ) return arg2;
	if ( isNop( arg2 ) ) return arg1;
	return new CSeq( arg1, arg2 );
}

// DoStm
IStm* doStm( CSeq* stm ) 
{
	return seq( doStm( stm->left ), doStm( stm->right ) );
}

IStm* doStm( CMove* stm ) 
{
	CTemp* temp = dynamic_cast<CTemp*>( stm->dst );
	CCall* call = dynamic_cast<CCall*>( stm->src );
	CEseq* eseq = dynamic_cast<CEseq*>( stm->dst );

	if ( ( temp != 0 ) && ( call != 0 ) )
		return reorderStm( new CMoveCall( temp, call ) );
	if ( eseq != 0 )
		return doStm( new CSeq( eseq->stm, new CMove( eseq->exp, stm->src ) ) );
	return reorderStm( stm );
}

IStm* doStm( CExp* stm ) 
{
	CCall* call = dynamic_cast<CCall*>( stm->exp );

	if ( call != 0 )
		return reorderStm( new CExpCall( call ) );
	return reorderStm( stm );
}

IStm* doStm( IStm* stm ) 
{
	CSeq* seq = dynamic_cast<CSeq*>( stm );
	CMove* move = dynamic_cast<CMove*>( stm );
	CExp* exp = dynamic_cast<CExp*>( stm );

	if ( seq != 0 ) 
		return doStm( seq );
	if ( move != 0 ) 
		return doStm( move );
	if ( exp != 0 ) 
		return doStm( exp );
	return reorderStm( stm );
}

// DoExp
CEseq* doExp( IExp* exp ) 
{
	CEseq* eseq = dynamic_cast<CEseq*>( exp );
	if ( eseq != 0 )
		return doExp( eseq );
	return reorderExp( exp );
}


CEseq* doExp( CEseq* exp ) 
{
	if( exp != 0 ) {
		IStm* stms = doStm( exp->stm );
		CEseq* eseq = doExp( exp->exp );
		return new CEseq( seq( stms, eseq->stm ), eseq->exp );
	}
}

// Reorder
StmExpList* reorder( IRTree::CExpList* list ) {
	if ( list == nullptr ) 
	{
		return new StmExpList( new CExp( new CConst( 0 ) ), 0 );
	}
	const IExp* head = list->head;
	CCall* call = dynamic_cast<CCall*>( head );

	if ( call != 0 ) {
		const Temp::CTemp* t = new const Temp::CTemp( );
		IExp* eseq = new CEseq( new CMove( new CTemp( t ), head ), new CTemp( t ) );
		return reorder( new IRTree::CExpList( eseq, list->tail ) );
	}

	CEseq* eseq = doExp( head );
	StmExpList* stmtList = reorder( list->tail );
	if ( commute( stmtList->stm, eseq->exp ) ) {
		return new StmExpList( seq( eseq->stm, stmtList->stm ),
							    new ExpList( eseq->exp, stmtList->exps ) );
	} else {
		const Temp::CTemp* t = new const Temp::CTemp();
		return new StmExpList( seq( eseq->stm, seq( new CMove( new CTemp( t ), eseq->exp ), stmtList->stm ) ),
							    new IRTree::CExpList*( new CTemp( t ), stmtList->exps ) );
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
StmtList* linear( IStm* s, StmtList* l ) {
	CSeq* seq = dynamic_cast<CSeq*>( s );
	if ( seq != 0 )
		return linear( seq, l );
	return new StmtList( s, l );
}

StmtList* linear( CSeq* s, StmtList* l ) 
{
	return linear( s->left, linear( s->right, l ) );
}

StmtList* linearize( IStm* s ) 
{
	return linear( doStm( s ), nullptr );
}