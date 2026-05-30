#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;



void push (char x)
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

char pop()
{
    Node *p;
    char x = -1;
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


int isBalanced(const char *exp)
{
    int i;
    for(i = 0; exp[i]!='\0';i++)
    {
        if(exp[i]=='(') push(exp[i]);
        if(exp[i]==')')
        {
            if(top == NULL) return false;
            pop();
        }
    }
    return (top == NULL);
}



int main ()
{
    const char *exp = "((a+b)*(c-d))"; // use const because they are read only
    cout << isBalanced(exp) <<endl;
    return 0;
}
