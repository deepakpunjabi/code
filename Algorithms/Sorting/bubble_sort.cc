#include <algorithm>
#include <iostream>
using namespace std;

/*

This is a program to do sorting with bubble sort.
It checks each element with the next element,
for example 1st with second and till last means n-1,
for every i, this means n-1-i, because bubble sort works on the principle that heavieast elements are already sorted

worst case: O(n^2)
average case: O(n^2)
best case: O(n)

*/

void bubbleSort(int a[], int n) {
    int i, j;
    for (i = 0; i < n; ++i) {
        bool swapped = false;
        for (j = 0; j < n - j - 1; ++j) {
            // check if there is an inversion
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        // break loop early if there has been a pass, where no element was swapped
        // hence array is alredy in sorted state
        if (!swapped) {
            break;
        }
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// driver program
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bubbleSort(a, n);
    printArray(a, n);
    return 0;
}
