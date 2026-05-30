#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{

    int data;
    struct Node *next;
} *top = NULL;


void push (int x)
{
    Node *t = new Node;
    if(t == NULL) cout << "Stack Overflow";
    else 
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    Node *p;
    int x = -1;
    if(top == NULL) cout << "Stack is empty!!!MF";
    else 
    {
        p = top;
        top=top->next;
        x = p->data;
        delete p;
    }
    return x;

}

void Display()
{
    cout << "\n";
    cout << "=====================================\n";
    cout << "           STACK VISUALIZER          \n";
    cout << "=====================================\n\n";

    if (top == NULL)
    {
        cout << "             [ EMPTY ]\n";
        cout << "\n=====================================\n";
        return;
    }

    Node* p = top;
    int level = 0;

    while (p)
    {
        cout << "            +-----------+\n";

        if (level == 0)
            cout << " TOP -----> ";
        else
            cout << "            ";

        cout << "|"
             << setw(5)
             << p->data
             << "     |\n";

        cout << "            +-----------+\n";

        if (p->next)
        {
            cout << "                 |\n";
            cout << "                 v\n";
        }

        p = p->next;
        level++;
    }

    cout << "\n=====================================\n";
}


void peek(int pos)
{

}

int main ()
{
    push(10);
    push(50);
    push(30);
    push(140);
    push(184);
    Display();
    return 0;
}
