#include "Queue.h"

class Tree
{

private:
   
Node *root;
public:
    Tree() { root = NULL; }
    void CreateTree();
    void PreOrder(){PreOrder(root);}
    void PreOrder(Node *p);
    void InOrder(){InOrder(root);}
    void InOrder(Node *p);
    void PostOrder(){PostOrder(root);}
    void PostOrder(Node *p);
    void LevelOrder(){LevelOrder(root);}
    void LevelOrder(Node *p);
    int Height(){return Height(root);}
    int Height(Node *root);
};


void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
    cout << "Enter root value";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue( root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->rchild = t->lchild = NULL;
            p->lchild = t;
            q.enqueue( t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->rchild = t->lchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}



void Tree::PreOrder( Node *p)
{
    if(p)
    {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void Tree::InOrder( Node *p)
{
    if(p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}
void Tree::PostOrder( Node *p)
{
    if(p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::LevelOrder(Node *p)
{
    Queue q(100);
    cout << root->data;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        root = q.dequeue();
        if(root->lchild)
        {
            cout << root->lchild->data;
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            cout << root->rchild->data;
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(Node *root)
{
    int x=0,y=0;
    if(root==0)
    {
        return 0;
    }
    x = Height(root->lchild);
    y = Height(root->rchild);
    if(x>y)
    {
        return x+1;
    
    }
    else 
        return y+1;
}


int main()
{
    Tree t;
    t.CreateTree();
    cout <<"\nPReorder: ";
    t.PreOrder();
    cout <<"\nInorder: ";
    t.InOrder();
    cout <<"\nPostorder: ";
    t.PostOrder();



    return 0;
}