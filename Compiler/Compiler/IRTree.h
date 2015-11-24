
class Label {};
namespace Temp {
	class Temp {};
	class LabelList {};
}

namespace IRTree {
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

	class CONST : public IExp {
	private:
		int value;
	};

	class NAME : public IExp {
	private:
		Label label;
	};

	class TEMP : public IExp {
	private:
		Temp::Temp temp;
	};

	class BINOP : public IExp {
	private:
		int binop;
		IExp left, rigth;
	};

	class MEM : public IExp {
	private:
		IExp exp;
	};

	class CALL : public IExp {
	private:
		IExp func;
		ExpList args;
	};

	class ESEQ : public IExp {
	private:
		IStm stm;
		IExp exp;
	};

	class IStm {

	};

	class MOVE : public IStm {
	private:
		IExp dst, src;
	};

	class EXP : public IStm {
	private:
		IExp exp;
	};

	class JUMP : public IStm {
	private:
		IExp exp;
		Temp::LabelList targets;
	};

	class CJUMP : public IStm {
	private:
		int relop;
		IExp left, right;
		Label iftrue, iffalse;
	};

	class SEQ : public IStm {
	private:
		IStm left, rigth;
	};

	class LABEL : public IStm {
	private:
		Label label;
	};

	class ExpList {
	private:
		IExp head;
		ExpList tail;
	};

	class StmList {
	private:
		IStm head;
		StmList tail;
	};
}