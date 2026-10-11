#include <iostream>
using namespace std;
void normalQueue()
{
    int n;
    cout << "Enter size of Queue: ";
    cin >> n;
    int q[100];
    int front = -1, rear = -1;
    int choice, value;
    do
    {
        cout << "\n--- NORMAL QUEUE ---\n";
        cout << "1. ENQUEUE\n";
        cout << "2. DEQUEUE\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                if (rear == n - 1) {
                    cout << "Queue Overflow!\n";
                }
                else {
                    cout << "Enter value: ";
                    cin >> value;
                    if (front == -1)
                        front = 0;
                    rear++;
                    q[rear] = value;
                    cout << "Inserted: " << value << endl;
                }
                break;

            case 2:
                if (front == -1 || front > rear)
                {
                    cout << "Queue Underflow!\n";
                }
                else{
                    cout << "Deleted: " << q[front] << endl;
                    front++;
                    if (front > rear) {
                     front = -1;
                        rear = -1;
                    }
                }
                break;
            case 3:
                if (front == -1)
                {
                    cout << "Queue is empty!\n";
                }
                else
                {
                    cout << "Queue: ";
                    for (int i = front; i <= rear; i++)
                    {
                        cout << q[i] << " ";
                    }
                    cout << endl;
                }
                break;
            case 4:
                cout << "Exiting Normal Queue...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);
}
void circularQueue()
{
    int n;
    cout << "\nEnter size of Circular Queue: ";
    cin >> n;
    int q[100];
    int front = -1, rear = -1;
    int choice, value;
    do
    {
        cout << "\n--- CIRCULAR QUEUE ---\n";
        cout << "1. ENQUEUE\n";
        cout << "2. DEQUEUE\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                if ((rear + 1) % n == front)
                {  cout << "Circular Queue Overflow!\n";
                }
                else
                { cout << "Enter value: ";
                    cin >> value;
                    if (front == -1)
                    {   front = 0;
                        rear = 0;
                    }
                    else
                    {   rear = (rear + 1) % n;
                    }
                    q[rear] = value;
                    cout << "Inserted: " << value << endl;
                }
                break;
            case 2:
                if (front == -1)
                {  cout << "Circular Queue Underflow!\n";
                }
                else
                {   cout << "Deleted: " << q[front] << endl;
                    if (front == rear)
                    {
                        front = -1;
                        rear = -1;
                    }
                    else
                    {
                        front = (front + 1) % n;
                    }
                }
                break;
            case 3:
                if (front == -1)
                {  cout << "Circular Queue is empty!\n";
                }
                else
                { cout << "Circular Queue: ";
                   int i = front;
                      while (true)
                    {
                        cout << q[i] << " ";
                        if (i == rear)
                            break;
                        i = (i + 1) % n;
                    }
                    cout << endl;
                }
                break;
            case 4:
                cout << "Exiting Circular Queue...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);
}

int main()
{
    normalQueue();
    circularQueue();

    return 0;
}