#include <iostream>
#include "GenStack.h"
#include "FileRead.h"
#include "Syntax.h"

using namespace std;

int main()
{
  GenStack<int> newStack(2);
  FileRead fr;
  string filename;

  cout << "Welcome To Syntax Checker" << endl;
  cout << " " << endl;
  cout << "Enter the file name: ";

  cin >> filename;
  if(fr.fileGood(filename) == false)
  {
    cout << "Could not locate given file. Please try again." << endl;
    return 1;
  }
  cout << fr.getFileContents(filename) << endl;

  newStack.push(2);
  newStack.push(4);
  cout << newStack.peek() << endl;
  cout << newStack.isFull() << " " << newStack.size() << endl;
  newStack.push(8);
  cout<< newStack.isFull() << " " << newStack.size() << endl;

  return 0;
}
