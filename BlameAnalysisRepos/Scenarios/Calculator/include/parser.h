#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H

#include "expression.h"

#include <memory>

/*
 * Grammar:
 *
 * <exp> := <binExp> | <constant> | epsilon
 *
 * <binExp> := '(' <exp> <op> <exp> ')'
 * <op> = '+' | '*'
 *
 * <constant> := <number>
 * <number> := '1'..'9'<digit>
 * <digit> := '0'..'9' | epsilon
 */

class ExpressionParser {
public:
  virtual std::unique_ptr<Expression> parse(std::string expressionString) = 0;
};

class RecursiveDescentParser : public ExpressionParser {
public:
  std::unique_ptr<Expression>
  parse(std::string expressionString) override;
};

#endif // CALCULATOR_PARSER_H
