#pragma once

template <class T>
class BinaryTree;

template <class E, class K>
class BSTree;

template <class E, class K>
class DBSTree;

template <class T>
class BinaryTreeNode {
    friend BinaryTree<T>;
    friend void PlaceBoosters(BinaryTreeNode<T>*);
    friend BSTree<T, int>;
    friend DBSTree<T, int>;

public:
    BinaryTreeNode() : LeftChild(nullptr), RightChild(nullptr) {}
    BinaryTreeNode(const T& e) : data(e), LeftChild(nullptr), RightChild(nullptr) {}
    BinaryTreeNode(const T& e, BinaryTreeNode* l, BinaryTreeNode* r) : data(e), LeftChild(l), RightChild(r) {}

private:
    T data;
    BinaryTreeNode<T>* LeftChild;
    BinaryTreeNode<T>* RightChild;
};
