#include "expression.h"
#include "parser.h"
#include "visitor.h"

#include <iostream>

class Calculator {
private:
  RecursiveDescentParser parser;
  EvaluationVisitor evaluator;
  PrintVisitor printer;

public:
  Calculator() {
    parser = RecursiveDescentParser();
    evaluator = EvaluationVisitor();
    printer = PrintVisitor();
  }

  void repl() {
    std::string line;
    std::cout << "> ";
    while (std::getline(std::cin, line)) {
      auto expr = parser.parse(line);
      expr->accept(evaluator);
      expr->accept(printer);
      std::cout << " = " << evaluator.getResult() << std::endl;
      std::cout << "> ";
    }
  }
};

int main() {
  Calculator().repl();
}
