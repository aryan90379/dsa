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
    int num;      // number of non-zero elements
    Element *ele; // array of elements
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

// adding sparse matrrix
struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    sum = new Sparse;
    sum->ele = new Element[s1->num + s2->num];

    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].row < s2->ele[j].row)
        {
            sum->ele[k++] = s1->ele[i++];
        }
        else if (s1->ele[i].row > s2->ele[j].row)
        {
            sum->ele[k++] = s2->ele[j++];
        }
        else if (s1->ele[i].col < s2->ele[j].col)
        {
            sum->ele[k++] = s1->ele[i++];
        }
        else if (s1->ele[i].col > s2->ele[j].col)
        {
            sum->ele[k++] = s2->ele[j++];
        }
        else 
        {
            sum->ele[k]=s1->ele[i++];
            sum->ele[k++].value+=s2->ele[j++].value;
        }
    }
    for(;i<s1->num;i++) sum->ele[k++]=s1->ele[i];
    for(;j<s2->num;j++) sum->ele[k++]=s2->ele[j];
    sum->rows = s1->rows;
    sum->cols = s2->cols;
    sum->num = k;
return sum;


}


void destroy(Sparse *s)
{
    delete[] s->ele;
}

int main()
{
    Sparse s1,s2, *s3;

    create(&s1);
    create(&s2);
    s3 = add(&s1,&s2);


    cout << "\nMatrix Representation:\n";
    cout << "\nshowing first matricx\n";
    display(s1);
    cout << "\nshowing second matricx\n";
    display(s2);
    cout << "\nshowing the sume of above two\n";
    display(*s3); // derefrencing the matrix

    destroy(&s1);
    destroy(&s2);
    destroy(s3); // doing *s dererfence the pointer to just Spares but s3 is expecting Sparse *

    return 0;
}