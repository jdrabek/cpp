#include <iostream>
#include <stack>
#include <cstring>
#include "token.h"

Token calc(Token op, Token a, Token b) {
  if (op.getType()!=TYPE_OPERATOR) {
    std::cout << "Wykonano calc na tokenie ktory nie jest operatorem!" << std::endl;
  }
  int val;

  switch (op.getValue()) {
    case '+':
      val = b.getValue() + a.getValue();
      break;
    case '-':
      val = b.getValue() - a.getValue();
      break;
    case '*':
      val = b.getValue()*a.getValue();
      break;
    case '/':
      val = b.getValue()/a.getValue();
      break;
    default:
      std::cout << "Nierozpoznany operator" << std::endl;
      val = 0;
      break;
  }
  char buffer[10];
  itoa(val, buffer, 10);

  return Token(buffer);
}

int main() {
  std::stack<Token> stack;
  char rpnExpression[] = "12 2 3 4 * 10 5 / + * +";

  char *pch = strtok(rpnExpression, " ");

  while (pch!=NULL) {
    Token t = Token(pch);
    if (t.getType()==TYPE_VALUE) {
      stack.push(t);
    } else {
      Token tokA = stack.top();
      stack.pop();
      Token tokB = stack.top();
      stack.pop();
      Token result = calc(t, tokA, tokB);
      stack.push(result);
    }
    pch = strtok(NULL, " ");
  }
  Token result = stack.top();
  std::cout << "Wynik: " << result.getValue() << std::endl;

  return 0;
}