#include <algorithm>

using namespace std;

void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    // get partition index, and divide main problem into subproblems
    int pi = partition(arr, start, end);
    quickSort(arr, start, pi - 1);
    quickSort(arr, pi + 1, end);
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int pi = start;

    while (start < end) {
        while (arr[start] <= pivot) {
            ++start;
        }
        while (arr[end] > pivot) {
            --end;
        }
        swap(arr[start], arr[end]);
    }
    
    /* 
    for (int i = start; i < end; ++i) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pi]);
            ++pi;
        }
    }
    */
    
    // end is now has last start value, which is less than pivot,
    // hence we need to put end to the left of pivot
    swap(arr[pi], arr[end]);
    return pi;
}
