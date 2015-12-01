#include "IRTree.h"

namespace Translate {

	class IExp {
		// Ex stands for an Уexpression,Ф represented as a Tree.Exp.
		virtual IRTree::IExp* unEx();
		// Nx stands for Уno result,Ф represented as a Tree statement.
		virtual IRTree::IStm* unNx();
		/*
			stands for Уconditional,Ф represented as a function from label-pair to statement.
		If you pass it a true destination and a false destination, it will make
		a statement that evaluates some conditionals and then jumps to one of the
		destinations (the statement will never Уfall throughФ).
		*/
		virtual IRTree::IStm* unCx(Temp::Label* t, Temp::Label* f);
		/*{
			Temp::Label* z = new Temp::Label();
			return	new IRTree::SEQ( new IRTree::CJUMP(IRTree::CJUMP.LT, a, b, z, f),
						new IRTree::SEQ(new IRTree::LABEL(z),
							new IRTree::CJUMP(IRTree::CJUMP.LT, c, d, t, f)));
		}*/
	};

	/*
		An ordinary expression that yields a single value.
	*/
	class Ex : public IExp {
	public:
		Ex(IRTree::IExp* e) { exp = e; }
		IRTree::IExp* unEx() { return exp; }
		IRTree::IStm* unNx() { return new IRTree::EXP( exp ); }
		IRTree::IStm* unCx( Temp::Label* t, Temp::Label* f ) {  }
	private:
		IRTree::IExp* exp;
	};

	/*
		An expression that yields no value.
	*/
	class Nx : public IExp {
	public:
		Nx(IRTree::IStm* s) {stm = s;}
		IRTree::IExp* unEx() { /* don't needed to be implemented*/ }
		IRTree::IStm* unNx() { return stm; }
		IRTree::IStm* unCx(Temp::Label t, Temp::Label f) { /* don't needed to be implemented*/ }
	private:
		IRTree::IStm* stm;
	};

	/*
		A УconditionalФ expression that jumps to either true or false.
	*/
	class Cx : public IExp {
	public:
		// To convert a УconditionalФ into a Уvalue expression,Ф
		/*
			Then we make a Tree.Stm that moves the value 1 into r, 
			and a conditional jump unCx(t, f ) that implements the conditional.
		If the condition is false, then 0 is moved into r; if it is true, then
		execution proceeds at t and the second move is skipped. The result of the
		whole thing is just the temporary r containing zero or one.
		*/
		IRTree::IExp* unEx() {
			Temp::Temp* r = new Temp::Temp();
			Temp::Label* t = new Temp::Label();
			Temp::Label* f = new Temp::Label();
			return new IRTree::ESEQ(
				new IRTree::SEQ(	
					new IRTree::MOVE( 
						new IRTree::TEMP( r ), 
						new IRTree::CONST( 1 ) 
					),
					new IRTree::SEQ( 
						unCx( t, f ),
						new IRTree::SEQ(
							new IRTree::LABEL( f ),
							new IRTree::SEQ(
								new IRTree::MOVE(
									new IRTree::TEMP( r ),
									new IRTree::CONST( 0 )
								),
								new IRTree::LABEL( t )
							)
						)
					)
				),
				new IRTree::TEMP(r)
			);
		}
		IRTree::IStm* unCx(Temp::Label* t, Temp::Label* f);
		IRTree::IStm* unNx() {  }
	};

	// объект-обЄрткa над промежуточным результатом, который будет возвращать 
	//	правильный тип из Tree в зависимости от ситуации:
	class ISubtreeWrapper {
	public:
		virtual ~ISubtreeWrapper() { }
		virtual const IRTree::IExp* ToExp() const = 0; // как Expr
		virtual const IRTree::IStm* ToStm() const = 0; // как Stm
		virtual const IRTree::IStm* ToConditional(
							 const Temp::Label* t, const Temp::Label* f) const = 0; // как if/jump
	};

	class CExpConverter : public ISubtreeWrapper {
	public:
		CExpConverter(const IRTree::IExp* e) : expr( e ) {}
		const IRTree::IExp* ToExp() const {return expr;}
		const IRTree::IStm* ToStm() const {  }
		const IRTree::IStm* ToConditional(const Temp::Label* t, const Temp::Label* f) const {  }
	private:
		const IRTree::IExp* expr;
	};

}