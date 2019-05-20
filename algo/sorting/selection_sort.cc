#include <iostream>
#include <vector>

using namespace std;

// select smallest element in each turn
void selectionSort(vector<int> &a) {
    int n = a.size();

    for (int i = 0; i < n - 1; ++i) {  // last element will already be sorted
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

// get state of array after x iterations
void selectionSortWithIterations(vector<int> &a, int x) {
    int n = a.size();
    for (int i = 0; i < n - 1 && x > 0; ++i, --x) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
    }
}
