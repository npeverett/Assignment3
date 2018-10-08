#include <iostream>
#include "GenStack.h"
#include "Syntax.h"

using namespace std;

Syntax::Syntax()
{
}

Syntax::~Syntax()
{
  cout << "Syntax Destroyed" << endl;
}

int Syntax::checkSyntax()
{
  bool error = false;
  string fileContents = FileRead::getFileContents();
  for (char& ch : fileContents)
  {
      if (ch == RCBracket)
      {
        //Pop, if not LCBracket, error
        if (newStack.pop() != LCBracket)
        {
          error = true;
          cout << "Error Found: " << endl;
          return 0;
        }
      }
      if (ch == LCBracket)
      {
        //push LCBracket
        newStack.push(LCBracket);
      }
      if (ch == RSBracket)
      {
        //Pop, if not LSBracket, error
        if (newStack.pop() != LSBracket)
        {
          error = true;
          cout << "Error Found: " << endl;
          return 0;
        }
      }
      if (ch == LSBracket)
      {
        //push LSBracket
        newStack.push(LSBracket);
      }
      if (ch == RParenthesis)
      {
        //Pop, if not LParenthesis, error
        if (newStack.pop() != LParenthesis)
        {
          error = true;
          cout << "Error Found: " << endl;
          return 0;
        }
      }
      if (ch == LParenthesis)
      {
        //push LParenthesis
        newStack.push(LParenthesis);
      }
  }

  cout << "No Errors Found" << endl;
  return 1;
}
