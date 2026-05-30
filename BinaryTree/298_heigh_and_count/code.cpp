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


void LevelOrder(struct Node *p)
{
    Queue q;
    createQueue(&q,100);
    cout << p->data << " ";
    enqueue(&q,p);
    while(!isEmpty(q))
    {

        p = dequeue(&q);
        if(p->lchild)
        {
            cout << p->lchild->data << " ";
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            cout << p->rchild->data << " ";
            enqueue(&q,p->rchild);
        }
    }

}



void printSpaces(int count)
{
    for(int i = 0; i < count; i++)
    {
        cout << " ";
    }
}


int height(struct Node *root)
{
    int x =0 ;int y=0;
    if(root==0) return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if(x>y) return x+1;
    else return y+1;
}

void VisualLevelOrder(Node *root)
{
    if(root == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }

    int h = height(root);

    Queue q;
    createQueue(&q, 100);

    enqueue(&q, root);

    int level = 1;

    while(level <= h)
    {
        int nodesAtLevel = 1;

        for(int i = 1; i < level; i++)
        {
            nodesAtLevel = nodesAtLevel * 2;
        }

        int frontSpace = 1;

        for(int i = level; i < h; i++)
        {
            frontSpace = frontSpace * 2;
        }

        printSpaces(frontSpace * 2);

        for(int i = 0; i < nodesAtLevel; i++)
        {
            Node *temp = NULL;

            if(!isEmpty(q))
            {
                temp = dequeue(&q);
            }

            if(temp)
            {
                cout << temp->data;

                enqueue(&q, temp->lchild);
                enqueue(&q, temp->rchild);
            }
            else
            {
                cout << " ";
                enqueue(&q, NULL);
                enqueue(&q, NULL);
            }

            printSpaces(frontSpace * 4);
        }

        cout << "\n\n";

        level++;
    }
}




int count (Node *root)
{
    if(root)
    {
        return count(root->lchild) + count(root->rchild) +1;
    }
    return 0;
}





int main()
{
    create();
   VisualLevelOrder(root);
cout << "\nCount is: " << count(root);
cout << "\nHeight is: " << height(root);
    return 0;
}