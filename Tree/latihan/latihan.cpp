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
        Visit(t);                 // kunjungi akar pohon
        PreOrder(t->LeftChild);   // lakukan subpohon kiri
        PreOrder(t->RightChild);  // lakukan subpohon kanan
    }
}

template <class T>
void InOrder(BinaryTreeNode<T> *t) {
    if (t) {
        InOrder(t->LeftChild);    // lakukan subpohon kiri
        Visit(t);                 // kunjungi akar pohon
        InOrder(t->RightChild);   // lakukan subpohon kanan
    }
}

template <class T>
void PostOrder(BinaryTreeNode<T> *t) {
    if (t) {
        PostOrder(t->LeftChild);   // lakukan subpohon kiri
        PostOrder(t->RightChild);  // lakukan subpohon kanan
        Visit(t);                  // kunjungi akar pohon
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

template <class T>
int CountNodes(BinaryTreeNode<T>* t) {
    if (!t)
        return 0;

    return 1 + CountNodes(t->LeftChild) + CountNodes(t->RightChild);
}

template <class T>
int Level(BinaryTreeNode<T>* t) {
    if (!t)
        return 0;

    int leftLevel = Level(t->LeftChild);
    int rightLevel = Level(t->RightChild);

    return 1 + max(leftLevel, rightLevel);
}

template <class T>
int Degree(BinaryTreeNode<T>* t, T value) {
    if (!t)
        return 0;

    if (t->data == value) {
        int degree = 0;
        if (t->LeftChild) degree++;
        if (t->RightChild) degree++;
        return degree;
    }

    int leftDegree = Degree(t->LeftChild, value);
    if (leftDegree != 0)
        return leftDegree;

    return Degree(t->RightChild, value);
}

template <class T>
int LeafNodes(BinaryTreeNode<T>* t) {
    if (!t)
        return 0;

    if (!t->LeftChild && !t->RightChild)
        return 1;

    return LeafNodes(t->LeftChild) + LeafNodes(t->RightChild);
}

template <class T>
int Depth(BinaryTreeNode<T>* t) {
    if (!t)
        return 0;

    int leftDepth = Depth(t->LeftChild);
    int rightDepth = Depth(t->RightChild);

    return 1 + max(leftDepth, rightDepth);
}

template <class T>
bool IsAncestor(BinaryTreeNode<T>* ancestor, BinaryTreeNode<T>* descendant) {
    if (!ancestor || !descendant)
        return false;

    if (ancestor == descendant)
        return true;

    return IsAncestor(ancestor, descendant->LeftChild) || IsAncestor(ancestor, descendant->RightChild);
}

int main() {
    BinaryTreeNode<char> h('H'), a('A'), k('K'), c('C'), j('J'), l('L'), b('B'), d('D');

    h.LeftChild = &a;
    h.RightChild = &k;
    a.LeftChild = nullptr;
    a.RightChild = &c;
    k.LeftChild = &j;
    k.RightChild = &l;
    c.LeftChild = &b;
    c.RightChild = &d;

    cout << "Urutan Inorder adalah ";
    InOrder(&h);
    cout << endl;

    cout << "Urutan Preorder adalah ";
    PreOrder(&h);
    cout << endl;

    cout << "Urutan Postorder adalah ";
    PostOrder(&h);
    cout << endl;

    cout << "Urutan Level order adalah ";
    LevelOrder(&h);
    cout << endl;

    cout << "Jumlah node: " << CountNodes(&h) << endl;
    cout << "Jumlah level dari pohon: " << Level(&h) << endl;
    cout << "Derajat 'K': " << Degree(&h, 'K') << endl;
    cout << "Jumlah daun: " << LeafNodes(&h) << endl;
    cout << "Kedalaman pohon: " << Depth(&h) << endl;

    // Mengecek apakah ancestor atau bukan
    if (IsAncestor(&l, &k))
        cout << "'l' adalah ancestor dari 'k'" << endl;
    else
        cout << "'l' bukan ancestor dari 'k'" << endl;

    return 0;
}
