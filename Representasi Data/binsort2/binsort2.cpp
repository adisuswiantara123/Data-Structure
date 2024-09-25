// main.cpp
// bin sort as a member of the chain class

#include <iostream>
#include "binnode2.h"
#include "nchain.h"

int main()
{
   Node x;
   Chain<Node> L;
   for (int i = 1; i <= 20; i++) {
      x.score = i / 2;
      L.Insert(0, x);
   }
   L.BinSort(10);
   std::cout << L << std::endl;

   return 0;
}
