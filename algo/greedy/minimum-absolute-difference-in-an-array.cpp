#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

/*
best method is to use insertion sort
while moving element, also get the difference while inserting element
keep track of minAbsDiff
*/

void bubbleSort(int a[], int n)
{
    int i, j;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n - 1 - i; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int getMinimumAbsDiff(int a[], int n)
{
    bubbleSort(a, n);
    int minAbsDiff = INT_MAX;

    for (int i = 0; i < n - 1; ++i)
    {
        minAbsDiff = min(minAbsDiff, abs(a[i] - a[i + 1]));
        if(minAbsDiff == 0){
            break;
        }
    }

    return minAbsDiff;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cout << getMinimumAbsDiff(a, n) << endl;
    return 0;
}
