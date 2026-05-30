#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

class Node
{
public:
    int data;
    struct Node *next;
};

class Stack
{
private:
    Node *top;
public:
    Stack(){top=NULL;}  
    void push (int x);
    int pop();
    void Display();  
};

void Stack::push(int x)
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


int Stack::pop()
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

void Stack::Display()
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
    Stack st;
    st.push(10);
    st.push(50);
    st.push(30);
    st.push(140);
    st.push(184);
    st.pop();
    st.Display();
    return 0;
}
