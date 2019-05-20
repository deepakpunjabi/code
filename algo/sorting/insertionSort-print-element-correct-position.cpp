#include <iostream>
using namespace std;

/*

Insertion sort is like adding a card in the last.
You move all bigger cards to right one step at a time.
put key in the empty place now.

*/

void insertionSort(int a[], int res[], int n)
{
    int i, j, key;

    for (i = 1; i < n; ++i)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0)
        {
            if (a[j] > key)
            {
                res[j] = res[j] + 1;
                ++count;
            }
            --j;
        }
        res[i] = i - count;
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] + 1 << " ";
    }
    cout << endl;
}

// driver program
int main()
{
    int n;
    cin >> n;
    int a[n], res[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        res[i] = i;
    }
    // printArray(res, n);
    insertionSort(a, res, n);
    printArray(res, n);
    // printArray(a, n);
    return 0;
}
