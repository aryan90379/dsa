#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#include "Queue.h"

 Node *root = NULL;


void create()
{
struct Node *p,*t;
int x;
struct Queue q;
createQueue(&q,100);
cout << "Enter root value";
cin >> x;
root =  new Node;
root->data = x;
root->lchild = root->rchild = NULL;
enqueue(&q,root);

while(!isEmpty(q))
{
    p = dequeue(&q);
    cout << "Enter left child of " << p->data << ": ";
    cin >> x;
    if(x!=-1)
    {
        t  = new Node;
        t->data = x;
        t->rchild = t->lchild = NULL;
        p->lchild = t;
        enqueue(&q,t);
    }
    cout << "Enter right child of " << p->data << ": ";
    cin >> x;
    if(x!=-1)
    {
        t  = new Node;
        t->data = x;
        t->rchild = t->lchild = NULL;
        p->rchild = t;
        enqueue(&q,t);
    }
}

}


void preorder(struct Node *p)
{
    if(p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void InOrder(struct Node *p)
{
    if(p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}
void PostOrder(struct Node *p)
{
    if(p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}

int main()
{
    create();
    PostOrder(root);
    return 0;
}