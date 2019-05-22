#include <iostream>
#include <vector>

using namespace std;

/*

Insertion sort is like adding a card in the last.
You move all bigger cards to right one step at a time.
put key in the empty place now.

*/

void insertionSort(vector<int> &a) {
    for (int i = 1; i < a.size(); ++i) {
        int tmp = a[i];
        int j = i;
        while (j >= 0 && a[j - 1] > tmp) {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
}

