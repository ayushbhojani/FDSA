#include <iostream>
using namespace std;

class Stack {
    int a[100];
    int top;
    int size;

public:
    Stack(int n) {
        size = n;
        top = -1;
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }

        a[++top] = value;
        cout << "Top: " << a[top] << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << "Taken: " << a[top--] << endl;

        if (top == -1)
            cout << "Top: Empty" << endl;
        else
            cout << "Top: " << a[top] << endl;
    }
};

int main() {
    int n, choice, value;

    cout << "Enter stack size: ";
    cin >> n;

    Stack s(n);

    cout << "1. Place" << endl;
    cout << "2. Take" << endl;
    cout << "0. Exit" << endl;

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1) {
            cout << "Enter tray: ";
            cin >> value;
            s.push(value);
        } else if (choice == 2) {
            s.pop();
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
