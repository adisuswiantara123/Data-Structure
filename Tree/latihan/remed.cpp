#include <iostream>
#include <queue>
#include <sstream>
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
BinaryTreeNode<T>* ConstructTreeFromPrefixExpression(istringstream& iss) {
    string token;
    iss >> token;

    if (token.empty())
        return nullptr;

    BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(token);

    if (isdigit(token[0])) {
        // If the token is a number, it's a leaf node
        newNode->LeftChild = nullptr;
        newNode->RightChild = nullptr;
    } else {
        // If the token is an operator, recursively construct left and right subtrees
        newNode->LeftChild = ConstructTreeFromPrefixExpression<T>(iss);
        newNode->RightChild = ConstructTreeFromPrefixExpression<T>(iss);
    }

    return newNode;
}

template <class T>
void PreOrder(BinaryTreeNode<T> *t) {
    if (t) {
        Visit(t);
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

int main() {
    string prefixExpression = "+ * * 6 8 k - 3 5 a - + 7 4 2";
    istringstream iss(prefixExpression);

    BinaryTreeNode<string>* root = ConstructTreeFromPrefixExpression<string>(iss);

    cout << "Preorder sequence is ";
    PreOrder(root);
    cout << endl;

    return 0;
}
