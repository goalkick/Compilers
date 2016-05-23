#include "IRTree.h"
#include "../Canonization.h"
using namespace IRTree;

namespace Canon {
	void Canonize( std::vector<INode*>& trees, std::vector<IStm*>& canonized_trees );
	void Linearize( std::vector<IStm*>& trees, std::vector<std::shared_ptr<StmtList>>& result );
	void Trace( std::vector<std::shared_ptr<StmtList>>& stmts, std::vector<std::shared_ptr<StmtList>>& result );
	/*
	void Print( std::ostream& out, std::ostream& gv, std::vector<INode*>& trees );
	void Print( std::ostream& out, std::ostream& gv, std::vector<IStm*>& trees );
	void Print( std::ostream& out, std::ostream& gv, std::shared_ptr<StmtList> stmts );
	void Print( std::ostream& out, std::ostream& gv, std::vector<std::shared_ptr<StmtList>>& stmts );
	*/
}
