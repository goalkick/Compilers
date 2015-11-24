namespace Translate {

// объект-обёрткa над промежуточным результатом, который будет возвращать 
//	правильный тип из Tree в зависимости от ситуации:
class ISubtreeWrapper {
public:
	virtual ~ISubtreeWrapper() { }
	virtual const IRTree::IExp* ToExp() const = 0; // как Expr
	virtual const IRTree::IStm* ToStm() const = 0; // как Stm
	virtual const IRTree::IStm* ToConditional(
                         const Temp::CLabel* t, const Temp::CLabel* f) const = 0; // как if/jump
};

}