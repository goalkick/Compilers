#pragma once
#include "Digraph.h"
#include "IRTreeVisitor.h"
#include <string>

namespace IRTree {

class CMove;
class CExp;
class CJump;
class CCJump;
class CSeq;
class CConst;
class CName;
class CTemp;
class CBinop;
class CMem;
class CCall;
class CEseq;
class CExpList;
class CLabel;
class IStm;
class IExp;


class CIRTreeToDigraphConverter : public IVisitor {
public:
	CIRTreeToDigraphConverter( std::string treeFileName ) : treeRepresentation( treeFileName ), minId( 0 ) {}

	void LinkedVisit( const IStm* node );
	void LinkedVisit( const IExp* node );

	virtual void visit( const CMove* node ) override;
	virtual void visit( const CExp* node ) override;
	virtual void visit( const CJump* node ) override;
	virtual void visit( const CCJump* node ) override;
	virtual void visit( const CSeq* node ) override;
	virtual void visit( const CConst* node ) override;
	virtual void visit( const CName* node ) override;
	virtual void visit( const CTemp* node ) override;
	virtual void visit( const CBinop* node ) override;
	virtual void visit( const CMem* node ) override;
	virtual void visit( const CCall* node ) override;
	virtual void visit( const CEseq* node ) override;
	virtual void visit( const CExpList* node ) override;
	virtual void visit( const CLabel* node ) override;

	void Flush() { treeRepresentation.Flush(); }

private:

	int minId;

	std::string lastNodeName;

	CDigraph treeRepresentation;

	void nextNameWithId( std::string label );
};

}