#pragma once

namespace IRTree {

class CMove;
class CExp;
class CJump;
class CCjump;
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


struct IVisitor {

	virtual void visit( const CMove* node ) = 0;
	virtual void visit( const CExp* node ) = 0;
	virtual void visit( const CJump* node ) = 0;
	virtual void visit( const CCjump* node ) = 0;
	virtual void visit( const CSeq* node ) = 0;
	virtual void visit( const CConst* node ) = 0;
	virtual void visit( const CName* node ) = 0;
	virtual void visit( const CTemp* node ) = 0;
	virtual void visit( const CBinop* node ) = 0;
	virtual void visit( const CMem* node ) = 0;
	virtual void visit( const CCall* node ) = 0;
	virtual void visit( const CEseq* node ) = 0;
	virtual void visit( const CExpList* node ) = 0;
	virtual void visit( const CLabel* node ) = 0;

};

} 