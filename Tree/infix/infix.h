#pragma once  // Guard against multiple inclusion

#include <iostream>

template <class T>
class BinaryTreeNode;  // Forward declaration

template <class T>
void Infix(BinaryTreeNode<T>* t) {
    if (t) {
        std::cout << '(';
        Infix(t->LeftChild);   // left operand
        std::cout << t->data;  // operator
        Infix(t->RightChild);  // right operand
        std::cout << ')';
    }
}

template <class Type>
class BinaryTreeNode {
    friend void Infix<Type>(BinaryTreeNode<Type>*);
    friend int main();  // Forward declaration
private:
    Type data;
    BinaryTreeNode* LeftChild;
    BinaryTreeNode* RightChild;
};
