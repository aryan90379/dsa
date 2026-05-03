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
    if (h != Head || flag == 0)
    {
        flag = 1;
        cout << h->data;
        RDisplay(h->next);
    }
    cout << endl;
    flag = 0;
}

int Length(Node *p)
{
    int len = 0;

    if (p == NULL)
        return 0;

    Node *temp = p;
    do
    {
        len++;
        temp = temp->next;
    } while (temp != p);

    return len;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Length(p))
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while (p->next != Head)
                p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        t = new Node;
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;
    if (index < 0 || index > Length(p))
        return -1;
    if (index == 1)
    {
        while (p->next != Head)
            p = p->next;
        x = Head->data;
        if (Head == p)
        {
            delete Head;
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }

    return x;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    // Insert(Head,3,12);
    Delete(Head, 8);
    // Display(Head);
    Display(Head);
    return 0;
}