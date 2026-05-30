#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*front = NULL,*rear = NULL;

void enqueue(int x)
{
    Node *t = new Node;
    if(t==NULL)
    {
        cout << "Node is empty";
    }
    else{
        t->data = x;
        t->next = NULL;
        if(front==NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}


int dequeue()
{
    int x = -1;
    struct Node *t;
    if(front == NULL)
    {
        cout << "Queue is empty";
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}


void Display()
{
    struct Node *p;
    p = front;
    while(p)
    {
        cout << p->data << (p->next? "->":"");
        p = p->next;
    }
    cout << endl;
}




int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    // Display();
    return 0;
}