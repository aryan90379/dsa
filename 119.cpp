#include <iostream>
#include <stdio.h>

using namespace std;
class Array
{
private:
    int *A;
    // int A[20];
    int size;
    int length;
    void swap(int *x, int *y); //beacuse swap is a ahpeer fucntoon only to be used inside the class not by users of the class, the fucntions that we have mentioned can use it but we cannot directly call swap and use it


public:
    Array() // non parameterized constructor
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz) //  parameterized constructor
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array() // destructor
    {
        delete[] A;
    }

    void Display();
    void Append(int x);
    int Delete(int index);
    void Insert(int index,int x);
    int LinearSearch(int key);
    int BinarySearch(int key);
    // int RBinSearch(int a[], int l, int h, int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
    Array* Union(Array *arr2);
    Array* Intersection(Array *arr2);
    Array* Difference(Array *arr2);
    
};

void Array::Display()
{
    int i;
    cout << "Elements are: ";
    for (i = 0; i < length; i++)

    {

        cout << A[i] << " ";
        /* code */
    }
}

void Array::Append(int x) //  inserting new elements at the end
{
    if (length < size)
        A[length++] = x;
}

void Array::Insert( int index, int x)
{
    int i;
    if (index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}

int Array::Delete( int index) // return deleted element
{

    int x, i;
    if (index >= 0 && index < length)
    {
        x = A[index];
        for (i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }

    return 0; // if element is not found
}

void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// int LinearSearch(struct  Array arr,int key){

//     int i;
//     for (i = 0; i < arr.length;i++){
//         if(key==arr.A[i])

//             return i;

//     }
//     return -1;
// }

// improved linear search
int Array::LinearSearch( int key)
{

    int i;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            // swap(&arr->A[i], &arr->A[i - 1]); // transposition
            swap(&A[i], &A[0]); // move to front
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch( int key)
{
    int l, h, mid;
    l = 0;
    h = length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key <= A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a, l, mid - 1, key);

        else
            return RBinSearch(a, mid + 1, h, key);
    }
    return -1;
}

int Array::Get( int index)
{
    if (index >= 0 && index <= length - 1)
        return A[index];
    return -1;
}

void Array::Set( int index, int x)
{
    if (index >= 0 && index <= length - 1)
    {
        A[index] = x;
    }
}

int Array::Max()
{
    int max = A[0];
    int i;
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

int Array::Min()
{
    int Min = A[0];
    int i;
    for (int i = 1; i < length; i++)
    {
        if (A[i] < Min)
        {
            Min = A[i];
        }
    }
    return Min;
}

int Array::Sum()
{
    int sum = 0;
    int i;
    for (int i = 1; i <= length; i++)
    {
        sum += A[i];
    }
    return sum;
}

float Array::Avg()
{
    return (float)Sum() / length;
}

void Array::Reverse()
{

    int *B;
    int i, j;
    B = new int[length];
    for (i = length - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (i = 0; i < length; i++)
        A[i] = B[i];
}

void Array::Reverse2()
{
    int i, j, temp;
    for (i = 0, j = length - 1; i <= j; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

void Array::InsertSort( int x)

{

    if (length == size)
        return;

    int i = length - 1;
    while (i >= 0 && x < A[i])
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

int Array::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return 0; // false
    }
    return 1; // true
}

void Array::Rearrange()
{

    int i, j;
    i = 0;
    j = length - 1;

    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
            swap(&A[i], &A[j]);
    }
}

Array* Array::Merge( struct Array arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = new Array(length+arr2.length);


    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = A[j];

    arr3->length = length + arr2.length;
    return arr3;
}

Array* Array::Union( struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = new Array(length+arr2->length);



    while (i < length && j < arr2->length)
    {
        if (A[i] == arr2->A[j])

        {
            arr3->A[k++] = A[i++];
            j++;
        }
        else if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = A[j];

    arr3->length = k;
    return arr3;
}

 Array* Array::Intersection( struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = new Array(length+arr2->length);  // passing the length+arr2.length this is the passing of sz , it create A of lenght sz in heap, the object arr3 if not in heap, it wil be destoryed when this funions runs so can never be returned, as soon as the fucntion ends, constructor will delete it form heap, everything, so obejet holding the Array A should be on the heap too

 
    while (i < length && j < arr2->length)
    {
        if (A[i] == arr2->A[j])

        {
            arr3->A[k++] = A[i++];
            j++;
        }
        else if (A[i] < arr2->A[j])
            i++;
        else
            j++;
    }

    arr3->length = k;
    return arr3;
}

Array* Array::Difference( struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = new Array(length+arr2->length);

    while (i < length && j < arr2->length)
    {
        if (A[i] == arr2->A[j])

        {
            i++;
            j++;
        }
        else if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else
            j++;
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];

    arr3->length = k;
    return arr3;
}

int main()
{

    Array *arr1;
    int ch,sz,x, index;

    printf("Enter size of array: ");
    cin >> sz;
    arr1 = new Array[sz];
    do
    {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Serach\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice");
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int x;
            printf("Enter an element and an index");
            cin >> x >> index;
            arr1->Insert( index, x);
            break;
        }
        case 2:
        {
            printf("Enter index to delete");
            cin >> index;
            int deletedElement = arr1->Delete(index);
            printf("Deleted element: %d\n", deletedElement);
            break;
        }
        case 3:
        {
            int key;
            printf("Enter key to search: ");
            cin >> key;
            int searchIndex = arr1->LinearSearch( key);
            if (searchIndex != -1)
            {
                printf("Element found at index: %d\n", searchIndex);
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        }
        case 4:
        {
            printf("Sum of elements: %d\n", arr1->Sum());
            break;
        }
        case 5:
        {
            arr1->Display();
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "Exiting..." << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid choice, please try again." << endl;
        }
        }
    } while (ch < 6);

    return 0;
}
