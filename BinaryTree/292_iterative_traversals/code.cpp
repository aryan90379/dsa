#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#include "Stack.h"

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

void IPreOrder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk,100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            cout << p->data << " "; 
            push(&stk,p) ;
            p = p->lchild;
        }
        else 
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}


void IInOrder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk,100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk,p) ;
            p = p->lchild;
            
        }
        else 
        {
            p = pop(&stk);
            cout << p->data << " "; 
            p = p->rchild;
        }
    }
}



void IPostOrder(struct Node *p)
{
    struct Stack stk;
    long int temp;
    StackCreate(&stk,100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk,p) ;
            p = p->lchild;
            
        }
        else 
        {
            temp = (long int) pop(&stk);
            if(temp>0)
            {
                push(&stk,(Node*)(-temp));
                p = ((Node*)temp)->rchild;
            }
            else
            {
                p = (Node *)(-temp);
                cout << p->data << " ";
                p = NULL;
            }
            
        }
    }
}


int main()
{
    create();
    IPostOrder(root);
    return 0;
}