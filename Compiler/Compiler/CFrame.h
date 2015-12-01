#include "CSymbol.h"
#include <map>

namespace Frame {
	// Переменная фрейма
	class IAccess {
	public:
		virtual ~IAccess() {}
	};

	// Класс-контейнер с платформо-зависимой информацией о функции
	class CFrame {
	public:
		CFrame( const CSymbol* name, int formalsCount );
		// Доступ к формальным параметрам
		int FormalsCount() const { return formals.size(); }
		const IAccess* Formal( CSymbol ) const;

	private:
		std::map<CSymbol, IAccess> formals;
	};
}