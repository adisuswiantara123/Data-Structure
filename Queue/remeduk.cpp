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
        Visit(t);
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

template <class T>
void InOrder(BinaryTreeNode<T> *t) {
    if (t) {
        InOrder(t->LeftChild);
        Visit(t);
        InOrder(t->RightChild);
    }
}

template <class T>
void PostOrder(BinaryTreeNode<T> *t) {
    if (t) {
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        Visit(t);
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


   BinaryTreeNode<char> enam('6'), dua('2'), empat('4'), tiga('3'), lima('5'), tujuh('7'), delapan('8');

   BinaryTreeNode<char> kali1('*'), kali2('*'), tambah1('+'), tambah2('+'), kurang1('-'), kurang2('-'), kuadrat('k'), akar('a');


  tambah1.LeftChild = &kali1;
  tambah1.RightChild = &akar;
  kali1.LeftChild = &kali2;
  kali1.RightChild = &kuadrat;
  kali2.LeftChild = &enam;
  kali2.RightChild =&dua;
  kuadrat.LeftChild = &kurang1;
  kurang1.LeftChild = &tiga;
  kurang1.RightChild = &lima;
  akar.RightChild = &kurang2;
  kurang2.LeftChild = &tambah2;
  kurang2.RightChild = &empat;
  tambah2.LeftChild = &tujuh;
  tambah2.RightChild = &delapan;
  


    cout << "Urutan Inorder adalah ";
    InOrder(&tambah1);
    cout << endl;

    cout << "Urutan Preorder adalah ";
    PreOrder(&tambah1);
    cout << endl;

    cout << "Urutan Postorder adalah ";
    PostOrder(&tambah1);
    cout << endl;

    cout << "Urutan Level order adalah ";
    LevelOrder(&tambah1);
    cout << endl;

    return 0;
}
