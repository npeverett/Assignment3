#include <iostream>
#include "GenStack.h"
#include "FileRead.h"
#include "Syntax.h"

using namespace std;

Syntax::Syntax()
{
}

Syntax::~Syntax()
{

}

int Syntax::checkSyntax(string filename)
{
  GenStack<int> newStack(8);

  FileRead fr;
  fr.getFileContents(filename);
  string fileContents = fr.getFileString();

  bool error = false;
  int lineCount = 1;

  for (char& ch : fileContents)
  {
      if (ch == RCBracket)
      {
        //Pop, if not LCBracket, error
        if (newStack.pop() != LCBracket)
        {
          error = true;
          cout << "Error found at line " << lineCount <<  "  "
               << "character '{' expected."       << endl;
          newStack.push(RCBracket);
          return 0;
        }
        newStack.push(RCBracket);
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
          cout << "Error found at line " << lineCount <<  "  "
               << "character '[' expected."       << endl;
          newStack.push(RSBracket);
          return 0;
        }
        newStack.push(RSBracket);
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
          cout << "Error found at line " << lineCount <<  "  "
               << "character '(' expected."       << endl;
          newStack.push(RParenthesis);
          return 0;
        }
        newStack.push(RParenthesis);
      }
      if (ch == LParenthesis)
      {
        //push LParenthesis
        newStack.push(LParenthesis);
      }
      if (ch == '\n')
      {
        lineCount++;
      }
  }

  /*if (!newStack.isEmpty()){
    if (newStack.pop())
  }
  */
  cout << "No Errors Found" << endl;
  return 1;
}
