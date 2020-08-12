#include <vector>

using namespace std;

class Heap {
   public:
    // builds a heap from unsorted array of size n
    void buildHeap(int arr[], int n) {
        int last = n / 2 - 1;
        for (int i = last; i >= 0; --i) {
            heapifyDown(arr, n, i);
        }
    }

    // puts index into it's right place by comparing child nodes recursively
    void heapifyDown(int arr[], int n, int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapifyDown(arr, n, largest);
        }
    }

    // sorts a array, by picking maximum and sending it in the last repetatively
    // in-place, not stable, O(n) amortized
    void heapSort(int arr[], int n) {
        buildHeap(arr, n);

        // actual sort once heap is there
        for (int i = n - 1; i > 0; --i) {
            swap(arr[i], arr[0]);  // extract max and send it to last
            heapifyDown(arr, i, 0);
        }
    }

    // O(n logn)
    int extractMax(int arr[], int n) {
        int max = arr[0];
        process(max);

        swap(arr[0], arr[n - 1]);
        heapifyDown(arr, n - 1, 0);
    }

    // print or process in any other way desired
    void process(int i);
};
