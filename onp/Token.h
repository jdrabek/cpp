//
// Created by jadrab on 09.06.2017.
//

#ifndef ONP_TOKEN_H
#define ONP_TOKEN_H

enum TokenType {
  TYPE_OPERATOR = 0,
  TYPE_VALUE = 1
};

class Token {
 private:
  int value;
  TokenType type;
 public:
  Token(char *c);
  void setOperatorType(char *c);
  int getValue();
  int getType();
};

#endif //ONP_TOKEN_H
