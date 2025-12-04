/*
    You are given an unrooted weighted tree with n vertices representing servers numbered from 0 to n - 1,
        an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional edge between vertices ai and bi of weight weighti.
        You are also given an integer signalSpeed.

    Two servers a and b are connectable through a server c if:
    a < b, a != c and b != c.
    The distance from c to a is divisible by signalSpeed.
    The distance from c to b is divisible by signalSpeed.
    The path from c to b and the path from c to a do not share any edges.
    Return an integer array count of length n where count[i] is the number of server pairs that are connectable through the server i.

    Example 1:
    Input: edges = [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]], signalSpeed = 1
    Output: [0,4,6,6,4,0]
    Explanation: Since signalSpeed is 1, count[c] is equal to the number of pairs of paths that start at c and do not share any edges.
    In the case of the given path graph, count[c] is equal to the number of servers to the left of c multiplied by the servers to the right of c.

    Example 2:
    Input: edges = [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]], signalSpeed = 3
    Output: [2,0,0,0,0,0,2]
    Explanation: Through server 0, there are 2 pairs of connectable servers: (4, 5) and (4, 6).
    Through server 6, there are 2 pairs of connectable servers: (4, 5) and (0, 5).
    It can be shown that no two servers are connectable through servers other than 0 and 6.

    Constraints:
    2 <= n <= 1000
    edges.length == n - 1
    edges[i].length == 3
    0 <= ai, bi < n
    edges[i] = [ai, bi, weighti]
    1 <= weighti <= 106
    1 <= signalSpeed <= 106
    The input is generated such that edges represents a valid tree.
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
    // create graph
    int v = edges.size() + 1;
    vector<vector<pair<int, int>>> graph(v);
    for (const auto& e : edges) {
      int src = e[0];
      int dst = e[1];
      int w = e[2];

      graph[src].push_back({dst, w});
      graph[dst].push_back({src, w});
    }

    vector<int> res(v);
    for (int i = 0; i < v; ++i) {
      int totalValidNodes = 0;
      int totalConnNodes = 0;
      for (const auto& [node, w] : graph[i]) {
        int validNodesInSubtree = dfs(graph, signalSpeed, node, i, w);
        totalConnNodes += validNodesInSubtree * totalValidNodes;
        totalValidNodes += validNodesInSubtree;
      }
      res[i] = totalConnNodes;
    }

    return res;
  }

 private:
  int dfs(const vector<vector<pair<int, int>>>& graph, int ss, int root, int parent, int totalW) {
    int count = 0;
    if (totalW % ss == 0) {
      count = 1;
    }
    for (const auto& [node, w] : graph[root]) {
      if (node != parent) {
        count += dfs(graph, ss, node, root, totalW + w);
      }
    }
    return count;
  }
};

int main() {
  Solution solution;
  
  // Example 1
  vector<vector<int>> edges1 = {{1,0,3},{2,0,9},{3,1,6},{4,2,1},{5,4,2},{6,2,2},{7,6,10},{8,2,2},{9,0,5},{10,1,9},{11,9,3},{12,9,8},{13,9,6},{14,8,2},{15,9,7},{16,8,4},{17,9,4},{18,11,7},{19,1,7},{20,7,3},{21,8,3},{22,11,5},{23,15,5},{24,6,2},{25,20,7},{26,1,4},{27,17,4},{28,27,7},{29,8,5},{30,9,8},{31,22,7},{32,26,3},{33,24,4},{34,6,3},{35,25,10},{36,3,1},{37,18,1},{38,22,2},{39,24,3},{40,31,4},{41,16,1},{42,16,10},{43,25,8},{44,39,7},{45,12,1},{46,14,6},{47,45,10},{48,1,1},{49,7,5},{50,6,3},{51,16,7},{52,42,3},{53,46,6},{54,14,9},{55,40,10},{56,48,3},{57,53,2},{58,5,3},{59,7,2},{60,14,1},{61,36,3},{62,12,3},{63,1,8},{64,62,8},{65,57,10},{66,38,6},{67,37,9},{68,16,4},{69,35,5},{70,39,6},{71,33,6},{72,53,5},{73,31,2},{74,41,10},{75,69,3},{76,69,2},{77,57,6},{78,47,3},{79,72,7},{80,13,3},{81,2,2},{82,14,8},{83,80,8}};
  int signalSpeed1 = 6;
  vector<int> result1 = solution.countPairsOfConnectableServers(edges1, signalSpeed1);
  
  cout << "Example 1 Result: [";
  for (int i = 0; i < result1.size(); i++) {
    cout << result1[i];
    if (i < result1.size() - 1) cout << ",";
  }
  cout << "]" << endl;
  
  // // Example 2
  // vector<vector<int>> edges2 = {{0,6,3},{6,5,3},{0,3,1},{3,2,7},{3,1,6},{3,4,2}};
  // int signalSpeed2 = 3;
  // vector<int> result2 = solution.countPairsOfConnectableServers(edges2, signalSpeed2);
  
  // cout << "Example 2 Result: [";
  // for (int i = 0; i < result2.size(); i++) {
  //   cout << result2[i];
  //   if (i < result2.size() - 1) cout << ",";
  // }
  // cout << "]" << endl;
  
  return 0;
}