#include <iostream>
using namespace std;

/*

Insertion sort is like adding a card in the last.
You move all bigger cards to right one step at a time.
put key in the empty place now.

*/

void insertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; ++i)
    {
        key = a[i];
        j = i - 1;
        //overwrite every bigger element to right
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            --j;
        }
        // correction because of --j
        a[j + 1] = key;
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << endl;
    }
}

// driver program
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    insertionSort(a, n);
    printArray(a, n);
    return 0;
}
