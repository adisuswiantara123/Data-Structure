#include <iostream>
#include "alllist.h"
#include "xcept.h"

int main() {
   int x;
   try {
      LinearList<int> L(5);
      std::cout << "Length = " << L.Length() << std::endl;
      std::cout << "IsEmpty = " << L.IsEmpty() << std::endl;
      L.Insert(0, 2).Insert(1, 6);
      std::cout << "List is " << L << std::endl;
      std::cout << "IsEmpty = " << L.IsEmpty() << std::endl;
      L.Find(1, x);
      std::cout << "First element is " << x << std::endl;
      std::cout << "Length = " << L.Length() << std::endl;
      L.Delete(1, x);
      std::cout << "Deleted element is " << x << std::endl;
      std::cout << "List is " << L << std::endl;
   } catch (std::exception& e) {
      std::cerr << "An exception has occurred: " << e.what() << std::endl;
   }
   return 0;
}
