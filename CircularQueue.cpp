#include <iostream>
using namespace std;
#define MAXSIZE 5

class CircularQueue {
    int arr[MAXSIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if ((rear + 1) % MAXSIZE == front) {
            cout << "Queue is Full!"<<endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } 
        else {
            rear = (rear + 1) % MAXSIZE;
        }

        arr[rear] = value;
        cout << value << " inserted"<<endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is Empty!"<<endl;
            return;
        }

        cout << arr[front] << " deleted"<<endl;

        if (front == rear) {
            front = rear = -1;
        } 
        else {
            front = (front + 1) % MAXSIZE;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty!"<<endl;
            return;
        }

        cout << "Queue: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAXSIZE;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << " Circular Queue "<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting"<<endl;
                break;

            default:
                cout << "Invalid choice!"<<endl;
        }

    } while (choice != 4);

    return 0;
}