#ifndef LinearList_
#define LinearList_
#include <cstdlib>
#include <iostream>
#include "abslist.h"
#include "xcept.h"

template<class T>
class LinearList : public AbstractList<T> {
   public:
      LinearList(int MaxListSize = 10);
      ~LinearList() { delete [] element; }
      bool IsEmpty() const { return length == 0; }
      int Length() const { return length; }
      bool Find(int k, T& x) const;
      int Search(const T& x) const;
      AbstractList<T>& Delete(int k, T& x);
      AbstractList<T>& Insert(int k, const T& x);
      void Output(std::ostream& out) const;
   private:
      int length;
      int MaxSize;
      T *element;
};

template<class T>
LinearList<T>::LinearList(int MaxListSize) {
   MaxSize = MaxListSize;
   element = new T[MaxSize];
   length = 0;
}

template<class T>
bool LinearList<T>::Find(int k, T& x) const {
   if (k < 1 || k > length) return false;
   x = element[k - 1];
   return true;
}

template<class T>
int LinearList<T>::Search(const T& x) const {
   for (int i = 0; i < length; i++)
      if (element[i] == x) return ++i;
   return 0;
}

template<class T>
AbstractList<T>& LinearList<T>::Delete(int k, T& x) {
   if (Find(k, x)) {
      for (int i = k; i < length; i++)
         element[i-1] = element[i];
      length--;
      return *this;
   } else {
      throw OutOfBounds();
   }
}

template<class T>
AbstractList<T>& LinearList<T>::Insert(int k, const T& x) {
   if (k < 0 || k > length) {
      throw OutOfBounds();
   }
   if (length == MaxSize) {
      throw NoMem();
   }
   for (int i = length - 1; i >= k; i--) {
      element[i + 1] = element[i];
   }
   element[k] = x;
   length++;
   return *this;
}

template<class T>
void LinearList<T>::Output(std::ostream& out) const {
   for (int i = 0; i < length; i++) {
      out << element[i] << "  ";
   }
}

template <class T>
std::ostream& operator<<(std::ostream& out, const LinearList<T>& x) {
   x.Output(out);
   return out;
}

#endif
