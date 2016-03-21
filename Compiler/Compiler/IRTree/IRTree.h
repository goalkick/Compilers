#pragma once

#include "Temp.h"
#include "visitor.h"

namespace IRTree {
	static enum BINOP_ENUM {
			PLUS, 
			MINUS, 
			MUL, 
			DIV, 
			AND, 
			OR, 
			LSHIFT, 
			RSHIFT,
			ARSHIFT, 
			XOR
		};

	static enum CJUMP_ENUM {
			EQUAL, NOT_EQUAL, // equal, not equal
			LESS, GREATER, // less, greater
			LESS_OR_EQUAL, GREATER_OR_EQUAL // less or equal, greater or equal
			//ULT, ULE, 
			//UGT, UGE
		};

	class IVisitor;
	// Exp stand for the computation of some value
	class IExp {
	public:
		virtual void Accept( IVisitor& ) const = 0;
	};

	// The integer constant
	class CONST : public IExp {
	public:
		CONST( int _value ) :
			value( _value )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	private:
		const int value;
	};

	// The symbolic constant n 
	// (corresponding to an assembly language label)
	class NAME : public IExp {
	public:
		NAME( const Temp::Label* _label ) :
			label( _label )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	private:
		const Temp::Label* label;
	};

	// Temporary t. 
	// A temporary in the abstract machine is similar to a register in a real machine. 
	// However, the abstract machine has an infinite number of temporaries.
	class TEMP : public IExp {
	public:
		TEMP( const Temp::Temp& _temp ) :
			temp( _temp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	private:
		Temp::Temp temp;
	};

	// The application of binary operator o to operands left, right. 
	// Subexpression left is evaluated before right.
	class BINOP : public IExp {
	public:
		BINOP( BINOP_ENUM _binop, const IExp* _left, const IExp* _right ) :
			binop( _binop ),
			left( _left ),
			right( _right )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	private:
		BINOP_ENUM binop;
		const IExp* left;
		const IExp* right;
	};

	// The contents of wordSize bytes of memory starting at address e 
	// (where wordSize is defined in the Frame module). 
	// Note that when MEM is used as the left child of a MOVE, it means Уstore,Ф but anywhere else it means Уfetch.Ф
	// ?????????? Accept????????
	class MEM : public IExp {
	public:
		MEM( const IExp* _exp ) :
			exp( _exp )
		{}

		virtual void Accept( IVisitor& printer ) const override
		{
			printer.visit( this );
		}
	private:
		const IExp* exp;
	};

	// A procedure call: the application of function f to argument list l.
	// The subexpression f is evaluated before the arguments which are evaluated left to right.
	class CALL : public IExp {
	public:
		CALL( const IExp* const _func, const ExpList& _args ) :
			func( _func ),
			args( _args )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	private:
		const IExp* func;
		ExpList args;
	};

	// The statement s is evaluated for side effects, then e is evaluated for a result.
	class ESEQ : public IExp {
	public:
		ESEQ( const IStm* _stm, const IExp* _exp ) :
			stm( _stm ),
			exp( _exp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

	private:
		const IStm* stm;
		const IExp* exp;
	};

	class IStm {

	};

	// MOVE(TEMP t, e) Evaluate e and move it into temporary t.
	// MOVE(MEM(e1), e2) Evaluate e1, yielding address a. Then evaluate e2, and
	// store the result into wordSize bytes of memory starting at a.
	class MOVE : public IStm {
	public:
		MOVE( const IExp* _dst, const IExp* _src ) :
			dst( _dst ),
			src( _src )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

	private:
		const IExp* dst;
		const IExp* src;
	};

	// Evaluate e and discard the result.
	class EXP : public IStm {
	public:
		EXP( const IExp* const _exp ) :
			exp( _exp )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

	private:
		const IExp* exp;
	};

	/*
		Transfer control (jump) to address e. The destination exp may be a
	literal label, as in NAME(lab), or it may be an address calculated by any other
	kind of expression. 
	
	For example, a C-language switch(i) statement may be implemented by doing arithmetic on i. 
	
	The list of labels targets specifies all the possible locations 
	that the expression exp can evaluate to; this is necessary for dataflow analysis later. 
	The common case of jumping to a known label l is written as JUMP(NAME l, new Temp::LabelList(l, null)), 
	but the JUMP class has an extra constructor so that this can be abbreviated as JUMP(l).
	*/
	// ѕереходим в узел CIRLabel, которому соответствует метка
	class JUMP : public IStm {
	public:
		JUMP( const Temp::LabelList* _label ) :
			label( _label )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	private:
		//IExp exp;
		const Temp::Label* label;
	};

	/*
		Evaluate left, right in that order, yielding values a, b. 
		Then compare a, b using the relational operator relop. 
		If the result is true, jump to iftrue; otherwise jump to iffalse.
		The relational operators are EQ and NE for integer equality and nonequality (signed or unsigned); 
		signed integer inequalities LT, GT, LE, GE; and unsigned integer inequalities ULT, ULE, UGT, UGE.
	*/
	class CJUMP : public IStm {
	public:
		CJUMP( CJUMP_ENUM _relop, const IExp* _left, const IExp* _right, const Temp::Label* _iftrue,
		const Temp::Label* _iffalse ) :
			relop( _relop ),
			left( _left ),
			right( _right ),
			iftrue( _iftrue ),
			iffalse( _iffalse )
		{
		}

		CJUMP( CJUMP_ENUM _relop, const IExp* const _left, const IExp* const _right, const Temp::Label* const _iftrue,
			const Temp::Label* const _iffalse ) :
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
				
	private:
		const CJUMP_ENUM relop;
		const IExp* left;
		const IExp* right;
		const Temp::Label* const iftrue;
		const Temp::Label* const iffalse;
	};

	/*
		The statement left followed by right.
	*/
	class SEQ : public IStm {
	public:
		SEQ( const IStm* _left, const IStm* _right ) : left( _left ), right( _right ) {}

		SEQ(const IStm* arg1, const IStm* arg2, const IStm* arg3 ) : left( arg1 ), right( new SEQ( arg2, arg3 ) ) {}

		SEQ(const IStm* arg1, const IStm* arg2, const IStm* arg3, const IStm* arg4 ) : 
			left( arg1 ), right( new SEQ( arg2, arg3, arg4 ) ) {}

		SEQ(const IStm* arg1, const IStm* arg2, const IStm* arg3, const IStm* arg4, const IStm* arg5 ) : 
			left( arg1 ), right( new SEQ( arg2, arg3, arg4, arg5 ) ) {}

		SEQ(const IStm* arg1, const IStm* arg2, const IStm* arg3, const IStm* arg4, 
				const IStm* arg5, const IStm* arg6) : 
			left(arg1), right( new SEQ( arg2, arg3, arg4, arg5, arg6 ) ) {}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	private:
		const IStm* left;
		const IStm* right;
	};

	/*
		Define the constant value of name label to be the current machine code address. 
		This is like a label definition in assembly language. 
		The value NAME(label) may be the target of jumps, calls, etc.
	*/
	class LABEL : public IStm {
	public: 
		LABEL( const Temp::Label* const _label ) :
			label( _label )
		{}

		virtual void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}

		const Temp::Label* const label;
	private:
		const Temp::Label* label;
	};
	
	
	class ExpList {
	public:
		ExpList( const IExp* _head, const ExpList* _tail ) :
			head( _head ), tail( _tail )
		{}

		void Accept( IVisitor& printer ) const
		{
			printer.visit( this );
		}
	private:
		const IExp* head;
		const ExpList* tail;
	};

	/*
	class StmList {
	private:
		IStm head;
		StmList* tail;
	};
	*/
}