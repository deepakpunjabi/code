#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(int a[], int n, int x)
{
    int minimum;
    for(int i=0; (i < n-1) && (x > 0); ++i)
    {
        minimum = i;
        for(int j=i+1; j<n; ++j)
        {
            if(a[j] < a[minimum])
            {
                minimum = j;
            }
        }
        swap(a[i], a[minimum]);
        --x;
    }
}

void printArray(int a[], int n)
{
    for(int i=0; i<n; ++i)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n, x;
    cin >> n >> x;
    int i;
    int a[n];
    
    for(i=0; i<n; ++i)
    {
        cin >> a[i];
    }
    
    selectionSort(a, n, x);
    printArray(a, n);
    
    return 0;
}
