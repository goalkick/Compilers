#pragma once
#include "IRTreeToDigraphConverter.h"
#include "IRTree.h"

using namespace std;

namespace IRTree {

void CIRTreeToDigraphConverter::visit( const CMove* node )
{
	node->dst->Accept( *this );
	string destString = lastNodeName;

	node->src->Accept( *this );
	string srcString = lastNodeName;

	nextNameWithId( "move" );

	treeRepresentation.AddEdge( lastNodeName, destString, "dest" );
	treeRepresentation.AddEdge( lastNodeName, srcString, "src" );
}

void CIRTreeToDigraphConverter::visit( const CExp* node )
{
	node->exp->Accept( *this );
	string prevString = lastNodeName;

	nextNameWithId( "exp" );
	treeRepresentation.AddEdge( lastNodeName, prevString );
}

void CIRTreeToDigraphConverter::visit( const CJump* node )
{
	nextNameWithId( "jump" );
	treeRepresentation.AddEdge( lastNodeName, node->label->Name(), "to_label" );
}

void CIRTreeToDigraphConverter::visit( const CCJump* node )
{
	node->right->Accept( *this );
	string rightString = lastNodeName;
	node->left->Accept( *this );
	string leftString = lastNodeName;

	nextNameWithId( "Cjump" );
	
	treeRepresentation.AddEdge( lastNodeName, rightString, "right" );
	treeRepresentation.AddEdge( lastNodeName, leftString, "left" );
	treeRepresentation.AddEdge( lastNodeName, node->iftrue->Name(), "iftrue" );
	treeRepresentation.AddEdge( lastNodeName, node->iffalse->Name(), "iffalse" );
}

void CIRTreeToDigraphConverter::visit( const CSeq* node )
{
	if( node->left != nullptr ) {
		node->left->Accept( *this );
		string leftString = lastNodeName;
		if( node->right != nullptr ) {
			node->right->Accept( *this );
			string rightString = lastNodeName;
			nextNameWithId( "seq" );
			treeRepresentation.AddEdge( lastNodeName, leftString, "left" );
			treeRepresentation.AddEdge( lastNodeName, rightString, "right" );
		} else {
			nextNameWithId( "seq" );
			treeRepresentation.AddEdge( lastNodeName, leftString, "left" );
		}
	} else {
		nextNameWithId( "seq" );
	}
}

void CIRTreeToDigraphConverter::visit( const CConst* node )
{
	nextNameWithId( string( "const_" ) + to_string( node->value ) );
}

void CIRTreeToDigraphConverter::visit( const CName* node )
{
	nextNameWithId( string( "name_" ) + node->label->Name() );
}

void CIRTreeToDigraphConverter::visit( const CTemp* node )
{
	nextNameWithId( string( "temp_" ) + node->temp.Name() );
}

void CIRTreeToDigraphConverter::visit( const CBinop* node )
{
	node->left->Accept( *this );
	string leftString = lastNodeName;
	node->right->Accept( *this );
	string rightString = lastNodeName;
	//graphviz отказывается работать с символами типа + *
	switch( node->binop ) {
		case B_Mul:
			nextNameWithId( "binop__Mul" );
			break;
		case B_Plus:
			nextNameWithId( "binop__Plus" );
			break;
		case B_Division:
			nextNameWithId( "binop__Division" );
			break;
		case B_Minus:
			nextNameWithId( "binop__Minus" );
			break;
		case B_Xor: 
			nextNameWithId( "binop__Xor" );
			break;
		case B_Less:
			nextNameWithId( "binop__Less" );
			break;
		case B_Greater:
			nextNameWithId( "binop__Greater" );
			break;
		case B_And:
			nextNameWithId( "binop__And" );
			break;
		default:
			//assert( false );
			break;
	}
	treeRepresentation.AddEdge( lastNodeName, rightString, "right" );
	treeRepresentation.AddEdge( lastNodeName, leftString, "left" );
}

void CIRTreeToDigraphConverter::visit( const CMem* node )
{
	node->exp->Accept( *this );
	string prevString = lastNodeName;
	nextNameWithId( "mem" );
	treeRepresentation.AddEdge( lastNodeName, prevString );
}

void CIRTreeToDigraphConverter::visit( const CCall* node )
{
	node->func->Accept( *this );
	string funcString = lastNodeName;
	node->args->Accept( *this );
	string argsString = lastNodeName;
	nextNameWithId( "call" );
	treeRepresentation.AddEdge( lastNodeName, funcString, "func" );
	treeRepresentation.AddEdge( lastNodeName, argsString, "args" );
}

void CIRTreeToDigraphConverter::visit( const CEseq* node )
{
	node->stm->Accept( *this );
	string stmString = lastNodeName;
	node->exp->Accept( *this );
	string expString = lastNodeName;
	nextNameWithId( "eseq" );
	treeRepresentation.AddEdge( lastNodeName, expString, "exp" );
	treeRepresentation.AddEdge( lastNodeName, stmString, "stm" );
}

void CIRTreeToDigraphConverter::visit( const CExpList* node )
{
	if( node->head != nullptr ) {
		node->head->Accept( *this );
		string headString = lastNodeName;
		if( node->tail != nullptr ) {
			node->tail->Accept( *this );
			string tailString = lastNodeName;
			nextNameWithId( "expList" );
			treeRepresentation.AddEdge( lastNodeName, headString, "head" );
			treeRepresentation.AddEdge( lastNodeName, tailString, "tail" );
		} else {
			nextNameWithId( "expList" );
			treeRepresentation.AddEdge( lastNodeName, headString, "head" );
		}
	} else {
		nextNameWithId( "expList" );
	}
	
}

void CIRTreeToDigraphConverter::visit( const CLabel* node )
{
	if (node->label->Name() == "tempLabel1") {
		int a = 1;
	}
	nextNameWithId( string( "label:" ) + node->label->Name() );
}

void CIRTreeToDigraphConverter::visit( const CMoveCall* node )
{
	// nothing
}

void CIRTreeToDigraphConverter::visit( const CExpCall* node )
{
	// nothing
}

void CIRTreeToDigraphConverter::nextNameWithId( std::string label )
{
	lastNodeName = label + string( "__id_" ) + to_string( minId++ );
	treeRepresentation.SetNodeLabel( lastNodeName, label );
}

void CIRTreeToDigraphConverter::LinkedVisit( const IStm* node )
{
	string fromName = lastNodeName;
	node->Accept( *this );
	string toName = lastNodeName;
	if( !fromName.empty() ) {
		treeRepresentation.AddEdge( fromName, toName, "next" );
	}
}

void CIRTreeToDigraphConverter::LinkedVisit( const IExp* node )
{
	string fromName = lastNodeName;
	node->Accept( *this );
	string toName = lastNodeName;
	if( !fromName.empty() ) {
		treeRepresentation.AddEdge( fromName, toName, "next" );
	}
}


}