#pragma once
#include <iostream>
#include "GenStack.h"

using namespace std;

class Syntax
{
public:
  Syntax();
  ~Syntax();
  int checkSyntax();

private:
  //GenStack<char> newStack(8);
  const char LCBracket = '{';
  const char RCBracket = '}';
  const char LSBracket = '[';
  const char RSBracket = ']';
  const char LParenthesis = '(';
  const char RParenthesis = ')';
};
