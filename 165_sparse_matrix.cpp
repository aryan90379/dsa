#include <iostream>
using namespace std;

class Element
{
public:
    int row;
    int col;
    int value;
};

class Sparse
{
private:
    int rows;
    int cols;
    int num;
    Element *ele;

public:
    Sparse(int rows, int cols, int num)
    {
        this->rows = rows;
        this->cols = cols;
        this->num = num;
        ele = new Element[this->num];
    }

    ~Sparse()
    {
        delete[] ele;
    }

    Sparse operator+(Sparse &s);
    friend istream &operator>>(istream &is, Sparse &s); // extraction istream opeartor
    friend ostream &operator<<(ostream &os, Sparse &s); // for display
};

Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    if (rows != s.rows || cols != s.cols)
    {
        cout << "Matrix dimensions must match\n";
        exit(0);
    }
    Sparse *sum = new Sparse(rows, cols, num + s.num);
    i = j = k = 0;
    while (i < num && j < s.num)
    {
        if (ele[i].row < s.ele[j].row)
        {
            sum->ele[k++] = ele[i++];
        }
        else if (ele[i].row > s.ele[j].row)
        {
            sum->ele[k++] = s.ele[j++];
        }
        else if (ele[i].col < s.ele[j].col)
        {
            sum->ele[k++] = ele[i++];
        }
        else if (ele[i].col > s.ele[j].col)
        {
            sum->ele[k++] = s.ele[j++];
        }
        else
        {
            sum->ele[k] = ele[i++];
            sum->ele[k++].value += s.ele[j++].value;
        }
    }

    for(;i<num;i++) sum->ele[k++]=ele[i];
    for(;j<s.num;j++) sum->ele[k++]=s.ele[j];
    
    sum->num = k;
    return * sum; // dereferenced value , that is onverting to Sparese instead of sparse pointer

}

istream &operator>>(istream &is, Sparse &s)
{
    cout << "\nEnter non zero elements\n";
    for (int i = 0; i < s.num; i++)
    {
        cin >> s.ele[i].row >> s.ele[i].col >> s.ele[i].value;
    }
    return is;
}

ostream &operator<<(ostream &os, Sparse &s)
{
    int k = 0;
    for (int i = 0; i < s.rows; i++)
    {
        for (int j = 0; j < s.cols; j++)
        {
            if (s.ele[k].row == i && s.ele[k].col == j)
            {
                cout << s.ele[k++].value << " ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return os;
}

// adding sparse matrrix

int main()
{
    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);
    cin >> s1;
    cin >> s2;

    Sparse sum = s1+s2;

    cout << "First matrix" << endl << s1;
    cout << "second matrix" << endl << s2;
    cout << "Sum of matrix" << endl << sum;




    return 0;
}