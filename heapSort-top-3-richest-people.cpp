#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify_up(int a[], int index)
{
    if (index <= 0)
    {
        return;
    }
    int parent = (index - 1) / 2;

    if (a[parent] < a[index])
    {
        swap(a[index], a[parent]);
        heapify_up(a, parent);
    }
}

void printTop3(int a[], int n)
{
    int max0, max1, max2;

    max0 = a[0];

    if (n == 2)
    {
        cout << max0 << " " << max(a[1], a[2]) << " " << min(a[1], a[2]) << " " << endl;
        return;
    }
    if (a[1] > a[2])
    {
        max1 = a[1];
        if (n == 3)
        {
            max2 = max(a[2], a[3]);
        }
        else
        {
            max2 = max(a[2], max(a[3], a[4]));
        }
    }
    else
    {
        max1 = a[2];
        if (n == 5)
        {
            max2 = max(a[1], a[5]);
        }
        else
        {
            max2 = max(a[1], max(a[5], a[6]));
        }
    }

    cout << max0 << " " << max1 << " " << max2 << " " << endl;
}

void printArray(int a[], int n)
{
    for (int i = 0; i <= n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void heapify_down(int a[], int index, int n)
{
    // cout << "hepify called from index --> " << index << endl;
    int left = a[index] + 1;
    int right = a[index] + 2;
    int max = index;
    if (left <= n && a[left] > a[max])
    {
        max = left;
    }
    if (right <= n && a[right] > a[max])
    {
        max = right;
    }
    if (max != index)
    {
        swap(a[max], a[index]);
        heapify_down(a, max, n);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i)
    {

        cin >> a[i];
        heapify_up(a, i);
        if (i < 2)
        {
            cout << -1 << endl;
        }
        else
        {
            printTop3(a, i);
        }
    }
    return 0;
}
