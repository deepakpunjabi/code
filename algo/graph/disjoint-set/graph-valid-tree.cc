/*
    You have a graph of n nodes labeled from 0 to n - 1. 
    You are given an integer n and a list of edges 
    where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

    Return true if the edges of the given graph make up a valid tree, and false otherwise.

    Example 1:
    Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
    Output: true

    Example 2:
    Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
    Output: false
    
    Constraints:
    1 <= 2000 <= n
    0 <= edges.length <= 5000
    edges[i].length == 2
    0 <= ai, bi < n
    ai != bi
    There are no self-loops or repeated edges.
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
    bool validTree(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for (const auto& i : edges) {
            int first = i[0];
            int second = i[1];

            if (ds.find(first) == ds.find(second)) {
                return false;
            }
            ds.unionByRank(first, second);
        }
        // tree should contain only 1 disjoint set(root)
        return ds.components() == 1;
    }
};

// tc:
// ip: 4, [[0,1],[2,3]]
// op: true
// tree must have only a single root node
