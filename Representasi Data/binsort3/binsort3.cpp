#include <iostream>
#include <cstdlib>
#include "binnode4.h"
#include "mchain.h"

inline int F1(Node& x) { return x.exam1; }
inline int F2(Node& x) { return x.exam2; }
inline int F3(Node& x) { return x.exam1 + x.exam2 + x.exam3; }

int main()
{
   Node x;
   Chain<Node> L;
   std::srand(time(nullptr));
   for (int i = 1; i <= 20; i++) {
      x.exam1 = i / 2;
      x.exam2 = 20 - i;
      x.exam3 = std::rand() % 100;
      x.name = i;
      L.Insert(0, x);
   }
   L.BinSort(10, F1);
   std::cout << "Sort on exam 1" << std::endl;
   std::cout << L << std::endl;
   L.BinSort(20, F2);
   std::cout << "Sort on exam 2" << std::endl;
   std::cout << L << std::endl;
   L.BinSort(130, F3);
   std::cout << "Sort on the sum of exams" << std::endl;
   std::cout << L << std::endl;

   return 0;
}
