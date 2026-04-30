#include <stdio.h>

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL; // first is a pointer to first node of the linked list

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    // t is the temporary pinter to creat ethe new node
    // last , keeps track of last node in the list
    // both first and last point to the same node

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;

    // t is the temporary pinter to creat ethe new node
    // last , keeps track of last node in the list
    // both first and last point to the same node

    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// void Rdisplay(struct Node *p)
// {
//     if (p != NULL)
//     {
//         cout << p->data << " ";
//         Rdisplay(p->next);
//     }
// }

// void Rdisplay(struct Node *p)
// {
//     static bool first = true;

//     if(p!=NULL)
//     {
//         Rdisplay(p->next);

//         if(!first)
//             cout << "->";

//         cout << p->data;
//         first = false;
//     }
// }

// in the correct order

void Rdisplay(Node *p)
{
    if (p != NULL)
    {
        cout << p->data;
        if (p->next != NULL)
            cout << "->";

        Rdisplay(p->next);
    }
}

int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

int Rcount(struct Node *p)
{
    if (!p)
    {
        return 0;
    }
    else
    {
        return 1 + Rcount(p->next);
    }

    // or .
}
int Rcount2(struct Node *p)
{
    if (p != NULL)
        return Rcount2(p->next) + 1;
    else
        return 0;

    // or .
}

int sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int Rsum(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return Rsum(p->next) + p->data;
    }
}

int Max(struct Node *p)
{
    int max = INT32_MIN;

    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT32_MIN;
    }
    x = Rmax(p->next);
    return x > p->data ? x : p->data;
}

struct Node *LinearSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node *RSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}

void Insert(struct Node *p, int index, int value)
{
    int i;
    struct Node *t;
    if (index < 0 || index > count(p))
    {
        return;
    }

    t = new Node;
    t->data = value;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (index < 1 || index > count(p))
    {
        cout << "invalid index" << endl;
    }
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        cout << "deleted element is" << x << endl;
    }
    else
    {

        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        cout << "deleted element is " << x << endl;
    }
}

int isSorted(struct Node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void Reverse1(struct Node *p)
{
    int *A, i = 0;

    Node *q = p;
    A = new int[count(p)];

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse2(Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(Node *q, Node *p) // recursive
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void Concat(struct Node *p, struct Node *q)
{
    third = p;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;

    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }

        if (p)
            last->next = p;
        if (q)
            last->next = q;
    }
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f;
    do
    {
        p = p->next;
        q = q->next;
        if (q)
            q = q->next;
    } while (p && q && p != q);

    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Node *t1, *t2;

    // have to ber ordered
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    // forming a loop
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    if(isLoop(first))
    {
        cout << "it is a loop";
    }
    else {
        cout << "not a loop";
    }

    cout << "\n";

        return 0;
}
