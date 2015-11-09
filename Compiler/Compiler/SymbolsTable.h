#include <vector>
#include <memory>
#include <string>

#include "classes.h"

namespace SymbolsTable {
	// связь имени и типа
	class CVarInfo {
	public:
		CVarInfo( const std::string& _name, IType* _type ) : name( _name ), type( _type ) {}

		std::string GetName() const { return name; }

		IType* GetType() const { return type; }

	private:
		std::string name;
		IType* type;
	};

	// описание метода (имя, формальные параметры и локальные переменные – CVarInfo)
	class CMethodInfo {
	public:
		CMethodInfo( const std::string& _name, IType* _type ) : name( _name ), returnType( new CVarInfo( "", _type ) ) {}

		bool AddParamVar( const std::string& name, IType* type );
		bool AddLocalVar( const std::string& name, IType* type );

		std::string GetName() const { return name; }
		CVarInfo* GetVar( const std::string& name ) const;
		CVarInfo* GetReturnType() const { return returnType.get(); }

	private:
		std::string name;
		std::shared_ptr<CVarInfo> returnType;
		std::vector<std::shared_ptr<CVarInfo>> params;
		std::vector<std::shared_ptr<CVarInfo>> localVars;
	};

	// описание класса (имя, поля CVarInfo, методы CMethodInfo)
	class CClassInfo {
	public:
		CClassInfo( const std::string& _name ) : name( _name ) {}

		bool AddVar( const std::string& name, IType* type );
		bool AddMethod( const std::string& name, IType* type );

		bool SetBaseClass( CClassInfo* baseClass );

		std::string GetName() const { return name; }
		CClassInfo* GetBaseClass() const { return baseClass.get(); }
		std::vector<std::shared_ptr<CVarInfo> > GerVars() const { return vars; }
		std::vector<std::shared_ptr<CMethodInfo> > GetMethods() const { return methods; }

		CMethodInfo* GetMethod( const std::string& name ) const;
		CVarInfo* GetVar( const std::string name ) const;

	private:
		std::string name;
		std::shared_ptr<CClassInfo> baseClass;
		std::vector<std::shared_ptr<CVarInfo> > vars;
		std::vector<std::shared_ptr<CMethodInfo> > methods;
	};

	// список известных классов (CClassInfo)
	class CTable {
	public:
		bool AddClass( const std::string& name );

		CClassInfo* GetClass( const std::string& name );

	private:
		std::vector<std::shared_ptr<CClassInfo> > classes;
	};
}