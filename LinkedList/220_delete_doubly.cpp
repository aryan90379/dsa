#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    static int flag = 0;
    while (p)
    {
        if (p->next == NULL)
            flag = 1;
        (flag == 0) ? (cout << p->data << " --> ") : (cout << p->data);
        p = p->next;
    }
    cout << endl;
}

int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(Node *p, int index, int x)
{
    Node *t;
    int i;

    if (index < 0 || index > Length(p))
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}


int Delete(Node *p,int index)
{
    struct Node *q;
    int x = -1,i;
    if(index < 1 || index >Length (p)) return -1;

    if(index ==1)
    {
        first = first ->next;
        if(first) first->prev = NULL;
        x = p->data;
        delete p;
    }
    else {
        for(i=0;i<index-1;i++) p = p->next;
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        x = p->data;
        delete p; // free (p)
    }
    return x;
}

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    create(A, 5);
    Insert(first,5,23);
    Delete(first,6);
    Display(first);
    cout << "esfad";
    
    cout << "Length of Linked List is: " << Length(first) << endl;
    return 0;
}