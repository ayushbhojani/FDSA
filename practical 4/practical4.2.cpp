#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
    Node* head;

public:
    Queue() {
        head = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void deleteValue(int value) {
        if (head == NULL)
            return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != value)
            temp = temp->next;

        if (temp->next != NULL) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    void forwardPrint() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void reversePrint(Node* temp) {
        if (temp == NULL)
            return;

        reversePrint(temp->next);
        cout << temp->data << " ";
    }

    void reverse() {
        reversePrint(head);
        cout << endl;
    }
};

int main() {
    Queue q;

    q.insertEnd(101);
    q.insertEnd(102);
    q.insertEnd(103);
    q.insertEnd(104);
    q.insertEnd(105);

    cout << "Forward Queue: ";
    q.forwardPrint();

    q.deleteValue(103);

    cout << "After Deletion: ";
    q.forwardPrint();

    cout << "Reverse Queue: ";
    q.reverse();

    return 0;
}
