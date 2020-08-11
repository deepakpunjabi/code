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

void heapifyDown(vector<int> &arr, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left  < arr.size() && arr[left] > arr[largest]) largest = left;
    if (right  < arr.size() && arr[right] > arr[largest]) largest = right;
    
    if (largest != index) {
        swap(arr[largest], arr[index]);
        heapifyDown(arr, largest);
    }
}

void createHeap(vector<int> &arr) {
    for (int i = arr.size()/2 - 1; i >= 0; --i) {
        heapifyDown(arr, i);
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
