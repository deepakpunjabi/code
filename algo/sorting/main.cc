#include <iostream>

using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    int i;
    int a[n];

    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }

    //selectionSort(a, n, x);
    printArray(a, n);

    return 0;
}
