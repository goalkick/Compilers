#ifndef BASICBLOCKS_HEADER
#define BASICBLOCKS_HEADER
#include "IRTree.h"

using namespace IRTree;
using namespace Temp;

namespace Canon {
class StmtListList {
public:
    StmtListList( std::shared_ptr<StmtList> _head, StmtListList* _tail ) : head( _head ), tail( _tail ) { }
	
    std::shared_ptr<StmtList> head;
    StmtListList* tail;
};

class BasicBlocks {
public:
	StmtListList* blocks;
	const Temp::CLabel* done;
	StmtListList* lastBlock;
	std::shared_ptr<StmtList> lastStm;

    BasicBlocks( std::shared_ptr<StmtList> stms ) : lastBlock(nullptr), blocks(nullptr), lastStm(nullptr) 
	{
		done = new Temp::CLabel();
		mkBlocks( stms );
	}

    void addStm( IStm* s )
	{
		lastStm->tail = new StmtList( s, nullptr );
		lastStm = std::make_shared<IRTree::StmtList>( lastStm->tail );
	}

    void doStms( std::shared_ptr<StmtList> l ) 
	{
		if ( l == nullptr ) {
			doStms( std::make_shared<StmtList>( new CJump( const_cast<Temp::CLabel*>( done ) ), nullptr ));
		} else {
			CJump* jump = dynamic_cast<CJump*>( l->head );
			CCJump* cjump = dynamic_cast<CCJump*>( l->head );
			if (( jump != 0 ) || ( cjump != 0 )) {
				addStm( l->head );
				mkBlocks( std::make_shared<StmtList>( l->tail ) );
			} else {
				IRTree::CLabel* label = dynamic_cast<IRTree::CLabel*>( l->head );
				if ( label != 0 ) {
					doStms( std::make_shared<StmtList>( new StmtList( new CJump( const_cast<Temp::CLabel*>( label->label ) ), l.get() )));
				} else {
					addStm( l->head );
					doStms( std::make_shared<StmtList>( l->tail ) );
				}
			}
		}
	}
    void mkBlocks( std::shared_ptr<StmtList> l );
};

}

#endif