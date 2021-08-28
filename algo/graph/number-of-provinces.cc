/*

There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly with city c, 
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, 
and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 
Constraints:
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    vector<int> root;  // store root for each node
    vector<int> rank;  // store size of each subtree
   public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int size = isConnected.size();
        root.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; ++i) {
            root[i] = i;
            rank[i] = 1;
        }

        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected[0].size(); ++j) {
                if (isConnected[i][j] == 1 and i != j) {
                    unionByrank(i, j);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < root.size(); ++i) {
            if (root[i] == i) {
                ++res;
            }
        }

        return res;
    }

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
};
