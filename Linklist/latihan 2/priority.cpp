#include <iostream>
using namespace std;

struct Node {
    char data;
    int priority;
    Node* next;
    Node* prev;
};

void cetak(Node* front) {
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    Node* A = new Node;
    A->data = 'A';
    A->priority = 3;
    A->next = NULL;
    A->prev = NULL;

    Node* B = new Node;
    B->data = 'B';
    B->priority = 1;
    B->next = NULL;
    B->prev = A;
    A->next = B;

    Node* C = new Node;
    C->data = 'C';
    C->priority = 2;
    C->next = NULL;
    C->prev = B;
    B->next = C;

    Node* D = new Node;
    D->data = 'D';
    D->priority = 4;
    D->next = NULL;
    D->prev = C;
    C->next = D;  

    cout << "Isi Link saat ini: ";
    cetak(A);
    cout << endl;

    cout << "Isi link berturut-turut yang akan dequeue sesuai prioritas:" << endl;

    // Enqueue A
    if (front == NULL) {
        front = rear = A;
    } else {
        if (A->priority < front->priority) {
            A->next = front;
            front->prev = A;
            front = A;
        } else if (A->priority >= rear->priority) {
            rear->next = A;
            A->prev = rear;
            rear = A;
        } else {
            Node* temp = front->next;
            while (temp->priority < A->priority) {
                temp = temp->next;
            }
            A->prev = temp->prev;
            A->next = temp;
            temp->prev->next = A;
            temp->prev = A;
        }
    }

    // Enqueue B
    if (front == NULL) {
        front = rear = B;
    } else {
        if (B->priority < front->priority) {
            B->next = front;
            front->prev = B;
            front = B;
        } else if (B->priority >= rear->priority) {
            rear->next = B;
            B->prev = rear;
            rear = B;
        } else {
            Node* temp = front->next;
            while (temp->priority < B->priority) {
                temp = temp->next;
            }
            B->prev = temp->prev;
            B->next = temp;
            temp->prev->next = B;
            temp->prev = B;
        }
    }

    // Enqueue C
    if (front == NULL) {
        front = rear = C;
    } else {
        if (C->priority < front->priority) {
            C->next = front;
            front->prev = C;
            front = C;
        } else if (C->priority >= rear->priority) {
            rear->next = C;
            C->prev = rear;
            rear = C;
        } else {
            Node* temp = front->next;
            while (temp->priority < C->priority) {
                temp = temp->next;
            }
            C->prev = temp->prev;
            C->next = temp;
            temp->prev->next = C;
            temp->prev = C;
        }
    }

    // Enqueue D
    if (front == NULL) {
        front = rear = D;
    } else {
        if (D->priority < front->priority) {
            D->next = front;
            front->prev = D;
            front = D;
        } else if (D->priority >= rear->priority) {
            rear->next = D;
            D->prev = rear;
            rear = D;
        } else {
            Node* temp = front->next;
            while (temp->priority < D->priority) {
                temp = temp->next;
            }
            D->prev = temp->prev;
            D->next = temp;
            temp->prev->next = D;
            temp->prev = D;
        }
    }

    cetak(front);
    cout << endl;

    // Dequeue all
    while (front != NULL) {
        Node* dequeuedNode = front;

        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }

        cout << "Dequeue: " << dequeuedNode->data << " Prioritas: " << dequeuedNode->priority << endl;
        delete dequeuedNode;

        cout << "Isi link list: ";
        cetak(front);
        cout << endl;
    }

    return 0;
}
