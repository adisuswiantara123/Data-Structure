#ifndef Node_
#define Node_

template <class T> class Chain;

class Node {
   friend void BinSort(Chain<Node>&, int);
  friend int main();

   public:
      operator int() const {return score;}
   private:
      int score;
      char *name;
};

#endif
