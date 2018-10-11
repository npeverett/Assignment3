#include <iostream>
#include <string>
#include "GenStack.h"
#include "FileRead.h"
#include "Syntax.h"

using namespace std;

//Class Constructor
Syntax::Syntax()
{
}


//Destructor
Syntax::~Syntax()
{

}

//Method To Check Against Syntax With {}, [], () Characters
int Syntax::checkSyntax(string filename)
{
  //Default Gen Stack
  GenStack<int> newStack(8);

  //Getting The FileContents string
  FileRead fr;
  fr.getFileContents(filename);
  string fileContents = fr.getFileString();
  int EOFIndex = fr.getNumChars();

  bool error = false;
  int lineCount = 1;

  for (char& ch : fileContents)
  {
    //Check If Char Is }
    if (ch == RCBracket)
    {
      if (newStack.isEmpty())
      {
        error = true;
        cout << "Error found at line " << lineCount << " "
              << "character '{' expected." << endl;
        return 0;
      }

      //Pop, if not LCBracket, error
      else if (newStack.pop() != LCBracket)
      {
        error = true;
        cout << "Error found at line " << lineCount <<  "  "
              << "character '{' expected." << endl;
        return 0;
      }
    }

    //Check If Char Is {
    if (ch == LCBracket)
    {
      newStack.push(LCBracket);
    }

    //Check If Char Is ]
    if (ch == RSBracket)
    {
      //If stack is empty, no possibility of left bracket
      if (newStack.isEmpty())
      {
        error = true;
        cout << "Error found at line " << lineCount << " "
            << "character '[' expected." << endl;
        return 0;
      }

      //Pop, if not LSBracket, error
      if (newStack.pop() != LSBracket)
      {
        error = true;
        cout << "Error found at line " << lineCount <<  "  "
              << "character '[' expected." << endl;
        return 0;
      }
    }

    //Check If Char Is [
    if (ch == LSBracket)
    {
      newStack.push(LSBracket);
    }

    //Check If Char Is )
    if (ch == RParenthesis)
    {
      //If stack is empty, no possibility of left parenthesis
      if (newStack.isEmpty())
      {
      error = true;
        cout << "Error found at line " << lineCount << " "
              << "character '(' expected." << endl;
        return 0;
      }

      //Pop, if not LParenthesis, error
      if (newStack.pop() != LParenthesis)
      {
        error = true;
        cout << "Error found at line " << lineCount <<  "  "
              << "character '(' expected." << endl;
        return 0;
      }
    }

    //Check If Char Is (
    if (ch == LParenthesis)
    {
      newStack.push(LParenthesis);
    }

    if (ch == '\n')
    {
      lineCount++;
    }

    //If Chars Left Over At EOF
    if (ch == fileContents[EOFIndex - 1])
    {
      if (!newStack.isEmpty())
      {
        char temp = newStack.pop();
        if (temp == LCBracket)
        {
          cout << "Error found at end of file expected '}' character" << endl;
          return 0;
        }
        else if (temp == LSBracket)
        {
          cout << "Error found at end of file expected ']' character" << endl;
          return 0;
        }
        else if (temp == LParenthesis)
        {
          cout << "Error found at end of file expected ')' character" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No Errors Found" << endl;
  return 1;
}
