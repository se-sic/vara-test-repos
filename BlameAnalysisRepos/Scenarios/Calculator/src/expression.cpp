#include "expression.h"

#include "visitor.h"

void BinaryExpression::accept(ExpressionVisitor &visitor) const {
  visitor.visit(*this);
}

void Constant::accept(ExpressionVisitor &visitor) const {
  visitor.visit(*this);
}
