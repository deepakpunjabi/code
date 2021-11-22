/*
    You have a graph of n nodes. 
    You are given an integer n and an array edges 
    where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.
    Return the number of connected components in the graph.

    Example 1:
    Input: n = 5, edges = [[0,1],[1,2],[3,4]]
    Output: 2

    Example 2:
    Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
    Output: 1
    
    Constraints:
    - 1 <= n <= 2000
    - 1 <= edges.length <= 5000
    - edges[i].length == 2
    - 0 <= ai <= bi < n
    - ai != bi
    - There are no repeated edges.
*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> root;
    vector<int> rank;

   public:
    DisjointSet(int size) : root(size), rank(size) {
        for (int i = 0; i < size; ++i) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (root[x] == x) {
            return x;
        }
        root[x] = find(root[x]);
        return root[x];
    }

    void unionByRank(int x, int y) {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry) {
            return;
        }

        if (rank[rx] < rank[ry]) {
            swap(rx, ry);
        }

        root[ry] = rx;
        if (rank[rx] == rank[ry]) {
            rank[rx] += 1;
        }
    }

    int components() {
        int sets = 0;
        for (int i = 0; i < root.size(); ++i) {
            if (root[i] == i) {
                ++sets;
            }
        }
        return sets;
    }
};

class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for (auto& i : edges) {
            ds.unionByRank(i[0], i[1]);
        }

        return ds.components();
    }
};
