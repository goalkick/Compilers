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
		virtual void Accept( IVisitor& Visitor ) const = 0;
		virtual ~INode() {}
	};

	// Exp stand for the computation of some value
	class IExp : public INode {
	public:
		virtual void Accept( IVisitor& ) const = 0;
		virtual CExpList* kids() = 0;
		virtual IExp* build( CExpList* kids ) = 0;
	};

	class IStm : public INode {
	public:
		virtual void Accept( IVisitor& ) const = 0;
		virtual CExpList* kids() = 0;
		virtual IStm* build( CExpList* kids ) = 0;
	};


	class CExpList {
	public:
		CExpList( IExp* _head, CExpList* _tail ) : head( _head ), tail( _tail ) {}

		void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	
		IExp* head;
		CExpList* tail;
	};


	class StmtList {
	public:
		StmtList( IStm* _head, StmtList* _tail ) : head( _head ), tail( _tail ) {}
		StmtList( std::vector<IStm*>& list )
		{
			if (list.empty()) 
			{
				tail = 0;
			} 
			else 
			{
				head = list[0];
				list.erase( list.begin() );
				tail = new StmtList( list );
			}
		}
		IStm* head;
		StmtList* tail;

		void toVector( std::vector<IStm*>& list )
		{
			if ( head != 0 )
				list.push_back(head);
			if ( tail !=0 )
				tail->toVector( list );
		}
	};

	class StmExpList {
	public:
		StmExpList( IStm* _stm, CExpList* _exps ) : stm( _stm ), exps( _exps ) {}
		IStm* stm;
		CExpList* exps;
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

		CExpList* kids() {
	 		return 0;
	 	}
	 
	 	IExp* build( CExpList* kids ) {
	 		return this;
	 	}

		const int value;
	};

	// The symbolic constant n 
	// (corresponding to an assembly language label)
	// ћетка дл€ переходов
	class CName : public IExp {
	public:
		CName( const Temp::CLabel* _label ) :
			label( _label )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		CExpList* kids() {
	 		return 0;
	 	}
	 
	 	IExp* build( CExpList* kids ) {
	 		return this;
	 	}

		const Temp::CLabel* label;
	};

	// Temporary t. 
	// A temporary in the abstract machine is similar to a register in a real machine. 
	// However, the abstract machine has an infinite number of temporaries.
	class CTemp : public IExp {
	public:
		CTemp( Temp::CTemp _temp ) :
			temp( _temp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		CExpList* kids() {
	 		return 0;
	 	}
	 
	 	IExp* build( CExpList* kids ) {
	 		return this;
	 	}

		Temp::CTemp temp;
	};

	// The application of binary operator o to operands left, right. 
	// Subexpression left is evaluated before right.
	class CBinop : public IExp {
	public:
		CBinop( BINOP_ENUM _binop, IExp* _left, IExp* _right ) :
			binop( _binop ),
			left( _left ),
			right( _right )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		CExpList* kids() {
	 		return new CExpList( left, new CExpList( right, 0 ) );
	 	}
	 
	 	IExp* build( CExpList* kids ) {
	 		return new CBinop( binop, kids->head, kids->tail->head );
	 	}

		const BINOP_ENUM binop;
		IExp* left;
		IExp* right;
	};

	// The contents of wordSize bytes of memory starting at address e 
	// (where wordSize is defined in the Frame module). 
	// Note that when CMem is used as the left child of a CMove, it means Уstore,Ф but anywhere else it means Уfetch.Ф
	class CMem : public IExp {
	public:
		CMem( IExp* _exp ) :
			exp( _exp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		CExpList* CMem::kids() 
		{
			return new CExpList( exp, nullptr );
		}

		IExp* CMem::build( CExpList* kids ) 
		{
			return new CMem( kids->head );
		}

		IExp* exp;
	};

	// A procedure call: the application of function f to argument list l.
	// The subexpression f is evaluated before the arguments which are evaluated left to right.
	class CCall : public IExp {
	public:
		CCall( IExp* _func, CExpList* _args ) :
			func( _func ),
			args( _args )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		CExpList* kids() {
	 		return new CExpList( func, args );
	 	}
	 
	 	IExp* build( CExpList* kids ) {
	 		return new CCall( kids->head, kids->tail );
	 	}

		IExp* func;
		CExpList* args;
	};

	// The statement s is evaluated for side effects, then e is evaluated for a result.
	// ¬ыполн€ет stm, затем вычисл€ет и возвращает exp
	class CEseq : public IExp {
	public:
		CEseq( IStm* _stm, IExp* _exp ) :
			stm( _stm ),
			exp( _exp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		CExpList* kids() {
	 		//assert(0);
	 		return 0;
	 	}
	 
	 	IExp* build( CExpList* kids ) {
	 		//assert(0);
	 		return 0;
	 	}

		IStm* stm;
		IExp* exp;
	};

	// CMove(CTemp t, e) Evaluate e and move it into temporary t.
	// CMove(CMem(e1), e2) Evaluate e1, yielding address a. Then evaluate e2, and
	// store the result into wordSize bytes of memory starting at a.
	// ¬ычисл€ем src и копируем результат в dst 
	// (dst - либо временна€ переменна€ CIRTemp, либо адрес CIRMem)
	class CMove : public IStm {
	public:
		CMove( IExp* _dst, IExp* _src ) :
			dst( _dst ),
			src( _src )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		CExpList* kids() {
	 		const CMem* memDst = dynamic_cast<const CMem*>( dst );
	 		if ( memDst != 0 ) 
			{
	 			return new CExpList( memDst->exp, new CExpList( src, nullptr ) );
	 		} 
			else 
			{
	 			return new CExpList( src, nullptr );
	 		}
	 	}
	 
	 	IStm* build( CExpList* kids ) 
		{
	 		const CMem* memDst = dynamic_cast<const CMem*>(dst);
	 		if ( memDst != 0 ) 
			{
	 			return new CMove( new CMem( kids->head ), kids->tail->head );
	 		} else 
			{
	 			return new CMove( dst, kids->head );
	 		}
	 	}

		IExp* dst;
		IExp* src;
	};

	// Evaluate e and discard the result.
	class CExp : public IStm {
	public:
		CExp( IExp* _exp ) :
			exp( _exp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		CExpList* kids()  
		{
	 		return new CExpList( exp, 0 );
	 	}
	 	
	 	IStm* build( CExpList* kids )  
		{
	 		return new CExp( kids->head );
	 	}
	
		IExp* exp;
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
	// ѕереходим в узел CIRLabel, которому соответствует метка
	class CJump : public IStm {
	public:
		CJump( IExp* _exp, Temp::CLabel* _label ) :
			exp( _exp ),
			label( _label )
		{}

		CJump( Temp::CLabel* _label ) :
			label( _label )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		CExpList* kids() 
		{
	 		return new CExpList( exp, 0 );
	 	}
	 	
	 	IStm* build( CExpList* kids ) 
		{
			return new CJump( kids->head, label );
	 	}

		IExp* exp;
		Temp::CLabel* label;
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
		CCJump( CJUMP_ENUM _relop, IExp* _left, IExp* _right, Temp::CLabel* _iftrue,
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
			
		CExpList* kids() {
	 		return new CExpList( left, new CExpList( right, 0 ) );
	 	}
	 	
	 	IStm* build( CExpList* kids ) {
	 		return new CCJump( relop, kids->head, kids->tail->head, iftrue, iffalse );
	 	}

		const CJUMP_ENUM relop;
		IExp* left;
		IExp* right;
		Temp::CLabel* iftrue;
		const Temp::CLabel* const iffalse;
	};

	/*
		The statement left followed by right.
		»сполн€ет сначала left, потом right
	*/
	class CSeq : public IStm {
	public:
		CSeq( IStm* _left, IStm* _right ) : 
			left( _left ), 
			right( _right )  
		{}

		CSeq( IStm* arg1, IStm* arg2, IStm* arg3 ) : 
			left( arg1 ), 
			right( new CSeq( arg2, arg3 ) ) 
		{}

		CSeq( IStm* arg1, IStm* arg2, IStm* arg3, IStm* arg4 ) : 
			left( arg1 ), right( new CSeq( arg2, arg3, arg4 ) ) {}

		CSeq( IStm* arg1, IStm* arg2, IStm* arg3, IStm* arg4, IStm* arg5 ) : 
			left( arg1 ), right( new CSeq( arg2, arg3, arg4, arg5 ) ) {}

		CSeq( IStm* arg1, IStm* arg2, IStm* arg3, IStm* arg4, 
				IStm* arg5, IStm* arg6 ) : 
			left( arg1 ), right( new CSeq( arg2, arg3, arg4, arg5, arg6 ) ) {}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	
		CExpList* kids() 
		{
	 		//assert(0);
	 		return 0;
	 	}
	 	
	 	IStm* build( CExpList* kids ) 
		{
	 		//assert(0);
	 		return 0;
	 	}

		IStm* left;
		IStm* right;
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

		CExpList* kids() 
		{
	 		return 0;
	 	}
	 	
	 	IStm* build( CExpList* kids ) 
		{
	 		return this;
	 	}

		const Temp::CLabel* label;
	};
		
	class CMoveCall: public IStm {
	public:
		CMoveCall( CTemp* _dst, CCall* _src) : dst( _dst ), src( _src ) {}
		CExpList* kids()
		{
			return src->kids();
		}

		IStm* build( CExpList* kids)
		{
			return new CMove( dst, src->build( kids ) );
		}

		CTemp* dst;
		CCall* src;

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	};

	class CExpCall: public IStm {
	public:
		CExpCall( CCall* _call) : call( _call ) {}
		CExpList* kids()
		{
			return call->kids();
		}

		IStm* build( CExpList* kids )
		{
			return new CExp( call->build( kids ) );
		}

		CCall* call;

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	};

}