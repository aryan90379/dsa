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
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
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
    while (p)
    {
        if (p->next)
            cout << p->data << " --> ";
        else
            cout << p->data;
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

void Reverse(Node *p)
{
    Node *temp = NULL;

    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        if (p->prev == NULL)
            first = p;

        p = p->prev;
    }
}

int middle(Node *p)
{
    Node *q = p;
    while (p)
    {
        p = p->next;
        if (p) p = p->next;
        if (p) q = q->next;
    }
    return q->data;
}

Node* intersectionTwoPointer(Node* head1, Node* head2)
{
    // Step 1: if any list is empty → no intersection
    if (head1 == NULL || head2 == NULL)
        return NULL;

    Node* p1 = head1;
    Node* p2 = head2;

    // Step 2: loop until both pointers are equal
    while (p1 != p2)
    {
        // move pointer of list1
        if (p1 == NULL)
            p1 = head2;   // jump to other list
        else
            p1 = p1->next;

        // move pointer of list2
        if (p2 == NULL)
            p2 = head1;   // jump to other list
        else
            p2 = p2->next;
    }

    // Step 3: either intersection node OR NULL
    return p1;
}

int main()
{
    int A[7] = {1, 2, 3, 4, 5, 6, 7};
    create(A, 7);

    // create second list
    Node *second = new Node;
    second->data = 100;
    second->prev = NULL;

    Node *temp = new Node;
    temp->data = 200;
    temp->prev = second;

    second->next = temp;

    // 🔥 Make intersection at node 4
    temp->next = first->next->next->next; 

    cout << "First List:\n";
    Display(first);

    cout << "Second List:\n";
    Display(second);

    Node* inter = intersectionTwoPointer(first, second);

    if (inter)
        cout << "Intersection at node with value: " << inter->data << endl;
    else
        cout << "No intersection\n";

    return 0;
}