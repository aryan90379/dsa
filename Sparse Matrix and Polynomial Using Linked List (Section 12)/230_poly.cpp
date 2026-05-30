#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly1 = NULL, *poly2 = NULL;

void create(Node *&poly)
{
    Node *t, *last;
    int num;

    cout << "Enter number of terms\n";
    cin >> num;
    cout << "Enter each term with coefficient and exponent\n";
    for (int i = 0; i < num; i++)
    {
        t = new Node;
        cout << "Coeff for first term sepearte by space: ";
        cin >> t->coeff >> t->exp;

        t->next = NULL;
        if (poly == NULL)
        {
            poly = t;
            last = t;
        }
        else
        {
            last->next = t;
            last = last->next;
        }
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        (p->next != NULL) ? (cout << p->coeff << "x^" << p->exp << "+") : (cout << p->coeff << "x^" << p->exp);
        p = p->next;
    }
    cout << endl;
}

int Eval(struct Node *p, int x)
{
    long sum = 0;
    while (p)
    {
        sum += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return sum;
}

Node *polySum(Node *poly1, Node *poly2)
{
    Node *poly3 = NULL, *last = NULL;
    Node *t;
    while (poly2 && poly1)
    {
        if (poly1->exp < poly2->exp)
        {
            t = new Node;
            t->coeff = poly2->coeff;
            t->exp = poly2->exp;
            t->next = NULL;
            poly2 = poly2->next;
        }
        else if (poly1->exp > poly2->exp)
        {
            t = new Node;
            t->coeff = poly1->coeff;
            t->exp = poly1->exp;
            t->next = NULL;
            poly1 = poly1->next;
        }
        else
        {
            t = new Node;
            t->coeff = poly1->coeff + poly2->coeff;
            t->exp = poly1->exp;
            t->next = NULL;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if (poly3 == NULL)
        {
            poly3 = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
    while (poly1)
    {
        t = new Node;
        t->coeff = poly1->coeff;
        t->exp = poly1->exp;
        t->next = NULL;
        poly1 = poly1->next;
        if (!poly3)
        {
            poly3 = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
    while (poly2)
    {
        t = new Node;
        t->coeff = poly2->coeff;
        t->exp = poly2->exp;
        t->next = NULL;
        poly2 = poly2->next;
        if (!poly3)
        {
            poly3 = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
    return poly3;
}

int main()
{
    cout << "Create first polynomial:\n";
    create(poly1);

    cout << "\nCreate second polynomial:\n";
    create(poly2);

    cout << "\nFirst Polynomial: ";
    Display(poly1);

    cout << "Second Polynomial: ";
    Display(poly2);

    Node *poly3 = polySum(poly1, poly2);

    cout << "Sum Polynomial: ";
    Display(poly3);

    int x;
    cout << "\nEnter value of x for evaluation: ";
    cin >> x;

    cout << "Value of first polynomial: " << Eval(poly1, x) << endl;
    cout << "Value of second polynomial: " << Eval(poly2, x) << endl;
    cout << "Value of sum polynomial: " << Eval(poly3, x) << endl;

    return 0;
}
