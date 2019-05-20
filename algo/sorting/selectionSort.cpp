#include <iostream>
#include <algorithm>
using namespace std;

/*
selection sort selects minimum/maximum element in each pass of n pass.
it puts it in its proper position
for example, for 1st pass, consider 1st element as minimum element
find minimum element from the rest of the array.
swap with 1st
*/
void selectionSort(int a[], int n)
{
    int minimum;
    for (int i = 0; i < n - 1; ++i)
    {
        minimum = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[minimum])
            {
                minimum = j;
            }
        }
        swap(a[i], a[minimum]);
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
    // bubbleSort(a, n);
    // insertionSort(a, n);
    selectionSort(a, n);
    printArray(a, n);
    return 0;
}
