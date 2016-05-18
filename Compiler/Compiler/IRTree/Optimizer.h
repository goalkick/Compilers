#include "IRTree.h"
using namespace IRTree;

namespace Canon {
	void Canonize(vector<INode*>& trees, vector<IStm*>& canonized_trees);
	void Linearize(vector<IStm*>& trees, vector<shared_ptr<StmtList>>& result);
	void Trace(vector<shared_ptr<StmtList>>& stmts, vector<shared_ptr<StmtList>>& result);
	void Print(ostream& out, ostream& gv, vector<INode*>& trees);
	void Print(ostream& out, ostream& gv, vector<IStm*>& trees);
	void Print(ostream& out, ostream& gv, shared_ptr<StmtList> stmts);
	void Print(ostream& out, ostream& gv, vector<shared_ptr<StmtList>>& stmts);
}
