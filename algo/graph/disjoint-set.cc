#include <utility>

using namespace std;

class DisjointSet {
    int *root;  // store root for each node
    int *rank;  // store size of each subtree

    // vector<int> root;
    // vector<int> rank;

    // DisjointSet(int size) : root(size), rank(size) {
    //     for (int i = 0; i < size; ++i) {
    //         root[i] = i;
    //         rank[i] = 1;
    //     }
    // }

    DisjointSet(int n) {
        root = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    ~DisjointSet() {
        delete root;
        delete rank;
    }

    // path-compression algorithm
    int find(int x) {
        if (root[x] == x) {
            return x;
        }
        root[x] = find(root[x]);
        return root[x];
    }

    void unionByrank(int x, int y) {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry) return;

        if (rank[rx] < rank[ry]) {
            swap(rx, ry);
        }

        root[ry] = rx;
        if (rank[rx] == rank[ry]) {
            ++rank[rx];
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
