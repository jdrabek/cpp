//
// Created by jadrab on 09.06.2017.
//

#include <cstring>
#include <iostream>
#include "Token.h"

Token::Token(char *c) {
  this->setOperatorType(c);
  if (this->type==TYPE_OPERATOR) {
    this->value = (int) c[0];
  } else {
    this->value = atoi(c);
  }
}

void Token::setOperatorType(char *c) {
  if (strcmp(c, "+")==0 || strcmp(c, "-")==0 || strcmp(c, "/")==0 || strcmp(c, "*")==0) {
    this->type = TYPE_OPERATOR;
  } else {
    this->type = TYPE_VALUE;
  }
}
int Token::getType() {
  return this->type;
}
int Token::getValue() {
  return this->value;
}
