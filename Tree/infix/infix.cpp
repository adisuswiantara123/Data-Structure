#include "infix.h"
#include <iostream>
using namespace std;

int main() {
    BinaryTreeNode<int> x, y, z;
    x.data = 1;
    y.data = 2;
    z.data = 3;
    x.LeftChild = &y;
    x.RightChild = &z;
    y.LeftChild = y.RightChild = z.LeftChild = z.RightChild = nullptr;

    Infix(&x);
    cout << endl;

    return 0;
}
