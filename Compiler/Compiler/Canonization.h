#include "visitor.h"
#include "IRTree\IRTree.h"


//using namespace IRTree;

class CCanonizer: public IRTree::IVisitor {
public:
	virtual void visit( IRTree::CMove* node );
	virtual void visit( IRTree::CExp* node );
	virtual void visit( IRTree::CJump* node );
    virtual void visit( IRTree::CCJump* node );
    virtual void visit( IRTree::CSeq* node );
    virtual void visit( IRTree::CLabel* node );
    virtual void visit( IRTree::CConst* node );
    virtual void visit( IRTree::CName* node );
	virtual void visit( IRTree::CTemp* node );
	virtual void visit( IRTree::CBinop* node );
	virtual void visit( IRTree::CMem* node );
    virtual void visit( IRTree::CCall* node );
    virtual void visit( IRTree::CExpList* node, IRTree::CExpList*& newNode );
	virtual void visit( IRTree::CEseq* node );
    //virtual void visit( IRTree::CMoveCall* node );
  	//virtual void visit( IRTree::CExpCall* node );

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