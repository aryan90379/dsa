#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Matrix
{
    int *A;
    int n;
};


// -----Row Major-----
// void Set(struct Matrix *m, int i, int j, int x)
// {
//     if (i >= j)
//     {
//         m->A[i*(i-1)/2 + j-1] = x;
//     }
// }


// -----Column major-----
void Set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x;
    }
}


int Get(struct Matrix m, int i, int j)
{
    if (i >=j)
    {
        // return m.A[i*(i-1)/2 + j-1];
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    }
    return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
            { 
                // cout << m.A[i*(i-1)/2 + j-1] << " ";
                cout << m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j] << " ";
            }
            else
            {
                cout << 0 << " "; 
            };
        }
        cout << endl;
    }
}

int main()
{
    struct Matrix m;
    int i,j,x;
    printf("Enter the dimensions");
    scanf("%d",&m.n);
    m.A = (int *)malloc(m.n*(m.n+1)/2*sizeof(int));

cout << "Enter all elements \n";
for (i=1;i<=m.n;i++)
{
    for (j=1;j<=m.n;j++)
    {
        cin >> x; // automatically takes the address
        Set(&m,i,j,x);
    }
}
cout << "\n\n";
Display(m);
    

    
}
