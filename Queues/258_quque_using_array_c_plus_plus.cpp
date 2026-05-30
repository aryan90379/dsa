#include <stdio.h>

#include <iostream>

using namespace std;

class Queue
{
private:
    int size; 
    int front;
    int rear;
    int *Q;
public:
Queue(){front = rear = -1;size =10;Q = new int[size];}
Queue(int size){front = rear = -1;this->size =size;Q = new int[this->size];}
void enqueue(int x);
int dequeue();
void Display();
};



void Queue::enqueue( int x)
{
    if (rear == size - 1)
    {
        cout << "Queue is full";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;

    if (front == rear)
        cout << "Queue is empty";
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::Display()
{
    if (front == rear)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "\nQueue Elements:\n";
    cout << "Front -> ";

    for (int i = front + 1; i <= rear; i++)
    {
        cout << "[" << Q[i] << "]";

        if (i != rear)
            cout << " -> ";
    }

    cout << " <- Rear" << endl;
}

int main()
{
     Queue q(5);
    
    q.enqueue(10);
    q.enqueue(28);
    q.enqueue(47);
    q.Display();
    cout << q.dequeue();
    q.enqueue(182);
    q.Display();

    return 0;
}
