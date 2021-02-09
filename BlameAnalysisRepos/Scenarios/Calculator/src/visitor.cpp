#include "visitor.h"

#include <iostream>

void EvaluationVisitor::visit(const BinaryExpression &exp) {
  exp.lhs->accept(*this);
  int lhsValue = result;
  exp.rhs->accept(*this);
  int rhsValue = result;
  result = (*exp.op)(lhsValue, rhsValue);
}

void EvaluationVisitor::visit(const Constant &exp) { result = exp.value; }


void PrintVisitor::visit(const BinaryExpression &exp) {
  std::cout << "(";
  exp.lhs->accept(*this);
  std::cout << " " << exp.op->representation << " ";
  exp.rhs->accept(*this);
  std::cout << ")";
}

void PrintVisitor::visit(const Constant &exp) { std::cout << exp.value; }
