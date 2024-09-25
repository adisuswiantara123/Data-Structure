#ifndef Node_
#define Node_
#include <iostream>

template <class T> class Chain;

class Node {
   friend std::ostream& operator<<(std::ostream&, const Node &);
   friend void BinSort(Chain<Node>&, int);
   friend int F1(Node&);
   friend int F2(Node&);
   friend int F3(Node&);
   friend int main();
   public:
      operator int() const {return exam1;}
   private:
      int exam1, exam2, exam3;
      int name;
};

std::ostream& operator<<(std::ostream& out, const Node& x)
{
   out << x.name << ' ' << x.exam1 << ' ' << x.exam2 
       << ' ' << x.exam3 << std::endl;
    return out;
}

#endif
