#pragma once
#include <iostream>


using namespace std;

class FileRead
{
public:
  FileRead();
  ~FileRead();

  bool fileGood(string filename);
  string getFileContents(string filename);

private:
  string fileContents;
};
