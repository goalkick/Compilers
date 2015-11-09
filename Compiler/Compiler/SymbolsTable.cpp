#include "SymbolsTable.h"

namespace SymbolsTable {

	bool CTable::AddClass( const std::string& name )
	{
		std::vector<std::shared_ptr<CClassInfo>>::iterator it = classes.begin();
		for( ; it != classes.end(); ++it ) 
		{
			if( (*it)->GetName() == name ) 
			{
				return false;
			}
		}
		classes.push_back( std::make_shared<CClassInfo>( name ) );
		return true;
	}

	CClassInfo* CTable::GetClass( const std::string& name )
	{
		std::vector<std::shared_ptr<CClassInfo>>::iterator it = classes.begin();
		for( ; it != classes.end(); ++it ) 
		{
			if( (*it)->GetName() == name ) 
			{
				return it->get();
			}
		}
		return nullptr;
	}

	bool CClassInfo::AddVar( const std::string& name, IType* type )
	{
		std::vector<std::shared_ptr<CVarInfo> >::iterator it = vars.begin();
		for( ; it != vars.end(); ++it ) 
		{
			if( (*it)->GetName() == name ) 
			{
				return false;
			}
		}
		vars.push_back( std::make_shared<CVarInfo>( name, type ) );
		return true;
	}

	bool CClassInfo::AddMethod( const std::string& name, IType* type )
	{
		std::vector<std::shared_ptr<CMethodInfo> >::iterator it = methods.begin();
		for( ; it != methods.end(); ++it ) 
		{
			if( (*it)->GetName() == name ) 
			{
				return false;
			}
		}
		methods.push_back( std::make_shared<CMethodInfo>( name, type ) );
		return true;
	}

	bool CClassInfo::SetBaseClass( CClassInfo* _baseClass )
	{
		if( baseClass != nullptr ) 
		{
			return false;
		}
		baseClass = std::shared_ptr<CClassInfo>( _baseClass );
		return true;
	}

	CMethodInfo* CClassInfo::GetMethod( const std::string& name ) const
	{
		std::vector<std::shared_ptr<CMethodInfo> >::const_iterator it = methods.begin();
		for( ; it != methods.end(); ++it ) 
		{
			if( (*it)->GetName() == name ) 
			{
				return it->get();
			}
		}
		return nullptr;
	}

	CVarInfo* CClassInfo::GetVar( const std::string name ) const
	{
		std::vector<std::shared_ptr<CVarInfo> >::const_iterator it = vars.begin();
		for( ; it != vars.end(); ++it )
		{
			if( (*it)->GetName() == name ) 
			{
				return it->get();
			}
		}
		return nullptr;
	}

	bool CMethodInfo::AddParamVar( const std::string& name, IType* type )
	{
		std::vector<std::shared_ptr<CVarInfo> >::const_iterator it = params.begin();
		for( ; it != params.end(); ++it )
		{
			if( (*it)->GetName() == name ) 
			{
				return false;
			}
		}
		params.push_back( std::make_shared<CVarInfo>( name, type ) );
		return true;
	}

	bool CMethodInfo::AddLocalVar( const std::string& name, IType* type )
	{
		std::vector<std::shared_ptr<CVarInfo> >::const_iterator it = localVars.begin();
		for( ; it != localVars.end(); ++it )
		{
			if( (*it)->GetName( ) == name ) 
			{
				return false;
			}
		}
		localVars.push_back( std::make_shared<CVarInfo>( name, type ) );
		return true;
	}

	CVarInfo* CMethodInfo::GetVar( const std::string& name ) const
	{
		std::vector<std::shared_ptr<CVarInfo> >::const_iterator it1 = localVars.begin();
		for( ; it1 != localVars.end(); ++it1 ) 
		{
			if( (*it1)->GetName() == name ) 
			{
				return it1->get();
			}
		}
		
		std::vector<std::shared_ptr<CVarInfo> >::const_iterator it2 = params.begin();
		for( ; it2 != params.end(); ++it2 ) 
		{
			if( (*it2)->GetName() == name ) 
			{
				return it2->get();
			}
		}
		return nullptr;
	}

}