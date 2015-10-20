#pragma once
#include "grammar.h"

class IVisitor {
public:
int visit(const PlusExp* n);
int visit(const MinusExp* n);
int visit(const TimesExp* n);
int visit(const DivideExp* n);
int visit(const Identifier* n);
int visit(const IntegerLiteral* n);
};