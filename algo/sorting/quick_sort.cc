#include <utility>

using namespace std;

void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int pi = partition(arr, start, end);
    quickSort(arr, start, pi - 1);
    quickSort(arr, pi + 1, end);
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int pi = start;

    for (int i = start; i < end; ++i) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pi]);
            ++pi;
        }
    }
    swap(arr[pi], arr[end]);
    return pi;
}