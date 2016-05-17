#pragma once

#include "Temp.h"
#include "IRTreeVisitor.h"
#include <memory>
#include <string>
#include <vector>

namespace IRTree {

	static enum BINOP_ENUM {
			B_Plus, 
			B_Minus, 
			B_Mul, 
			B_Division, 
			B_Xor, 
			B_Less, 
			B_Greater,
			B_And,
			B_Count
		};

	static enum CJUMP_ENUM {
			CJ_Less,
			CJ_Greater,
			CJ_EqLess,
			CJ_EqGreater,
			CJ_Equal,
			CJ_NotEqual,

			CJ_Count
		};

	class IVisitor;

	class INode {
	public:
		virtual void Accept( IVisitor* Visitor ) = 0;
		virtual ~INode() {}
	};

	// Exp stand for the computation of some value
	class IExp : public INode {
	public:
		virtual void Accept( IVisitor& ) const = 0;
		virtual ExpList* kids() = 0;
		virtual IExp* build( ExpList* kids ) = 0;
	};

	class IStm : public INode {
	public:
		virtual void Accept( IVisitor& ) const = 0;
		virtual ExpList* kids() = 0;
		virtual IStm* build( ExpList* kids) = 0;
	};


	class CExpList {
	public:
		CExpList( const IExp* _head, const CExpList* _tail ) : head( _head ), tail( _tail ) {}

		void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	//private:
		const IExp* head;
		const CExpList* tail;
	};

	class ExpList {
	public:
		ExpList( IExp* _head, ExpList* _tail ) : head( _head ), tail( _tail ) {}
		IExp* head;
		ExpList* tail;
	};

	class StmtList {
	public:
		StmtList( IStm* _head, StmtList* _tail );
		StmtList( std::vector<IStm*>& list );
		IStm* head;
		StmtList* tail;

		void toVector( std::vector<IStm*>& list );
	};

	struct StmExpList {
		StmExpList( IStm* _stm, ExpList* _exps );
		IStm* stm;
		ExpList* exps;
	};

	// The integer constant
	class CConst : public IExp {
	public:
		CConst( int _value ) :
			value( _value )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const ExpList* kids() const {
	 		return 0;
	 	}
	 
	 	const IExp* build( const ExpList* kids ) const {
	 		return this;
	 	}

	//private:
		const int value;
	};

	// The symbolic constant n 
	// (corresponding to an assembly language label)
	// ����� ��� ���������
	class CName : public IExp {
	public:
		CName( const Temp::CLabel* _label ) :
			label( _label )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const ExpList* kids() const {
	 		return 0;
	 	}
	 
	 	const IExp* build(const ExpList* kids) const {
	 		return this;
	 	}

	//private:
		const Temp::CLabel* label;
	};

	// Temporary t. 
	// A temporary in the abstract machine is similar to a register in a real machine. 
	// However, the abstract machine has an infinite number of temporaries.
	class CTemp : public IExp {
	public:
		CTemp( const Temp::CTemp& _temp ) :
			temp( _temp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const ExpList* kids() const {
	 		return 0;
	 	}
	 
	 	const IExp* build(const ExpList* kids) const {
	 		return this;
	 	}

	//private:
		const Temp::CTemp temp;
	};

	// The application of binary operator o to operands left, right. 
	// Subexpression left is evaluated before right.
	class CBinop : public IExp {
	public:
		CBinop( BINOP_ENUM _binop, const IExp* _left, const IExp* _right ) :
			binop( _binop ),
			left( _left ),
			right( _right )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const ExpList* kids() const {
	 		return new ExpList(left, new ExpList(right, 0));
	 	}
	 
	 	const IExp* build(const ExpList* kids) const {
	 		return new BINOP(binop, kids->head, kids->tail->head);
	 	}

	//private:
		const BINOP_ENUM binop;
		const IExp* left;
		const IExp* right;
	};

	// The contents of wordSize bytes of memory starting at address e 
	// (where wordSize is defined in the Frame module). 
	// Note that when CMem is used as the left child of a CMove, it means �store,� but anywhere else it means �fetch.�
	class CMem : public IExp {
	public:
		CMem( const IExp* _exp ) :
			exp( _exp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		ExpList* CMem::kids() 
		{
			return new ExpList( exp, nullptr );
		}

		IExp* CMem::build( ExpList* kids ) {
			return new CMem( kids->head );
		}

	//private:
		const IExp* exp;
	};

	// A procedure call: the application of function f to argument list l.
	// The subexpression f is evaluated before the arguments which are evaluated left to right.
	class CCall : public IExp {
	public:
		CCall( const IExp* const _func, const CExpList& _args ) :
			func( _func ),
			args( _args )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const ExpList* kids() const {
	 		return new ExpList(func, args);
	 	}
	 
	 	const IExp* build(const ExpList* kids) const {
	 		return new CALL(kids->head, kids->tail);
	 	}

	//private:
		const IExp* func;
		const CExpList args;
	};

	// The statement s is evaluated for side effects, then e is evaluated for a result.
	// ��������� stm, ����� ��������� � ���������� exp
	class CEseq : public IExp {
	public:
		CEseq( const IStm* _stm, const IExp* _exp ) :
			stm( _stm ),
			exp( _exp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const ExpList* kids() const {
	 		//assert(0);
	 		return 0;
	 	}
	 
	 	const IExp* build(const ExpList* kids) const {
	 		//assert(0);
	 		return 0;
	 	}

	//private:
		const IStm* stm;
		const IExp* exp;
	};

	// CMove(CTemp t, e) Evaluate e and move it into temporary t.
	// CMove(CMem(e1), e2) Evaluate e1, yielding address a. Then evaluate e2, and
	// store the result into wordSize bytes of memory starting at a.
	// ��������� src � �������� ��������� � dst 
	// (dst - ���� ��������� ���������� CIRTemp, ���� ����� CIRMem)
	class CMove : public IStm {
	public:
		CMove( const IExp* _dst, const IExp* _src ) :
			dst( _dst ),
			src( _src )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const ExpList* kids() const {
	 		const CMem* memDst = dynamic_cast<const CMem*>( dst );
	 		if (memDst != 0) {
	 			return new ExpList( memDst->exp, new ExpList( src, nullptr ) );
	 		} else {
	 			return new ExpList( src, nullptr );
	 		}
	 	}
	 
	 	const IStm* build(const ExpList* kids) const {
	 		
	 		const CMem* memDst = dynamic_cast<const CMem*>(dst);
	 		if (memDst != 0) {
	 			return new MOVE(new CMem(kids->head), kids->tail->head);
	 		} else {
	 			return new MOVE(dst, kids->head);
	 		}
	 	}

	//private:
		const IExp* dst;
		const IExp* src;
	};

	// Evaluate e and discard the result.
	class CExp : public IStm {
	public:
		CExp( const IExp* _exp ) :
			exp( _exp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const ExpList* kids() const {
	 		return new ExpList( exp, 0 );
	 	}
	 	
	 	const IStm* build( const ExpList* kids ) const {
	 		return new EXP( kids->head );
	 	}
	//private:
		const IExp* exp;
	};

	/*
		Transfer control (jump) to address e. The destination exp may be a
	literal label, as in CName(lab), or it may be an address calculated by any other
	kind of expression. 
	
	For example, a C-language switch(i) statement may be implemented by doing arithmetic on i. 
	
	The list of labels targets specifies all the possible locations 
	that the expression exp can evaluate to; this is necessary for dataflow analysis later. 
	The common case of jumping to a known label l is written as JUMP(CName l, new Temp::CLabelList(l, null)), 
	but the JUMP class has an extra constructor so that this can be abbreviated as JUMP(l).
	*/
	// ��������� � ���� CIRLabel, �������� ������������� �����
	class CJump : public IStm {
	public:
		CJump( const Temp::CLabel* _label ) :
			label( _label )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const ExpList* kids() const {
	 		return new ExpList( exp, 0 );
	 	}
	 	
	 	const IStm* build( const ExpList* kids ) const {
	 		return new JUMP( kids->head, target );
	 	}

	//private:
		const Temp::CLabel* label;
	};

	/*
		Evaluate left, right in that order, yielding values a, b. 
		Then compare a, b using the relational operator relop. 
		If the result is true, jump to iftrue; otherwise jump to iffalse.
		The relational operators are EQ and NE for integer equality and nonequality (signed or unsigned); 
		signed integer inequalities LT, GT, LE, GE; and unsigned integer inequalities ULT, ULE, UGT, UGE.
	*/
	class CCJump : public IStm {
	public:
		CCJump( CJUMP_ENUM _relop, const IExp* _left, const IExp* _right, const Temp::CLabel* _iftrue,
		const Temp::CLabel* _iffalse ) :
			relop( _relop ),
			left( _left ),
			right( _right ),
			iftrue( _iftrue ),
			iffalse( _iffalse )
		{}
			
		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
			
		const ExpList* kids() const {
	 		return new ExpList( left, new ExpList( right, 0 ) );
	 	}
	 	
	 	const IStm* build( const ExpList* kids ) const {
	 		return new CJUMP( relop, kids->head, kids->tail->head, iftrue, iffalse );
	 	}

	//private:
		const CJUMP_ENUM relop;
		const IExp* left;
		const IExp* right;
		const Temp::CLabel* const iftrue;
		const Temp::CLabel* const iffalse;
	};

	/*
		The statement left followed by right.
		��������� ������� left, ����� right
	*/
	class CSeq : public IStm {
	public:
		CSeq( const IStm* _left, const IStm* _right ) : 
			left( _left ), 
			right( _right )  
		{}

		CSeq( const IStm* arg1, const IStm* arg2, const IStm* arg3 ) : 
			left( arg1 ), 
			right( new CSeq( arg2, arg3 ) ) 
		{}

		CSeq( const IStm* arg1, const IStm* arg2, const IStm* arg3, const IStm* arg4 ) : 
			left( arg1 ), right( new CSeq( arg2, arg3, arg4 ) ) {}

		CSeq( const IStm* arg1, const IStm* arg2, const IStm* arg3, const IStm* arg4, const IStm* arg5 ) : 
			left( arg1 ), right( new CSeq( arg2, arg3, arg4, arg5 ) ) {}

		CSeq( const IStm* arg1, const IStm* arg2, const IStm* arg3, const IStm* arg4, 
				const IStm* arg5, const IStm* arg6 ) : 
			left( arg1 ), right( new CSeq( arg2, arg3, arg4, arg5, arg6 ) ) {}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	
		const ExpList* kids() const {
	 		//assert(0);
	 		return 0;
	 	}
	 	
	 	const IStm* build( const ExpList* kids ) const {
	 		//assert(0);
	 		return 0;
	 	}

		//private:
		const IStm* left;
		const IStm* right;
	};

	/*
		Define the constant value of name label to be the current machine code address. 
		This is like a label definition in assembly language. 
		The value CName(label) may be the target of jumps, calls, etc.
	*/
	class CLabel : public IStm {
	public: 
		CLabel( const Temp::CLabel* const _label ) :
			label( _label )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const ExpList* kids() const {
	 		return 0;
	 	}
	 	
	 	const IStm* build(const ExpList* kids) const {
	 		return this;
	 	}

	//private:
		const Temp::CLabel* label;
	};
		
	
}