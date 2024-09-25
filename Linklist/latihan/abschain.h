#ifndef Chain_
#define Chain_
#include <iostream>
#include "cnode.h"
#include "abslist.h"
#include "xcept.h"

template <class T> class ChainIterator;

template<class T>
class Chain : public AbstractList<T> {
   friend  ChainIterator<T>;
   public:
      Chain() {first = 0;}
      ~Chain();
      bool IsEmpty() const {return first == 0;}
      int Length() const; 
      bool Find(int k, T& x) const; 
      int Search(const T& x) const; 
      AbstractList<T>& Delete(int k, T& x); 
      AbstractList<T>& Insert(int k, const T& x);
      void Output(std::ostream& out) const;
   private:
      ChainNode<T> *first;
};

template<class T>
Chain<T>::~Chain()
{
   ChainNode<T> *i;
   while (first) { i = first->link; delete first; first = i; }
}

template<class T>
int Chain<T>::Length() const
{
   ChainNode<T> *i = first;
   int len = 0;
   while (i) { len++; i = i->link; }
   return len;
}

template<class T>
bool Chain<T>::Find(int k, T& x) const
{
   if (k < 1) return false;
   ChainNode<T> *i = first;
   int j = 1;
   while (j < k && i) { j++; i = i->link; }
   if (i) { x = i->data; return true; }
   return false;
}

template<class T>
int Chain<T>::Search(const T& x) const
{
   ChainNode<T> *i = first;
   int j = 1;
   while (i && i->data != x) { j++; i = i->link; }
   if (i) return j;
   return 0;
}

template<class T>
AbstractList<T>& Chain<T>::Delete(int k, T& x)
{
   if (k < 1 || !first) throw OutOfBounds();
   ChainNode<T> *i = first;
   if (k > 1) {
     int j = 1;
     while (j < k - 1 && i) { j++; i = i->link; }
     if (!i || !i->link) throw OutOfBounds();
     ChainNode<T> *y = i->link;
     i->link = y->link; i = y;
   } else first = first->link;
   x = i->data; delete i;
   return *this;
}

template<class T>
AbstractList<T>& Chain<T>::Insert(int k, const T& x)
{
   if (k < 0) throw OutOfBounds();
   ChainNode<T> *i = first;
   int j = 1;
   while (j < k && i) { j++; i = i->link; }
   if (k > 0 && !i) throw OutOfBounds();
   ChainNode<T> *y;
   y = new ChainNode<T>;
   y->data = x;
   if (k) { y->link = i->link; i->link = y; }
   else { y->link = first; first = y; }
   return *this;
}

template<class T>
void Chain<T>::Output(std::ostream& out) const
{
   ChainNode<T> *i;
   for (i = first; i; i = i->link) out << i->data << "  ";
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x)
{
   x.Output(out); return out;
}

#endif
