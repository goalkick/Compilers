#include "Optimizer.h"
#include "BasicBlocks.h"
//#include "../TraceShedule.h"
#include "../Canonization.h"

namespace Canon {
	void Canonize( std::vector<INode*>& trees, std::vector<IStm*>& canonized_trees )
	{
		canonized_trees.clear();
		CCanonizer canonizer;
		for ( int i = 0; i < trees.size(); ++i ) {
			trees[i]->Accept( canonizer );

			INode* root = canonizer.current_node;
			IExp* exp = dynamic_cast<IExp*>( root );
			IStm* stm = dynamic_cast<IStm*>( root );
			IStm* result = 0;

			if ( exp != 0 ) 
			{
				IExp* res = doExp( exp );
				CEseq* eseq = dynamic_cast<CEseq*>( res );
				result = dynamic_cast<CSeq*>( eseq->stm );
			}

			if ( stm !=0 ) 
			{
				result = doStm( stm );
			}
			if ( result != 0 ) 
			{
				canonized_trees.push_back( result );
			}
		}
	}

	void Linearize(std::vector<IStm*>& trees, std::vector<std::shared_ptr<StmtList>>& result) {
		result.clear();
		for ( int i = 0; i < trees.size(); ++i ) {
			StmtList* listLin = linearize( trees[i] );
			result.push_back( std::make_shared<StmtList>( listLin ) );
		}
	}

	void Trace( std::vector<std::shared_ptr<StmtList>>& linearized, std::vector<std::shared_ptr<StmtList>>& result ) {
		result.clear();
		for ( int i = 0; i < linearized.size(); ++i ) {
			std::shared_ptr<StmtList> listLin = linearized[i];
			BasicBlocks* blocks = new BasicBlocks( listLin );
			TraceShedule* traceSh = new TraceShedule( blocks );
			std::shared_ptr<StmtList> traced = traceSh->stms;
			result.push_back(traced);
		}
	}

	void Print(std::ostream& out, std::ostream& gv, std::vector<INode*>& trees) {
		CIRPrinter ir_print_vis( out, gv );
		for ( int i = 0; i < trees.size(); ++i ) {
			out << "=================================" << std::endl;
			out << i << " tree" << std::endl;
			out << "=================================" << std::endl;
			trees[i]->Accept( &ir_print_vis );
		}
	}

	void Print( std::ostream& out, std::ostream& gv, std::vector<IStm*>& trees ) {
		CIRPrinter ir_print_vis( out, gv );
		for ( int i = 0; i < trees.size(); ++i ) {
			out << "=================================" << std::endl;
			out << i << " tree" << endl;
			out << "=================================" << std::endl;
			trees[i]->Accept( &ir_print_vis );
		}
	}

	void Print( std::ostream& out, std::ostream& gv, std::shared_ptr<StmtList> stmts) {

	}

	void Print( std::ostream& out, std::ostream& gv, std::vector<std::shared_ptr<StmtList>>& stmts ) {
		CIRPrinter ir_print_vis( out, gv );
		for ( int i = 0; i < stmts.size(); ++i ) {
			out << "=================================" << std::endl;
			out << i << " tree" << std::endl;
			out << "=================================" << std::endl;
			std::vector<IStm*> trees;
			stmts[i]->toVector( trees );
			for ( int j = 0; j < trees.size(); ++j ) {
				trees[j]->Accept( &ir_print_vis );
			}
		}
	}
}