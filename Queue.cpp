#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the queue

class Queue {
    int front, rear;
    int arr[MAX];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool enqueue(int x);
    int dequeue();
    int peek();
    bool isEmpty();
    void display();
};

bool Queue::enqueue(int x) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow" << endl;
        return false;
    } else {
        if (front == -1) front = 0; // When the first element is added
        arr[++rear] = x;
        cout << x << " enqueued to queue" << endl;
        return true;
    }
}

int Queue::dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
        return 0;
    } else {
        int x = arr[front++];
        if (front > rear) {
            // Reset queue when empty
            front = rear = -1;
        }
        return x;
    }
}

int Queue::peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty" << endl;
        return 0;
    } else {
        return arr[front];
    }
}

bool Queue::isEmpty() {
    return (front == -1 || front > rear);
}

void Queue::display() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                cout << q.dequeue() << " dequeued from queue" << endl;
                break;
            case 3:
                cout << "Front element is: " << q.peek() << endl;
                break;
            case 4:
                q.display();
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
