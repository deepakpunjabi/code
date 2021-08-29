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

    unordered_map<int, vector<int>> components() {
        unordered_map<int, vector<int>> res;
        for (int i = 0; i < root.size(); ++i) {
            res[root[i]].push_back(i);
        }
        return res;
    }

    void printComponents() {
        auto components = this->components();
        for (auto& i : components) {
            cout << i.first << " --> ";
            for (auto& j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

class Solution {
   public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DisjointSet ds(s.length());
        for (auto& i : pairs) {
            ds.unionByRank(i[0], i[1]);
        }

        for (int i = 0; i < s.size(); ++i) {
            ds.find(i);
        }

        auto components = ds.components();
        for (auto& i : components) {
            string tmp = "";
            for (auto& j : i.second) {
                tmp += s[j];
            }
            sort(tmp.begin(), tmp.end());
            int k = 0;
            for (auto& j : i.second) {
                s[j] = tmp[k++];
            }
        }

        return s;
    }
};
