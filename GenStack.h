#pragma once
#include <iostream>

using namespace std;

template <class T>
class GenStack
{
public:
  GenStack();
  GenStack(int maxSize);
  ~GenStack();

  int size();
  bool isEmpty();
  bool isFull();
  void push(T);
  T pop();
  T peek();

private:
  T* myStack;
  int top;
  int stackSize;

};

//Empty Constructor
template <class T>
GenStack<T>::GenStack()
{
}

//Overloaded Constructor
template <class T>
GenStack<T>::GenStack(int maxSize)
{
  myStack = new T[maxSize];
  top = -1;
  stackSize = maxSize;
}

//Destructor
template <class T>
GenStack<T>::~GenStack()
{
  while(!isEmpty())
  {
    pop();
  }

  delete[] myStack;
  cout << "Stack destroyed." << endl;
}

//Method To Push New Data Onto Stack
template <class T>
void GenStack<T>::push(T data)
{
  if (isFull())
  {
    cout << "Stack Cannot Hold Any More Data" << endl; //for now
  }
  else
  {
    myStack[++top] = data;
  }
}

//Method To Pop Top Element
template <class T>
T GenStack<T>::pop()
{
  if (isEmpty())
  {
    cout << "Stack Is Empty" << endl;
    exit(0);
  }

  return myStack[top--];
}

//Method To View Data At Top Of Stack
template <class T>
T GenStack<T>::peek()
{
  if (isEmpty())
  {
    cout << "Stack Is Empty" << endl;
    exit(0);
  }
  return myStack[top];
}

//Method To Return Size Of Stack
template <class T>
int GenStack<T>::size()
{
  return (top + 1);
}
//Method To Check If Stack Is Full
template <class T>
bool GenStack<T>::isFull()
{
  return (top == stackSize-1);
}

//Method To Check If Stack Is Empty
template <class T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}
