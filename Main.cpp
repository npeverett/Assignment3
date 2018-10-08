#include <iostream>
#include "GenStack.h"
#include "FileRead.h"

using namespace std;

int main()
{
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

  return 0;
}
