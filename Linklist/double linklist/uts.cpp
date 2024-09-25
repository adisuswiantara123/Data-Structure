#include<iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    public:
        Node* head;
        DoublyLinkedList() {
            head = NULL;
        }

        void addNode(Node* node) {
            Node* newNode = new Node();
            newNode->data = node->data;
            newNode->next = NULL;
            newNode->prev = NULL;

            if(head == NULL) {
                head = newNode;
            } else {
                Node* temp = head;
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
        }

        void deleteNode(char data) {
            Node* temp = head;
            while(temp != NULL) {
                if(temp->data == data) {
                    if(temp->prev != NULL) {
                        temp->prev->next = temp->next;
                    }
                    if(temp->next != NULL) {
                        temp->next->prev = temp->prev;
                    }
                    if(temp == head) {
                        head = temp->next;
                    }
                    delete temp;
                    return;
                }
                temp = temp->next;
            }
        }

        void printList() {
            Node* temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    DoublyLinkedList dll;
    Node* A = new Node();
    A->data = 'A';
    A->next = NULL;
    A->prev = NULL;
    dll.addNode(A);

    Node* B = new Node();
    B->data = 'B';
    B->next = NULL;
    B->prev = A;
    dll.addNode(B);

    Node* C = new Node();
    C->data = 'C';
    C->next = NULL;
    C->prev = B;
    dll.addNode(C);

    Node* D = new Node();
    D->data = 'D';
    D->next = NULL;
    D->prev = C;
    dll.addNode(D);

    cout << "List awal: ";
    dll.printList();

    cout << "Penambahan B: ";
    dll.addNode(B);
    dll.printList();

    cout << "Penambahan A: ";
    dll.addNode(A);
    dll.printList();

    cout << "Cetak kembali B menggunakan pointer -> prev: ";
    dll.addNode(C->prev);
    dll.printList();

    // Mencari posisi 'D' dan menambahkan 'C' setelahnya secara manual
    Node* temp = dll.head;
    while(temp != NULL) {
        if(temp->data == 'D') {
            Node* newNode = new Node();
            newNode->data = 'C';
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if(newNode->next != NULL) {
                newNode->next->prev = newNode;
            }
            break;
        }
        temp = temp->next;
    }
    cout << "Menambahkan node baru di tengah antara D dan B: ";
    dll.printList();

    // Menghapus elemen 'D'
    dll.deleteNode('D');
    cout << "Setelah menghapus D: ";
    dll.printList();

    return 0;
}
