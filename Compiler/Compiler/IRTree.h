
class Label {};
namespace Temp {
	class Temp {};
	class LabelList {};
}

namespace IRTree {

	// Exp stand for the computation of some value
	class IExp {
	private:
		static enum BINOP {
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

		static enum CJUMP {
			EQ, NE, 
			LT, GT, 
			LE, GE, 
			ULT, ULE, 
			UGT, UGE
		};
	};

	// The integer constant
	class CONST : public IExp {
	private:
		int value;
	};

	// The symbolic constant n 
	// (corresponding to an assembly language label)
	class NAME : public IExp {
	private:
		Label label;
	};

	// Temporary t. 
	// A temporary in the abstract machine is similar to a register in a real machine. 
	// However, the abstract machine has an infinite number of temporaries.
	class TEMP : public IExp {
	private:
		Temp::Temp temp;
	};

	// The application of binary operator o to operands left, right. 
	// Subexpression left is evaluated before right.
	class BINOP : public IExp {
	private:
		int binop;
		IExp left, rigth;
	};

	// The contents of wordSize bytes of memory starting at address e 
	// (where wordSize is defined in the Frame module). 
	// Note that when MEM is used as the left child of a MOVE, it means “store,” but anywhere else it means “fetch.”
	class MEM : public IExp {
	private:
		IExp exp;
	};

	// A procedure call: the application of function f to argument list l.
	// The subexpression f is evaluated before the arguments which are evaluated left to right.
	class CALL : public IExp {
	private:
		IExp func;
		ExpList args;
	};

	// The statement s is evaluated for side effects, then e is evaluated for a result.
	class ESEQ : public IExp {
	private:
		IStm stm;
		IExp exp;
	};

	class IStm {

	};

	// MOVE(TEMP t, e) Evaluate e and move it into temporary t.
	// MOVE(MEM(e1), e2) Evaluate e1, yielding address a. Then evaluate e2, and
	// store the result into wordSize bytes of memory starting at a.
	class MOVE : public IStm {
	private:
		IExp dst, src;
	};

	// Evaluate e and discard the result.
	class EXP : public IStm {
	private:
		IExp exp;
	};

	/*
		Transfer control (jump) to address e. The destination exp may be a
	literal label, as in NAME(lab), or it may be an address calculated by any other
	kind of expression. 
	
	For example, a C-language switch(i) statement may be implemented by doing arithmetic on i. 
	
	The list of labels targets specifies all the possible locations 
	that the expression exp can evaluate to; this is necessary for dataflow analysis later. 
	The common case of jumping to a known label l is written as JUMP(NAME l, new LabelList(l, null)), 
	but the JUMP class has an extra constructor so that this can be abbreviated as JUMP(l).
	*/
	class JUMP : public IStm {
	private:
		IExp exp;
		Temp::LabelList targets;
	};

	/*
		Evaluate left, right in that order, yielding values a, b. 
		Then compare a, b using the relational operator relop. 
		If the result is true, jump to iftrue; otherwise jump to iffalse.
		The relational operators are EQ and NE for integer equality and nonequality (signed or unsigned); 
		signed integer inequalities LT, GT, LE, GE; and unsigned integer inequalities ULT, ULE, UGT, UGE.
	*/
	class CJUMP : public IStm {
	private:
		int relop;
		IExp left, right;
		Label iftrue, iffalse;
	};

	/*
		The statement left followed by right.
	*/
	class SEQ : public IStm {
	private:
		IStm left, rigth;
	};

	/*
		Define the constant value of name label to be the current machine code address. 
		This is like a label definition in assembly language. 
		The value NAME(label) may be the target of jumps, calls, etc.
	*/
	class LABEL : public IStm {
	private:
		Label label;
	};
	
	class ExpList {
	private:
		IExp head;
		ExpList* tail;
	};

	class StmList {
	private:
		IStm head;
		StmList* tail;
	};
}