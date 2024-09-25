#pragma once

#include <iostream>
#include "lqueue.h"
#include "btnode2.h"


template <class T>
class BinaryTree;

template <class E, class K>
class BSTree;

template <class E, class K>
class DBSTree;

template <class T>
class BinaryTree {
    friend BSTree<T, int>;
    friend DBSTree<T, int>;

public:
    BinaryTree() : root(nullptr), _count(0) {}
    ~BinaryTree() {}
    bool IsEmpty() const { return (!root); }
    bool Root(T& x) const;
    void MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right);
    void BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right);
    void PreOrder(void (*Visit)(BinaryTreeNode<T>* u)) { PreOrder(Visit, root); }
    void InOrder(void (*Visit)(BinaryTreeNode<T>* u)) { InOrder(Visit, root); }
    void PostOrder(void (*Visit)(BinaryTreeNode<T>* u)) { PostOrder(Visit, root); }
    void LevelOrder(void (*Visit)(BinaryTreeNode<T>* u));
    void PreOutput() { PreOrder(Output, root); std::cout << std::endl; }
    void InOutput() { InOrder(Output, root); std::cout << std::endl; }
    void PostOutput() { PostOrder(Output, root); std::cout << std::endl; }
    void LevelOutput() { LevelOrder(Output); std::cout << std::endl; }
    void Delete() { PostOrder(Free, root); root = nullptr; }
    int Height() const { return Height(root); }
    int Size() { return _count; }

private:
    BinaryTreeNode<T>* root;
    int _count;
    void PreOrder(void (*Visit)(BinaryTreeNode<T>* u), BinaryTreeNode<T>* t);
    void InOrder(void (*Visit)(BinaryTreeNode<T>* u), BinaryTreeNode<T>* t);
    void PostOrder(void (*Visit)(BinaryTreeNode<T>* u), BinaryTreeNode<T>* t);
    static void Free(BinaryTreeNode<T>* t) { delete t; }
    static void Output(BinaryTreeNode<T>* t) { std::cout << t->data << ' '; }
    static void Add1(BinaryTreeNode<T>* t, int& count) { count++; }
    int Height(BinaryTreeNode<T>* t) const;
};

template <class T>
bool BinaryTree<T>::Root(T& x) const {
    if (root) {
        x = root->data;
        return true;
    } else {
        return false;
    }
}

template <class T>
void BinaryTree<T>::MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right) {
    root = new BinaryTreeNode<T>(element, left.root, right.root);
    left.root = right.root = nullptr;
}

template <class T>
void BinaryTree<T>::BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right) {
    element = root->data;
    left.root = root->LeftChild;
    right.root = root->RightChild;
    delete root;
    root = nullptr;
}

template <class T>
void BinaryTree<T>::PreOrder(void (*Visit)(BinaryTreeNode<T>* u), BinaryTreeNode<T>* t) {
    if (t) {
        Visit(t);
        Add1(t, _count);  // Menghitung jumlah node
        PreOrder(Visit, t->LeftChild);
        PreOrder(Visit, t->RightChild);
    }
}

template <class T>
void BinaryTree<T>::InOrder(void (*Visit)(BinaryTreeNode<T>* u), BinaryTreeNode<T>* t) {
    if (t) {
        InOrder(Visit, t->LeftChild);
        Visit(t);
        InOrder(Visit, t->RightChild);
    }
}

template <class T>
void BinaryTree<T>::PostOrder(void (*Visit)(BinaryTreeNode<T>* u), BinaryTreeNode<T>* t) {
    if (t) {
        PostOrder(Visit, t->LeftChild);
        PostOrder(Visit, t->RightChild);
        Visit(t);
    }
}

template <class T>
void BinaryTree<T>::LevelOrder(void (*Visit)(BinaryTreeNode<T>* u)) {
    LinkedQueue<BinaryTreeNode<T>*> Q;
    BinaryTreeNode<T>* t = root;
    while (t) {
        Visit(t);
        if (t->LeftChild) Q.Add(t->LeftChild);
        if (t->RightChild) Q.Add(t->RightChild);

        try {
            Q.Delete(t);
        } catch (std::out_of_range) {
            return;
        }
    }
}

template <class T>
int BinaryTree<T>::Height(BinaryTreeNode<T>* t) const {
    if (!t) return 0;
    int hl = Height(t->LeftChild);
    int hr = Height(t->RightChild);
    return (hl > hr) ? ++hl : ++hr;
}
