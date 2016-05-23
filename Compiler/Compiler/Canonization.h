#include "visitor.h"
#include "IRTree\IRTree.h"


using namespace IRTree;

class CCanonizer: public IRTree::IVisitor {
public:
	virtual void visit( const CMove* node );
	virtual void visit( const CExp* node );
	virtual void visit( const CJump* node );
    virtual void visit( const CCJump* node );
    virtual void visit( const CSeq* node );
    virtual void visit( const IRTree::CLabel* node );
    virtual void visit( const CConst* node );
    virtual void visit( const CName* node );
	virtual void visit( const IRTree::CTemp* node );
	virtual void visit( const CBinop* node );
	virtual void visit( const CMem* node );
    virtual void visit( const CCall* node );
    virtual void visit( const IRTree::CExpList* node, const IRTree::CExpList*& newNode );
	virtual void visit( const CEseq* node );
    virtual void visit( const CMoveCall* node );
  	virtual void visit( const CExpCall* node );

    IRTree::INode* current_node;
};

bool isNop( IRTree::IStm* stm );
bool commute( IRTree::IStm* stm, IRTree::IExp* exp );
IRTree::IStm* seq( IRTree::IStm* arg1, IRTree::IStm* arg2 );

IRTree::IStm* doStm( IRTree::IStm* stm );
IRTree::IStm* doStm( IRTree::CSeq* s );
IRTree::IStm* doStm( IRTree::CMove* s );
IRTree::IStm* doStm( IRTree::CExp* s );

IRTree::CEseq* doExp( IRTree::CEseq* exp );
IRTree::CEseq* doExp( IRTree::IExp* exp );

IRTree::StmExpList* reorder( IRTree::CExpList* list );
IRTree::CEseq* reorderExp( IRTree::IExp* exp );
IRTree::IStm* reorderStm( IRTree::IStm* stm );


IRTree::StmtList* linear( IRTree::IStm* s, IRTree::StmtList* l );
IRTree::StmtList* linear( IRTree::CSeq* s, IRTree::StmtList* l );
IRTree::StmtList* linearize( IRTree::IStm* s );