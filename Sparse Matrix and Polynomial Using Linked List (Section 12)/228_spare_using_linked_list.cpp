#include <stdio.h>
#include <iostream>

using namespace std;

struct Node
{
    int col;
    int val;
    struct Node *next;
};

Node** createMatrix() // pointer to an array of nodes
{

    int m, n;
    cout << "what is the rows of matrix" << endl;
    cin >> m;
    cout << "what is the col of matrix" << endl;
    cin >> n;

   Node **A = new Node*[m];
    
    for (int i = 0; i < m; i++)
    {

        Node *p = NULL;
        A[i] = NULL;

        for (int j = 0; j < n; j++)
        {
            int value;
            cin >> value;
            
            
            if (value != 0)
            {
                Node *t = new Node;

                t->col = j;
                t->val = value;
                t->next = NULL;
               if(p==NULL) // first node;
               {
                A[i] = t;
                p = t;
               }
               else{
                p->next = t;
                p = t;
               }
            }

        }

    
    }
    return A;
}

void printMatrix(Node **A,int m,int n)
{
    for(int i  = 0;i<m;i++)
    {
        Node *p = A[i];
        for(int j = 0;j<n;j++)
        {
            if(p && j==p->col)
            {
                cout << p->val << " "; 
                p=p->next;
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}


int main()
{

    int m,n;
    Node ** matrix = createMatrix();
    cout << "\nEnter rows and columns again for printing\n";
    cin >> m>>n;

    cout << "\nMatrix is:\n";
    printMatrix(matrix,m,n);


    return 0;
}
