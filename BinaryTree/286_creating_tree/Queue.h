#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <stdio.h>
using namespace std;
#include <stdlib.h>

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size; 
    int front;
    int rear;
    Node **Q;
public:
Queue(){front = rear = -1;size =10;Q = new Node*[size];}
Queue(int size){front = rear = -1;this->size =size;Q = new Node*[this->size];}
void enqueue(Node *x);
Node* dequeue();
int isEmpty(){return front == rear;}
void Display();
};




void Queue::enqueue( Node *x)
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

Node* Queue::dequeue()
{
    Node* x = NULL;

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

#endif 