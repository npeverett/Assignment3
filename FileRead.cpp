#include <iostream>
#include <sstream>
#include <fstream>
#include "FileRead.h"

using namespace std;

//Class Constructor
FileRead::FileRead()
{

}

//Class Destructor
FileRead::~FileRead()
{

}

bool FileRead::fileGood(string filename)
{
  ifstream fin;
  fin.open(filename);
  if (fin.good())
  {
    return true;
  }

  fin.close();
  fin.clear();
  fin.seekg(0, fin.beg);

  return false;
}

string FileRead::getFileContents(string filename)
{
  stringstream strStream;
  string line = "";

  ifstream fin;
  fin.open(filename);

  string temp((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
  fileContents = temp;

  return fileContents;
}

string FileRead::getFileString()
{
  return fileContents;
}
