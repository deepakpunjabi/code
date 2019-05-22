#include <iostream>
#include <vector>
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

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}
