#include <iostream>
#define SIZE 6
using namespace std;

struct cirQueue
{
    int arr[SIZE];
    int front, rear;
    cirQueue()
    {
        front = SIZE - 1;
        rear = SIZE - 1;
    }

    bool isEmpty()
    {
        return rear == front;
    }

    bool isFull()
    {
        return ((rear + 1) % SIZE) == front;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Q is full" << endl;
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = data;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Q is empty" << endl;
            return -1;
        }
        return arr[front = (front + 1) % SIZE];
    }
};

int main()
{
    cirQueue q;
    for (int i = 1; i <= 6; i++)
        q.enqueue(i);
    q.enqueue(10);
    while (!q.isEmpty())
        cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
}