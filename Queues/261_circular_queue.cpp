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

Queue(int size){front = rear = 0;this->size =size;Q = new int[this->size];}

void enqueue(int x);
int dequeue();
void Display();
};



void Queue::enqueue( int x)
{
    if ((rear+1)%size == front)
    {
        cout << "Queue is full"<<'\n';
    }
    else
    {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;

    if (front == rear)
        cout << "Queue is empty" <<'\n';
    else
    {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

void Queue::Display()
{
    int i = front+1;
    do
    {
        cout << Q[i] << endl;
        i = (i+1)%size;
    }while(i!=(rear+1)%size);
}

int main()
{
     Queue q(5);
    
    q.enqueue(10);
    q.enqueue(28);
    q.enqueue(47);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(23);
    q.enqueue(82);
    q.enqueue(48);
    
    cout << endl;
    q.Display();
    

    return 0;
}
