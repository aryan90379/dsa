#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;

    last = Head;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(Node *h)
{
    static int flag = 0;
    do
    {
        if (h->next == Head)
        {
            flag = 1;
        }

        flag == 0 ? (cout << h->data << " -> ") : (cout << h->data);
        h = h->next;

    } while (h != Head);
    cout << endl;
}

void RDisplay(Node *h)
{
    static int flag = 0;
    if(h != Head || flag == 0)
    {
        flag = 1;
        cout << h->data;
        RDisplay(h->next);
    }
    cout << endl;
    flag = 0;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    // Display(Head);
    RDisplay(Head);
    return 0;
}