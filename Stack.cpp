#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the stack

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void display();
};

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow" << endl;
        return false;
    } else {
        arr[++top] = x;
        cout << x << " pushed into stack" << endl;
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow" << endl;
        return 0;
    } else {
        int x = arr[top--];
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty" << endl;
        return 0;
    } else {
        int x = arr[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

void Stack::display() {
    if (top < 0) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << "Stack elements are: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                cout << s.pop() << " popped from stack" << endl;
                break;
            case 3:
                cout << "Top element is: " << s.peek() << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
