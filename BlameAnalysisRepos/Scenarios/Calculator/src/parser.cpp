#include "parser.h"

#include <algorithm>
#include <iostream>
#include <utility>

struct Symbol {
  std::string Name;
  std::string Representation;

  Symbol(std::string Name, std::string Representation)
      : Name(std::move(Name)), Representation(std::move(Representation)) {}
};

Symbol OPENING_PARENTHESIS("OPENING_PARENTHESIS", "(");
Symbol CLOSING_PARENTHESIS("CLOSING_PARENTHESIS", ")");
Symbol PLUS("PLUS", "+");
Symbol MINUS("MINUS", "-");
Symbol TIMES("TIMES", "*");
Symbol DIV("DIV", "/");
Symbol ZERO("ZERO", "0");
Symbol DIGIT_NO_ZERO("DIGIT_NO_ZERO", "[1,2,3,4,5,6,7,8,9]");
Symbol UNKNOWN("UNKNOWN", "UNKNOWN");
Symbol EOS("EOS", "EOS");

class Token {
public:
  Symbol *symbol;
  char value;

  Token(Symbol *symbol, char value) : symbol(symbol), value(value) {}
};

void nextSymbol(const char **currentSymbol) {
  do {
    ++(*currentSymbol);
  } while (**currentSymbol == ' ');
}

Token getToken(const char *currentSymbol) {
  switch (*currentSymbol) {
  case '\0':
    return Token(&EOS, '\0');
  case '(':
    return Token(&OPENING_PARENTHESIS, '(');
  case ')':
    return Token(&CLOSING_PARENTHESIS, ')');
  case '+':
    return Token(&PLUS, '+');
  case '-':
    return Token(&MINUS, '-');
  case '*':
    return Token(&TIMES, '*');
  case '/':
    return Token(&DIV, '/');
  case '0':
    return Token(&ZERO, '0');
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    return Token(&DIGIT_NO_ZERO, *currentSymbol);
  default:
    return Token(&UNKNOWN, *currentSymbol);
  }
}

bool isExpected(std::initializer_list<Symbol *> expectedSymbols,
                const char *currentSymbol) {
  return std::find(expectedSymbols.begin(), expectedSymbols.end(),
                   getToken(currentSymbol).symbol) != expectedSymbols.end();
}

bool expect(std::initializer_list<Symbol *> expectedSymbols,
            const char *currentSymbol) {
  if (!isExpected(expectedSymbols, currentSymbol)) {
    std::cout << "Syntax error: expected ";
    for (auto symbol : expectedSymbols) {
      std::cout << symbol->Representation << " ";
    }
    std::cout << "but got " << getToken(currentSymbol).symbol->Representation
              << "\n";
    return false;
  }
  return true;
}

std::unique_ptr<Expression> parseExpression(const char **currentSymbol);

std::unique_ptr<Expression> parseConstant(const char **currentSymbol) {
  std::string constant = "";
  while (isExpected({&ZERO, &DIGIT_NO_ZERO}, *currentSymbol)) {
    constant.push_back(getToken(*currentSymbol).value);
    nextSymbol(currentSymbol);
  }
  return std::make_unique<Constant>(Constant(std::stoi(constant)));
}

std::unique_ptr<BinaryOperator> parseOperator(const char **currentSymbol) {
  if (!expect({&PLUS}, *currentSymbol)) {
    exit(-1);
  }
  if (getToken(*currentSymbol).symbol == &PLUS) {
    nextSymbol(currentSymbol);
    return std::make_unique<AddOperator>();
  } else {
    exit(-1); // cannot happen. See check above
  }
}

std::unique_ptr<Expression> parseBinExp(const char **currentSymbol) {
  if (!expect({&OPENING_PARENTHESIS}, *currentSymbol)) {
    exit(-1);
  }
  nextSymbol(currentSymbol); // advance over opening parenthesis
  auto lhs = parseExpression(currentSymbol);
  auto op = parseOperator(currentSymbol);
  auto rhs = parseExpression(currentSymbol);
  if (!expect({&CLOSING_PARENTHESIS}, *currentSymbol)) {
    exit(-1);
  }
  nextSymbol(currentSymbol); // advance over closing parenthesis
  return std::make_unique<BinaryExpression>(std::move(lhs), std::move(rhs),
                                            std::move(op));
}

std::unique_ptr<Expression> parseExpression(const char **currentSymbol) {
  expect({&OPENING_PARENTHESIS, &DIGIT_NO_ZERO}, *currentSymbol);
  Token token = getToken(*currentSymbol);
  if (token.symbol == &OPENING_PARENTHESIS) {
    return parseBinExp(currentSymbol);
  } else if (token.symbol == &DIGIT_NO_ZERO) {
    return parseConstant(currentSymbol);
  }
  exit(-1);
}

std::unique_ptr<Expression>
RecursiveDescentParser::parse(std::string expressionString) {
  const char *symbols = expressionString.c_str();
  const char **symbol = &symbols;
  auto expression = parseExpression(symbol);
  if (!expect({&EOS}, *symbol)) {
    exit(-1);
  }
  return expression;
}

