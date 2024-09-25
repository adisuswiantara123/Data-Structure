#ifndef AbstractList_
#define AbstractList_

template<class T>
class AbstractList {
   public:
      virtual bool IsEmpty() const = 0;
      virtual int Length() const = 0;
      virtual bool Find(int k, T& x) const = 0;
      virtual int Search(const T& x) const = 0;
      virtual AbstractList<T>& Delete(int k, T& x) = 0;
      virtual AbstractList<T>& Insert(int k, const T& x) = 0;
      virtual void Output(std::ostream& out) const = 0;
};

#endif
