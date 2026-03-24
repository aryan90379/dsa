#include <iostream>
using namespace std;

struct Element
{
    int row;
    int col;
    int value;
};

struct Sparse
{
    int rows;
    int cols;
    int num;        // number of non-zero elements
    Element *ele;   // array of elements
};

void create(Sparse *s)
{
    cout << "Enter number of rows and columns: ";
    cin >> s->rows >> s->cols;

    cout << "Enter number of non-zero elements: ";
    cin >> s->num;

    s->ele = new Element[s->num];

    cout << "Enter row column value for each non-zero element:\n";

    for (int i = 0; i < s->num; i++)
    {
        cin >> s->ele[i].row >> s->ele[i].col >> s->ele[i].value;
    }
}

void display(const Sparse &s) // pass by refrence 

{
    int k = 0;

    for (int i = 0; i < s.rows; i++)
    {
        for (int j = 0; j < s.cols; j++)
        {
            if (k < s.num && i == s.ele[k].row && j == s.ele[k].col)
            {
                cout << s.ele[k++].value << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void destroy(Sparse *s)
{
    delete[] s->ele;
}

int main()
{
    Sparse s;

    create(&s);

    cout << "\nMatrix Representation:\n";
    display(s);

    destroy(&s);

    return 0;
}