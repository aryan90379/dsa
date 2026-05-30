#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Queue.h"

// ---------------- STACK ----------------
struct Stack
{
    int size;
    int top;
    Node **S;
};

// ---------------- CREATE STACK ----------------
void StackCreate(Stack *st, int size)
{
    st->size = size;
    st->top = -1;

    st->S = new Node *[size];
}

// ---------------- PUSH ----------------
void push(Stack *st, Node *x)
{
    if (st->top == st->size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

// ---------------- POP ----------------
Node *pop(Stack *st)
{
    Node *x = NULL;

    if (st->top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }

    return x;
}

// ---------------- PEEK ----------------
Node *peek(Stack *st, int pos)
{
    if (pos <= 0 || pos > st->top + 1)
    {
        cout << "Invalid Position" << endl;
        return NULL;
    }

    return st->S[st->top - pos + 1];
}

// ---------------- STACK TOP ----------------
Node *stackTop(Stack *st)
{
    if (st->top == -1)
        return NULL;

    return st->S[st->top];
}

// ---------------- IS EMPTY ----------------
int isEmptyStack(Stack st)
{
    return st.top == -1;
}

