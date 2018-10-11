#include <iostream>
#include "GenStack.h"
#include "FileRead.h"
#include "Syntax.h"

using namespace std;

int main(int argc, char** argv)
{
  FileRead fr;
  string filename;
  Syntax s;

  //If User Does Not Provide A File Name In Argument
  if (argv[1] == NULL)
  {
    cout << "Please attach a file name when compiling." << endl;
  }

  //Check If File Is Readable and Exists
  if(fr.fileGood(argv[1]) == false)
  {
    cout << "Could not locate given file. Please try again." << endl;
    return 1;
  }
  fr.getFileContents(argv[1]);
  s.checkSyntax(argv[1]);

  return 0;
}
