#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstring>
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

int OutStackPre(char x)
{
    if(x == '+' || x == '-') return 1;
    else if (x == '*' || x == '/') return 3;
    else if (x == '^') return 6;
    else if (x == '(') return 7;
    else if (x == ')') return 0;
    else
     return 0;
}
int InStackPre(char x)
{
    if(x == '+' || x == '-') return 2;
    else if (x == '*' || x == '/') return 4;
    else if (x == '^') return 5;
    else if (x == '(') return 0;
    else
     return 0;
}

int isOperand(char x)
{
    if(x == '+' || x == '-' || x =='*' || x == '/' || x == '^' || x == '(' || x == ')' ) return 0;
    else
     return 1;
}

char * InToPost(const char *infix)
{
    int i = 0,j=0;
    char *postfix = new char[strlen(infix)+2];
    while(infix[i]!='\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(OutStackPre(infix[i])>InStackPre(top->data))
                push(infix[i++]);
            else
            {
                if(infix[i] == ')')   
                {
                    if(top->data!='(')
                    {
                        postfix[j++] = pop();
                    }
                    else 
                    {
                        pop();
                        i++;
                    }
                }
                else
                    postfix[j++] = pop();
            } 

        }

    }
    while(top!=NULL && top ->data !='#') postfix[j++] = pop();
    postfix[j] = '\0';

    return postfix;

}


int main ()
{

    const char *infix = "((a+b)*c)-d^e^f";
    push('#');
    const char *postfix = InToPost(infix);
    cout << postfix <<endl;
    return 0;
}
