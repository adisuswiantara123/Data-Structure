#include <iostream>
#include <queue>
using namespace std;

template <class T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode* LeftChild;
    BinaryTreeNode* RightChild;

    // Constructor for convenience
    BinaryTreeNode(T val) : data(val), LeftChild(nullptr), RightChild(nullptr) {}
};

template <class T>
void Visit(BinaryTreeNode<T> *x) {
    cout << x->data << ' ';
}

template <class T>
void PreOrder(BinaryTreeNode<T> *t) {
    if (t) {
        Visit(t);                 // visit tree root
        PreOrder(t->LeftChild);   // do left subtree
        PreOrder(t->RightChild);  // do right subtree
    }
}

template <class T>
void InOrder(BinaryTreeNode<T> *t) {
    if (t) {
        InOrder(t->LeftChild);    // do left subtree
        Visit(t);                 // visit tree root
        InOrder(t->RightChild);   // do right subtree
    }
}

template <class T>
void PostOrder(BinaryTreeNode<T> *t) {
    if (t) {
        PostOrder(t->LeftChild);   // do left subtree
        PostOrder(t->RightChild);  // do right subtree
        Visit(t);                  // visit tree root
    }
}

template <class T>
void LevelOrder(BinaryTreeNode<T> *t) {
    if (!t)
        return;

    queue<BinaryTreeNode<T>*> Q;
    Q.push(t);

    while (!Q.empty()) {
        BinaryTreeNode<T>* current = Q.front();
        Q.pop();

        Visit(current);

        if (current->LeftChild) Q.push(current->LeftChild);
        if (current->RightChild) Q.push(current->RightChild);
    }
}

int main() {
    BinaryTreeNode<int> x(1), y(2), z(3);
    x.LeftChild = &y;
    x.RightChild = &z;

    cout << "Inorder sequence is ";
    InOrder(&x);
    cout << endl;

    cout << "Preorder sequence is ";
    PreOrder(&x);
    cout << endl;

    cout << "Postorder sequence is ";
    PostOrder(&x);
    cout << endl;

    cout << "Level order sequence is ";
    LevelOrder(&x);
    cout << endl;

    return 0;
}
