/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 11 "parser.y"
 
	#include "Classes.h" 
	#include "PrettyPrinter.h" 


/* Line 2058 of yacc.c  */
#line 52 "parser.tab.hpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER_LITERAL = 258,
     ID = 259,
     STRING = 260,
     INT = 261,
     IF = 262,
     CLASS = 263,
     PUBLIC = 264,
     BOOL = 265,
     EXTENDS = 266,
     RETURN = 267,
     WHILE = 268,
     VOID = 269,
     MAIN = 270,
     SYSTEM_OUT_PRINTLN = 271,
     LENGTH = 272,
     TRUE = 273,
     FALSE = 274,
     NEW = 275,
     ELSE = 276,
     THIS = 277,
     STATIC = 278
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 16 "parser.y"

	int ival;
	char sval[255];
	char* val;
	IProgram* programVal; 
	IMainClass* mainClassDeclarationVal; 
	IClassDeclsList* classDeclarationListVal; 
	IClassDecls* classDeclarationVal; 
	IVarDeclList* variableDeclarationListVal; 
	IVarDecl* variableDeclarationVal; 
	IMethodDecl* methodDeclarationVal; 
	IMethodDeclList* methodDeclarationListVal; 
	IFormalList* formalListVal; 
	IFormalRest* formalRestVal; 
	IStatement* statementVal; 
	IType* typeVal; 
	IExp* expressionVal; 
	IExpRest* expressionRest; 
	IExpList* expressionListVal; 
	IStatementList* statementListVal;


/* Line 2058 of yacc.c  */
#line 113 "parser.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (std::shared_ptr<CProgram>& root);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
