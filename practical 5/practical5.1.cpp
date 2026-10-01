#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    void insertFront(int value) {
        Node* n = new Node(value);

        if (head == NULL)
            head = tail = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void insertEnd(int value) {
        Node* n = new Node(value);

        if (head == NULL)
            head = tail = n;
        else {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
    }

    void insertAfter(int x, int value) {
        Node* temp = head;

        while (temp != NULL && temp->data != x)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Song not found" << endl;
            return;
        }

        Node* n = new Node(value);
        n->next = temp->next;
        n->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = n;
        else
            tail = n;

        temp->next = n;
    }

    void deleteFirst() {
        if (head == NULL)
            return;

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void count() {
        int c = 0;
        Node* temp = head;

        while (temp != NULL) {
            c++;
            temp = temp->next;
        }

        cout << "Count: " << c << endl;
    }
};

int main() {
    Playlist p;
    int n, value, x;

    cout << "Enter number of songs: ";
    cin >> n;

    cout << "Enter songs: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        p.insertEnd(value);
    }

    cout << "Playlist: ";
    p.display();

    cout << "Enter song to add at front: ";
    cin >> value;
    p.insertFront(value);
    p.display();

    cout << "Enter song to add at end: ";
    cin >> value;
    p.insertEnd(value);
    p.display();

    cout << "Enter song after which to insert: ";
    cin >> x;

    cout << "Enter new song: ";
    cin >> value;

    p.insertAfter(x, value);
    p.display();

    p.deleteFirst();
    cout << "After deleting first: ";
    p.display();

    p.count();

    return 0;
}
