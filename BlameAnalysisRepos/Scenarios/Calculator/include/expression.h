#ifndef CALCULATOR_EXPRESSION_H
#define CALCULATOR_EXPRESSION_H

#include <memory>
#include <string>

class ExpressionVisitor;

class Expression {
public:
  virtual ~Expression() = default;
  virtual void accept(ExpressionVisitor &visitor) const = 0;
};

class BinaryOperator {
public:
  std::string representation;

  explicit BinaryOperator(std::string representation)
      : representation(std::move(representation)) {}
  virtual ~BinaryOperator() = default;

  virtual const int operator()(const int lhs, const int rhs) const = 0;
};

class AddOperator : public BinaryOperator {
public:
  AddOperator() : BinaryOperator("+") {}

  const int operator()(const int lhs, const int rhs) const override {
    return lhs + rhs;
  };
};

class BinaryExpression : public Expression {
public:
  const std::unique_ptr<Expression> lhs;
  const std::unique_ptr<Expression> rhs;
  const std::unique_ptr<BinaryOperator> op;

  BinaryExpression(std::unique_ptr<Expression> lhs,
                   std::unique_ptr<Expression> rhs,
                   std::unique_ptr<BinaryOperator> op)
      : lhs(std::move(lhs)), rhs(std::move(rhs)), op(std::move(op)) {}

  void accept(ExpressionVisitor &visitor) const override;
};

class Constant : public Expression {
public:
  const int value;

  explicit Constant(int value) : value(value) {}

  void accept(ExpressionVisitor &visitor) const override;
};

#endif // CALCULATOR_EXPRESSION_H
