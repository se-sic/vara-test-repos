#ifndef CALCULATOR_VISITOR_H
#define CALCULATOR_VISITOR_H

#include "expression.h"

class ExpressionVisitor {
public:
  virtual void visit(const BinaryExpression &exp) = 0;
  virtual void visit(const Constant &exp) = 0;
};

class EvaluationVisitor : public ExpressionVisitor {
  int result = 0;

public:
  void visit(const BinaryExpression &exp) override;
  void visit(const Constant &exp) override;

  int getResult() const { return result; };
};

class PrintVisitor : public ExpressionVisitor {
public:
  void visit(const BinaryExpression &exp) override;
  void visit(const Constant &exp) override;
};

#endif // CALCULATOR_VISITOR_H
