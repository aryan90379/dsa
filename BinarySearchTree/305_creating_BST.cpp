#include <stdio.h>
#include <iostream>
using namespace std;
#include <math.h>


struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r ,*p ;

    if(!root)
    {
        root  = p =  new Node;
        p->data = key;
        p->rchild = p->lchild = NULL;
        return;
    }

    while(t!=NULL)
    {
        r = t;
        if(key<t->data) t= t->lchild;
        else if(key>t->data) t= t->rchild;
        else return ;
    }

    p =  new Node;
    p->data = key;
    p->rchild = p->lchild = NULL;
    if(key<r->data) r->lchild = p;
    else r->rchild = p;
}

void Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << "  \n";
        Inorder(p->rchild);
    }
}



Node * Search(int key)
{
    Node *t = root;
    while(t)
    {
        if(key == t->data) return t;
        else if(key<t->data) t = t->lchild;
        else t = t->rchild;
    }
    return NULL;
}


int main ()
{
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);



    Inorder(root);
    Node *temp = Search(8);
    if(temp) {cout << "element:" << temp->data << " is found.\n";}
    else cout << "element not found";
    return 0;
}

