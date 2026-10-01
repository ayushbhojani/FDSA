#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class SinglyCircular {
    Node* head;

public:
    SinglyCircular() {
        head = NULL;
    }

    void insert(int value) {
        Node* n = new Node(value);

        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    void remove(int value) {
        if (head == NULL)
            return;

        Node* temp = head;
        Node* prev = NULL;

        do {
            if (temp->data == value)
                break;

            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp->data != value)
            return;

        if (temp == head) {
            if (head->next == head) {
                delete head;
                head = NULL;
            } else {
                Node* last = head;

                while (last->next != head)
                    last = last->next;

                head = head->next;
                last->next = head;
                delete temp;
            }
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

class DoublyCircular {
    Node* head;

public:
    DoublyCircular() {
        head = NULL;
    }

    void insert(int value) {
        Node* n = new Node(value);

        if (head == NULL) {
            head = n;
            n->next = n;
            n->prev = n;
            return;
        }

        Node* last = head->prev;

        n->next = head;
        n->prev = last;
        last->next = n;
        head->prev = n;
    }

    void remove(int value) {
        if (head == NULL)
            return;

        Node* temp = head;

        do {
            if (temp->data == value)
                break;

            temp = temp->next;
        } while (temp != head);

        if (temp->data != value)
            return;

        if (temp->next == temp) {
            delete temp;
            head = NULL;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if (temp == head)
            head = temp->next;

        delete temp;
    }

    void display() {
        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    SinglyCircular s;
    DoublyCircular d;

    int n, value;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter students: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        s.insert(value);
        d.insert(value);
    }

    cout << "Singly Circular: ";
    s.display();

    cout << "Doubly Circular: ";
    d.display();

    cout << "Enter student to remove: ";
    cin >> value;

    s.remove(value);
    d.remove(value);

    cout << "After removal:" << endl;

    cout << "Singly Circular: ";
    s.display();

    cout << "Doubly Circular: ";
    d.display();

    return 0;
}
