#include <algorithm>

using namespace std;

void quickSort(int arr[], int start, int end) {
    if (start >= end) return;

    // get partition index, and divide main problem into subproblems
    int pi = partition(arr, start, end);
    quickSort(arr, start, pi - 1);
    quickSort(arr, pi + 1, end);
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    // index at which we want to put pivot, starting this with start position
    int pivot_index = start;

    // while (start < end) {
    //     while (start < end && arr[start] <= pivot) {
    //         ++start;
    //     }
    //     while (start < end && arr[end] > pivot) {
    //         --end;
    //     }
    //     swap(arr[start], arr[end]);
    // }

    for (int i = start; i < end; ++i) {
        // whenever you find an element lesser than pivot, put it at pivot index and increment pivot index
        // this way elements_less_than_pivot <= pivot index < elements_greater_than_pivot
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pivot_index]);
            ++pivot_index;
        }
    }

    // you had chosen pivot as end element, now you have to put it at final pivot_index
    swap(arr[pivot_index], arr[end]);
    return pivot_index;
}
