#include <utility>

using namespace std;

void heapify(int arr[], int n, int root) {
    int largest = root;
    int left = 2 * root + 1, right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

// in-place, not stable
// O(n)
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) heapify(arr, n, i);
}

// O(n logn)
int extractMax(int arr[], int n) {
    swap(arr[0], arr[n - 1]);
    heapify(arr, n - 1, 0);
}