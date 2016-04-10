#pragma once

#include <vector>
#include <memory>
#include <string>

#include "classes.h"

namespace SymbolsTable {
	class CVarInfo {
	public:
		CVarInfo( const std::string& _name, const IType* _type ) : name( _name ), type( _type ) {}

		std::string GetName() const { return name; }

		const IType* GetType() const { return type; }

	private:
		std::string name;
		const IType* type;
	};

	class CMethodInfo {
	public:
		CMethodInfo( const std::string& _name, const IType* _type )  {
			name = _name;
			if (_type != NULL) {
				returnType = std::make_shared<CVarInfo>( _type->StringType(), _type );
			}
			else {
				returnType = std::make_shared<CVarInfo>( "", _type );
			}
		}

		bool AddParamVar( const std::string& name, const IType* type );
		bool AddLocalVar( const std::string& name, const IType* type );

		std::string GetName() const { return name; }
		CVarInfo* GetVar( const std::string& name ) const;
		CVarInfo* GetReturnType() const { return returnType.get(); }
		std::vector<std::shared_ptr<CVarInfo>> GetParams() const { return params; }
		std::vector<std::shared_ptr<CVarInfo>> GetLocals() const { return localVars; }
		const CVarInfo* CMethodInfo::GetParamByNumber( int number ) const;
		
	private:
		std::string name;
		std::shared_ptr<CVarInfo> returnType;
		std::vector<std::shared_ptr<CVarInfo>> params;
		std::vector<std::shared_ptr<CVarInfo>> localVars;
	};

	class CClassInfo {
	public:
		CClassInfo( const std::string& _name ) : name( _name ) {}

		bool AddVar( const std::string& name, const IType* type );
		bool AddMethod( const std::string& name, const IType* type );

		bool SetBaseClass( CClassInfo* baseClass );

		std::string GetName() const { return name; }
		CClassInfo* GetBaseClass() const { return baseClass.get(); }
		std::vector<std::shared_ptr<CVarInfo> > GetVars() const { return vars; }
		std::vector<std::shared_ptr<CMethodInfo> > GetMethods() const { return methods; }

		CMethodInfo* GetMethod( const std::string& name ) const;
		CVarInfo* GetVar( const std::string name ) const;

	private:
		std::string name;
		std::shared_ptr<CClassInfo> baseClass;
		std::vector<std::shared_ptr<CVarInfo> > vars;
		std::vector<std::shared_ptr<CMethodInfo> > methods;
	};

	class CTable {
	public:
		bool AddClass( const std::string& name );

		CClassInfo* GetClass( const std::string& name ) const;

		std::vector<std::shared_ptr<CClassInfo> > classes;
	};
}