#include "BasicBlocks.h"
#include <unordered_map>

using namespace std;

namespace Canon {

class TraceShedule {
public:
	shared_ptr<StmtList> stms;
	BasicBlocks* blocks;
	std::unordered_map<const Temp::CLabel*, shared_ptr<StmtList>> table;

	TraceShedule( BasicBlocks* b )
	{
		blocks = b;
		for (StmtListList* l = b->blocks; l != nullptr; l = l->tail) {
			if (static_cast<IRTree::CLabel*>(l->head->head)->label == 0) {
				// cerr << "BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa" << endl;
				exit(1);
			}
			table[static_cast<IRTree::CLabel*>(l->head->head)->label] = l->head;
			//cout << "1" << endl;
		}
		stms = getNext();
		//table = nullptr;
	}

	shared_ptr<StmtList> getLast( shared_ptr<StmtList> block );
	
	void trace( shared_ptr<StmtList> l )
	{
		for (;;) {
			IRTree::CLabel* label = static_cast<IRTree::CLabel*>( l->head );
			table.erase(label->label);
			shared_ptr<StmtList> last = getLast(l);
			IStm* s = last->tail->head;
			CJump* jump = dynamic_cast<CJump*>( s );
			if ( jump != 0 ) 
			{
				std::unordered_map<const Temp::CLabel*, shared_ptr<StmtList>>::iterator it = table.find( jump->label );
				if ( it != table.end() ) 
				{
					last->tail = it->second.get();
					l = it->second;
				} 
				else 
				{
					last->tail->tail = getNext().get();
					return;
				}

			} 
			else 
			{
				CCJump* cjump = dynamic_cast<CCJump*>(s);
				if (cjump != 0) {
					std::unordered_map<const Temp::CLabel*, shared_ptr<StmtList>>::iterator itTrue = table.find(cjump->iftrue);
					std::unordered_map<const Temp::CLabel*, shared_ptr<StmtList>>::iterator itFalse = table.find(cjump->iffalse);
					if ( itFalse != table.end() ) {
						//cout << last->tail->tail << endl;
						last->tail->tail = itFalse->second.get();
						//cout << last->tail->tail << endl;
						l = itFalse->second;
						//cout << "ohoho" << endl;
					} else if ( itTrue != table.end() ) {
						last->tail->head = new CCJump(cjump->relop, const_cast<IRTree::IExp*>( cjump->left ), const_cast<IRTree::IExp*>( cjump->right ),
							const_cast<Temp::CLabel*>( cjump->iffalse ), const_cast<Temp::CLabel*>( cjump->iftrue ) );
						last->tail->tail = itTrue->second.get();
						l = itTrue->second;
					} else {
						Temp::CLabel* ff = new Temp::CLabel();
						last->tail->head = new CCJump( cjump->relop, const_cast<IRTree::IExp*>( cjump->left ), const_cast<IRTree::IExp*>( cjump->right ), 
							const_cast<Temp::CLabel*>( cjump->iffalse ), const_cast<Temp::CLabel*>( cjump->iftrue ) );
						last->tail->tail = new StmtList( new IRTree::CLabel(ff),
							new StmtList( new CJump( const_cast<Temp::CLabel*>( cjump->iffalse ) ), getNext().get()));
						return;
					}
				} else {
					//std::cerr << "BOOOOOOOOOOOM" << std::endl;
				}
			}
		}
	}

	shared_ptr<StmtList> getNext()
	{
		if (blocks->blocks == nullptr) {
			return make_shared<StmtList>( new IRTree::CLabel( blocks->done ), nullptr );
		} else {
			shared_ptr<StmtList> s = blocks->blocks->head;
			IRTree::CLabel* label = static_cast<IRTree::CLabel*>( s->head );
			std::unordered_map<const Temp::CLabel*, shared_ptr<StmtList>>::iterator itTrue = table.find( label->label );
			if (itTrue != table.end()) {
				trace(s);
				return s;
			} else {
				blocks->blocks = blocks->blocks->tail;
				return getNext();
			}
		}
	}
};

}