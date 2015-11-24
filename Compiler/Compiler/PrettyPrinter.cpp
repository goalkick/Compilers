#include "PrettyPrinter.h"

void CPrettyPrinter::visit(const CProgram* rule) 
{
	if( rule->MainClass() != nullptr ) 
	{
		rule->MainClass()->Accept( this );
	}
	if( rule->ClassDeclList() != nullptr ) 
	{
		rule->ClassDeclList()->Accept( this );
	}
}

void CPrettyPrinter::visit(const CMainClass* rule)
{
	std::cout << "class " << rule->ClassName()->GetString() << " {" << std::endl;
	std::cout << "public static void main(String[] " << rule->Arg()->GetString() << ") {" << std::endl;
	if( rule->Statement() != nullptr ) 
	{
		rule->Statement()->Accept( this );
	}
	std::cout << std::endl << "}" << std::endl << "}" << std::endl;
}

void CPrettyPrinter::visit(const CClassDeclsList* rule)
{
	if( rule->ClassDecls() != nullptr ) 
	{
		rule->ClassDecls()->Accept( this );
	}
	if( rule->ClassDeclsList() != nullptr ) 
	{
		rule->ClassDeclsList()->Accept( this );
	}
}

void CPrettyPrinter::visit(const CClassDecls* rule)
{
	std::cout << "class " << rule->ClassName()->GetString();
	if( !rule->ParentName()->GetString().empty() )
	{
		std::cout << " extends " << rule->ParentName()->GetString();
	}
	std::cout << " {" << std::endl;
	if( rule->VarDeclList() != nullptr ) 
	{
		rule->VarDeclList()->Accept( this );
	}
	if( rule->MethodDeclList() != nullptr ) 
	{
		rule->MethodDeclList()->Accept( this );
	}
	std::cout << "}" << std::endl;
}

void CPrettyPrinter::visit(const CVarDeclList* rule)
{
	if( rule->VarDeclList() != nullptr ) 
	{
		rule->VarDeclList()->Accept( this );
	}
	if( rule->VarDecl() != nullptr ) 
	{
		rule->VarDecl()->Accept( this );
	}
}

void CPrettyPrinter::visit(const CVarDecl* rule)
{
	rule->Type()->Accept( this );
	std::cout << rule->Name()->GetString() << ";" << std::endl;
}

void CPrettyPrinter::visit(const CMethodDeclList* rule)
{
	if( rule->MethodDecl() != nullptr ) 
	{
		rule->MethodDecl()->Accept( this );
	}
	if( rule->MethodDeclList() != nullptr ) 
	{
		rule->MethodDeclList()->Accept( this );
	}
}

void CPrettyPrinter::visit(const CMethodDecl* rule)
{
	std::cout << "public ";
	if( rule->Type() != nullptr ) 
	{
		rule->Type()->Accept( this );
	}
	std::cout << rule->Name()->GetString() << "( ";
	if( rule->FormalList() != nullptr ) 
	{
		rule->FormalList()->Accept( this );
	}
	std::cout << " )" << std::endl << "{" << std::endl;
	if( rule->VarDeclList() != nullptr ) 
	{
		rule->VarDeclList()->Accept( this );
	}
	if( rule->StatementList() != nullptr ) 
	{
		rule->StatementList()->Accept( this );
	}
	std::cout << "return ";
	if( rule->Exp() != nullptr ) 
	{
		rule->Exp()->Accept( this );
	}
	std::cout << ";" << std::endl << "}" << std::endl;
}

void CPrettyPrinter::visit(const CFormalList* rule)
{
	if( rule->Type() != nullptr ) 
	{
		rule->Type()->Accept( this );
	}
	std::cout << " " << rule->Id()->GetString() << " ";
	if( rule->FormalRest() != nullptr ) 
	{
		rule->FormalRest()->Accept( this );
	}
}

void CPrettyPrinter::visit(const CFormalRest* rule)
{
	if( rule->FormalRest() != nullptr ) 
	{
		rule->FormalRest()->Accept( this );
	}
	std::cout << ", ";
	rule->Type()->Accept( this );
	std::cout << " " << rule->Id()->GetString();
}

void CPrettyPrinter::visit(const CType* rule)
{
	switch( rule->Type() ) 
	{
	case CType::EType::INT:
		std::cout << "int ";
		break;
	case CType::EType::INT_ARRAY:
		std::cout << "int[] ";
		break;
	case CType::EType::BOOL:
		std::cout << "bool ";
		break;
	}
}

void CPrettyPrinter::visit(const CUserType* rule)
{
	std::cout << rule->Type()->GetString() << std::endl;
}

void CPrettyPrinter::visit(const CStatementList* rule)
{
	if( rule->Statement() != nullptr ) 
	{
		rule->Statement()->Accept( this );
	}
	if( rule->StatementList() != nullptr ) 
	{
		rule->StatementList()->Accept( this );
	}
}

void CPrettyPrinter::visit(const CStatement* rule)
{
	std::cout << "{" << std::endl;
	if( rule->StatementList() != nullptr ) 
	{
		rule->StatementList()->Accept( this );
	}
	std::cout << std::endl << "}" << std::endl;
}

void CPrettyPrinter::visit(const CIfStatement* rule)
{
    std::cout << "if( ";
	if( rule->Condition() != nullptr )
	{
		rule->Condition()->Accept( this );
	}
	std::cout << " )" << std::endl;
	if( rule->IfTrueStatement() != nullptr )
	{
		rule->IfTrueStatement()->Accept( this );
	}
	if( rule->IfFalseStatement() != nullptr )
	{
		std::cout << std::endl << "else" << std::endl;
		rule->IfFalseStatement()->Accept( this );
	}
	std::cout << std::endl;
}

void CPrettyPrinter::visit(const CWhileStatement* rule)
{
    std::cout << "while( ";
	if( rule->Condition() != nullptr )
	{
		rule->Condition()->Accept( this );
	}
	std::cout << " )" << std::endl;
	if( rule->BodyCycle() != nullptr )
	{
		rule->BodyCycle()->Accept( this );
	}
	std::cout << std::endl;
}

void CPrettyPrinter::visit(const CPrintStatement* rule)
{
    std::cout << "System.out.println( ";
	if( rule->Expression() != nullptr )
	{
		rule->Expression()->Accept( this );
	}
	std::cout << " );" << std::endl;
}

void CPrettyPrinter::visit(const CAssignStatement* rule)
{
    std::cout << rule->LeftPart()->GetString() << " = ";
	if( rule->RightPart() != nullptr )
	{
		rule->RightPart()->Accept( this );
	}
	std::cout << ";" << std::endl;
}

void CPrettyPrinter::visit(const CArrayAssignStatement* rule)
{
    std::cout << rule->ArrayName()->GetString() << "[";
    if( rule->ElementNumber() != nullptr )
    {
		rule->ElementNumber()->Accept( this );
	}
	std::cout << "] = ";
	if( rule->RightPart() != nullptr )
	{
		rule->RightPart()->Accept( this );
	}
	std::cout << ";" << std::endl;
}

void CPrettyPrinter::visit(const CExpList* rule)
{
	if( rule->Exp() != nullptr )
	{
		rule->Exp()->Accept( this );
		return;
	}
	if( rule->ExpList() != nullptr )
	{
		rule->ExpList()->Accept( this );
	}
	if ( rule->ExpRest() != nullptr )
	{
		rule->ExpRest()->Accept( this );
	}
}

void CPrettyPrinter::visit(const CExpRest* rule)
{
    if( rule->Exp() != nullptr )
    {
		std::cout << ',';
		rule->Exp()->Accept( this );
	}
}

void CPrettyPrinter::visit(const CBinOpExpression* rule)
{
    if( rule->LeftExp() != nullptr )
    {
		rule->LeftExp()->Accept( this );
	}
	switch( rule->BinOp() )
	{
        case CBinOpExpression::EBinOp::AND:
            std::cout << " && ";
            break;
        case CBinOpExpression::EBinOp::LESS:
            std::cout << " < ";
            break;
        case CBinOpExpression::EBinOp::PLUS:
            std::cout << " + ";
            break;
        case CBinOpExpression::EBinOp::MINUS:
            std::cout << " - ";
            break;
		case CBinOpExpression::EBinOp::TIMES:
            std::cout << " * ";
            break;
        case CBinOpExpression::EBinOp::DIVIDE:
            std::cout << " / ";
            break;
	}
	if( rule->RightExp() != nullptr )
	{
		rule->RightExp()->Accept( this );
	}
}

void CPrettyPrinter::visit(const CIndexExpression* rule)
{
    if( rule->Exp() != nullptr )
    {
		rule->Exp()->Accept( this );
	}
	if( rule->IndexExp() != nullptr )
	{
		std::cout << "[";
		rule->IndexExp()->Accept( this );
		std::cout << "]";
	}
}

void CPrettyPrinter::visit(const CLenghtExpression* rule)
{
    if( rule->Exp() != nullptr )
    {
		rule->Exp()->Accept( this );
		std::cout << ".length";
	}
}

void CPrettyPrinter::visit(const CMethodExpression* rule)
{
	if( rule->Exp() != nullptr )
	{
		rule->Exp()->Accept( this );
	}
	std::cout << "." << rule->Id()->GetString() << "(";
	if( rule->IndexExp() != nullptr )
	{
		rule->IndexExp()->Accept( this );
	}
	std::cout << ")";
}

void CPrettyPrinter::visit(const CIntLiteralExpression* rule)
{
    std::cout << rule->Value()->GetString();
}

void CPrettyPrinter::visit(const CBoolLiteralExpression* rule)
{
    std::cout << rule->Value()->GetString();
}

void CPrettyPrinter::visit(const CIdentifierExpression* rule)
{
    std::cout << rule->Id()->GetString();
}

void CPrettyPrinter::visit(const CThisExpression* rule)
{
    std::cout << "this ";
}

void CPrettyPrinter::visit(const CNewIntArrayExpression* rule)
{
    if( rule->Exp() != nullptr ) 
	{
		std::cout << "new int [";
		rule->Exp()->Accept( this );
		std::cout << "]";
	}
}

void CPrettyPrinter::visit(const CNewExpression* rule)
{
    std::cout << "new " << rule->Id()->GetString() << "()";
}

void CPrettyPrinter::visit(const CUnaryOpExpression* rule)
{
	switch( rule->Op() )
    {
        case CUnaryOpExpression::UnaryOp::MINUS:
            std::cout << "-";
            break;
        case CUnaryOpExpression::UnaryOp::NOT:
            std::cout << "!";
            break;
	}
	if( rule->Exp() != nullptr )
	{
		rule->Exp()->Accept( this );
	}
}

void CPrettyPrinter::visit(const CBracesExpression* rule)
{
    if( rule->Exp() != nullptr )
    {
		std::cout << "( ";
		rule->Exp()->Accept( this );
		std::cout << " )";
	}
}

/*
void CPrettyPrinter::visit(const CExpressionList* rule)
{
    if( rule->Exp() != nullptr )
    {
		rule->Exp()->Accept( this );
	}
	if( rule->ExpList() != nullptr )
	{
		rule->ExpList()->Accept( this );
	}
}
*/