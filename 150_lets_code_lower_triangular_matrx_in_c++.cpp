#include <iostream>
using namespace std;

class LowerTrianglular
{
private:
    int *A;
    int n;

public:
    LowerTrianglular()
    {
        n = 2;
        A = new int[(n*(n+1))/2];
    }

    LowerTrianglular(int n)
    {
        this->n = n;
        A = new int[(n*(n+1))/2];
    }


    ~LowerTrianglular()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension () {return n;}
};


void LowerTrianglular::Set(int i, int j, int x)
{
    if (i >= j)
        A[n*(j-1)-((j-2)*(j-1))/2 + (i-j)] = x; // column major
        // A[i*(i-1)/2 + j-1] = x; row major
}
int LowerTrianglular::Get(int i, int j)
{
    if (i == j)
        return A[n*(j-1)-((j-2)*(j-1))/2 + (i-j)];
    return 0;
}

void LowerTrianglular::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[i*(j-1)-((j-2)*(j-1))/2 + (i-j)] << " ";
            else
                cout << "0" << " ";
        }
        cout << endl;
    }
}

int main()
{
    int d;
    cout << "Enter dimensions]\n";
    cin >> d;
    LowerTrianglular lm(d);
    // lm.Set(1,1,5);
    // lm.Set(2,2,8);
    // lm.Set(3,3,9);
    // lm.Set(4,4,13);

    int x;
    cout << "Enter all elements\n";
    for (int i =1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin >> x;
            lm.Set(i,j,x);
        }
    }
    lm.Display();


    return 0;
}