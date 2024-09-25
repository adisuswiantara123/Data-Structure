#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void setHead(Node* node) {
        this->head = node;
    }

    void setTail(Node* node) {
        this->tail = node;
    }

    void cetakmaju() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

    }

    void deleteNode(Node* node) {
        if (head == NULL || node == NULL)
            return;

        if (head == node)
            head = node->next;

        if (node->next != NULL)
            node->next->prev = node->prev;

        if (node->prev != NULL)
            node->prev->next = node->next;

        delete node;
    }
};

int main() {
    LinkedList list;

    Node* B = new Node;
    B->data = 'B';
    B->next = NULL;
    B->prev = NULL;
    list.setHead(B);
    list.setTail(B);
    list.cetakmaju();
    cout << endl;

    Node* D = new Node;
    D->data = 'D';
    D->next = NULL;
    D->prev = B;
    B->next = D;
    list.setTail(D);
    list.cetakmaju();
    cout << endl;

    Node* C = new Node;
    C->data = 'C';
    Node* temp = B->next;
    C->next = temp;
    C->prev = B;
    B->next = C;
    temp->prev = C;
    list.cetakmaju();
    cout << endl;

    Node* A = new Node;
    A->data = 'A';
    A->next = B;
    A->prev = NULL;
    B->prev = A;
    list.setHead(A);
    list.cetakmaju();
    cout << endl;


    list.cetakmaju();
    Node* jalan = D->prev;
    while(jalan != NULL){
        cout<<jalan->data<<" ";
        jalan = jalan->prev;
    }//output: C B A(mundur)


    cout<<endl;
     list.cetakmaju();
     jalan = D->prev;
    while(jalan != NULL){
        cout<<jalan->data<<" ";
        jalan = jalan->prev;
    }

    jalan = A->next;
    while(jalan != C){
         cout<<jalan->data<<" ";
        jalan = jalan->next;
    }//output: B(maju) 

    cout<<endl;

    list.deleteNode(D);

    list.cetakmaju();
     jalan = C;
    while(jalan != NULL){
        cout<<jalan->data<<" ";
        jalan = jalan->prev;
    }

    jalan = A->next;
    while(jalan != C){
         cout<<jalan->data<<" ";
        jalan = jalan->next;
    }


    return 0;
}
