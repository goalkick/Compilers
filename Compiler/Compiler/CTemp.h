#include <string>
#include "CSymbol.h"

namespace Temp {
	// Метка - точка перехода в коде
	class Label {
	public:
		// Создать метку с уникальным именем
		Label();
		// Создать метку с заданным именем
		explicit Label( const CSymbol& symbol );

		const std::string& Name() const { return name; }

	private:
	// Счётчик для создания уникальных идентификаторов
		static int nextUniqueId;
		std::string name;
	};
	// Временная переменная
	class Temp {
	public:
		// Новая переменная с уникальным именем
		Temp();
		// Новая переменная с заданным именем
		explicit Temp( const CSymbol& symbol );
		~Temp();

		const std::string& Name() const { return name; }

	private:
		// Счётчик для создания уникальных имён
		static int nextUniqueId;
		std::string name;
	};
} // namespace Temp
