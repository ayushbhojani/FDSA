#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = NULL;
    }
};

class Browser {
    Node* top;

public:
    Browser() {
        top = NULL;
    }

    void visit(string page) {
        Node* n = new Node(page);
        n->next = top;
        top = n;
        cout << "Current Page: " << top->page << endl;
    }

    void back() {
        if (top == NULL) {
            cout << "No history" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;

        if (top == NULL)
            cout << "No page" << endl;
        else
            cout << "Current Page: " << top->page << endl;
    }
};

int main() {
    Browser b;
    int choice;
    string page;

    cout << "1. Visit" << endl;
    cout << "2. Back" << endl;
    cout << "0. Exit" << endl;

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1) {
            cout << "Enter page: ";
            cin >> page;
            b.visit(page);
        } else if (choice == 2) {
            b.back();
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
