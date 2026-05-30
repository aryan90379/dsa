#include <stdio.h>
#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * (sizeof(int)));
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        cout << "Queue is full";
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
        cout << "Queue is empty";
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    if (q.front == q.rear)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "\nQueue Elements:\n";
    cout << "Front -> ";

    for (int i = q.front + 1; i <= q.rear; i++)
    {
        cout << "[" << q.Q[i] << "]";

        if (i != q.rear)
            cout << " -> ";
    }

    cout << " <- Rear" << endl;
}

int main()
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q,10);
    enqueue(&q,28);
    enqueue(&q,47);
    Display(q);
    cout << dequeue(&q);
    enqueue(&q,182);
    Display(q);

    return 0;
}
