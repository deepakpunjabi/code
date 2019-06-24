#include <utility>

using namespace std;

class DisjointSet {
    int *arr;
    int *size;

    DisjointSet(int n) {
        arr = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
            size[i] = 1;
        }
    }
    ~DisjointSet() {
        delete arr;
        delete size;
    }

    int find(int x) {
        if (arr[x] != x) {
            arr[x] = find(arr[x]);
        }
        return arr[x];
    }

    void unionBySize(int x, int y) {
        int r1 = find(x);
        int r2 = find(y);

        if (r1 == r2) return;

        if (size[r1] < size[r2]) {
            swap(r1, r2);
        }

        arr[r2] = r1;
        if (size[r1] == size[r2]) {
            ++size[r1];
        }
    }
};