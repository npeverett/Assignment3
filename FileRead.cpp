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

//Method To Check If File Exists/Can Be Read
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

//Method To Get File Contents To A String
string FileRead::getFileContents(string filename)
{
  stringstream strStream;
  string line = "";

  ifstream fin;
  fin.open(filename);

  string temp((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
  fileContents = temp;

  //Character used in Syntax to locate end of file
  fileContents += "/a";

  return fileContents;
}

//Getter For FileContent as String
string FileRead::getFileString()
{
  return fileContents;
}
