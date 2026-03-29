#include <stdio.h>

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL; // first is a pointer to first node of the linked list

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

void Rdisplay(struct Node *p)
{
    if (p != NULL)
    {
        Rdisplay(p->next);
        cout << p->data << " ";
    }
}

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
    if(p!=NULL)
    return Rcount2(p->next)+1;
    else return 0;

    // or .
    
}

int sum(struct Node *p)
{
    int s = 0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}


int Rsum(struct Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    else {
        return Rsum(p->next) + p->data;
    }
}


int Max (struct Node *p)
{
  int max  = INT32_MIN;

  while(p)
  {
    if(p->data > max)
    {
      max = p->data;

    }
    p=p->next;
  }
  return max;
}


int Rmax(struct Node *p)
{
  int x = 0;
  if(p==0)
  {
    return INT32_MIN;
  }
  x = Rmax(p->next);
  return x>p->data ? x :  p->data;
}

int main()
{

    int A[] = {3, 5, 7, 10, 15, 8, 23, 16};
    create(A, 8);
    // Rdisplay(first);

    // cout << "\n\nLength is \n" << Rcount2(first) << endl<< "and the sum is \n"<< sum(first) << "\nand Rsum is \n" << Rsum(first)<< endl;

    cout << Rmax(first) <<endl;
    return 0;
}
