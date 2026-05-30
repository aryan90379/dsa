

#include <iostream>
using namespace std;


struct Stack
{
    int size;
    int top;
    int *s;
};



void create(struct Stack *st,int sz)
{
    if(sz==-1)
    {
        cout << "Enter size";
        cin >> st->size;

    }
    else st->size = sz;
    st->top = -1;
    st->s = new int[st->size];
}

void Display(Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        cout << st.s[i] <<endl;
    }
}


void push (Stack *st,int x)
{
    if(st->top == st->size-1) cout << "Stack Overflow for value: " << x << "\n";
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(Stack *st)
{
    int x = -1;
    if(st->top == -1) cout << "STack underflow\n";
    else {
        x = st->s[st->top--];
    }
    return x;
}

int peek(Stack st,int index)
{
    int x = -1;
    if(st.top-index+1 <0)
    {
        cout << "Invalid index\n";
    }
    else x = st.s[st.top-index+1];
    return x;
}


int isEmpty(Stack st)
{
    if(st.top == -1) return 1;
    return 0;
}

int isFull(Stack st)
{
    return st.top == st.size-1;
}

int stackTop(Stack st)
{
    if(!isEmpty(st)) return st.s[st.top];
    return -1;
}
int main ()
{

    struct Stack st;
    create(&st,5);

    push (&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    push(&st,60);
    Display(st);
    
cout << peek(st,3)<<endl;

    // cout << pop(&st) <<endl;
    // cout << pop(&st) <<endl;
    // cout << pop(&st) <<endl;
    // cout << pop(&st) <<endl;
    // Display(st);
    return 0;
}