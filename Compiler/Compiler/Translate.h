namespace Translate {

// ������-�����a ��� ������������� �����������, ������� ����� ���������� 
//	���������� ��� �� Tree � ����������� �� ��������:
class ISubtreeWrapper {
public:
	virtual ~ISubtreeWrapper() { }
	virtual const IRTree::IExp* ToExp() const = 0; // ��� Expr
	virtual const IRTree::IStm* ToStm() const = 0; // ��� Stm
	virtual const IRTree::IStm* ToConditional(
                         const Temp::CLabel* t, const Temp::CLabel* f) const = 0; // ��� if/jump
};

}