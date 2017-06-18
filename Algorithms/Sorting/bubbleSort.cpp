#include <iostream>
#include <algorithm>
using namespace std;

/*

This is a program to do sorting with bubble sort.
It checks each element with the next element,
for example 1st with second and till last means n-1,
for every i, this means n-1-i, because bubble sort works on the principle that heavieast elements are already sorted

*/

void bubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n - 1 - i; ++j)
        {
            // check if there is an inversion
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
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
    bubbleSort(a, n);
    printArray(a, n);
    return 0;
}
