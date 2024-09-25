#ifndef BookStack_
#define BookStack_

#include "xcept.h"

class Book {
public:
  // Default constructor added
  Book() : title(""), author(""), pageCount(0) {}
  Book(const string &title, const string &author, int pageCount);
  string GetTitle() const;
  string GetAuthor() const;
  int GetPageCount() const;

private:
  string title;
  string author;
  int pageCount;
};

template <class T> class BookStack {
public:
  BookStack(int MaxStackSize = 10);
  ~BookStack();
  bool IsEmpty() const;
  bool IsFull() const;
  T Top() const;
  BookStack<T> &Add(const T &book);
  BookStack<T> &Remove(T &book);

private:
  T *stack;
  int MaxTop;
  int top;
};

template <class T>
BookStack<T>::BookStack(int MaxStackSize)
    : stack(new T[MaxStackSize]), MaxTop(MaxStackSize - 1), top(-1) {}

template <class T> BookStack<T>::~BookStack() { delete[] stack; }
template <class T> bool BookStack<T>::IsEmpty() const { return top == -1; }
template <class T> bool BookStack<T>::IsFull() const { return top == MaxTop; }
template <class T> T BookStack<T>::Top() const {
  if (IsEmpty())
    throw OutOfBounds();
  return stack[top];
}

template <class T> BookStack<T> &BookStack<T>::Add(const T &book) {
  if (IsFull())
    throw NoMem();
  stack[++top] = book;
  return *this;
}

template <class T> BookStack<T> &BookStack<T>::Remove(T &book) {
  if (IsEmpty())
    throw OutOfBounds();
  book = stack[top--];
  return *this;
}

#endif