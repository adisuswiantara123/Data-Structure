#include <iostream>
#include "binary.h"
using namespace std;


// globals
int count = 0;
BinaryTree<int> a, x, y, z;

template <class T>
void ct(BinaryTreeNode<T>* t) {
    count++;
}

int main() {
    y.MakeTree(1, a, a);
    z.MakeTree(2, a, a);
    x.MakeTree(3, y, z);
    y.MakeTree(4, x, a);

    cout << "Preorder sequence is ";
    y.PreOutput();
    cout << "Inorder sequence is ";
    y.InOutput();
    cout << "Postorder sequence is ";
    y.PostOutput();
    cout << "Level order sequence is ";
    y.LevelOutput();
    cout << "Number of nodes = " << y.Size() << endl;
    cout << "Height = " << y.Height() << endl;

    y.PreOrder(ct);
    cout << "Count of nodes is " << count << endl;

    return 0;
}
