/* 
Given a directed, acyclic graph of N nodes.
Find all possible paths from node 0 to node N-1, and return them in any order.
The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  
graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Note:
The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
*/

#include <vector>

using namespace std;

// in this solution we have not made assumption that graph is dag
// but question specifies that, so there is no such need of visited array
// as we won't be visiting same node again and there won't be any cycles
class Solution {
   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> res;
        vector<bool> visited(graph.size(), false);
        vector<int> path;

        recurse(res, graph, visited, path, 0, graph.size() - 1);

        return res;
    }

    void recurse(vector<vector<int>> &res, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &path, int curr, int target) {
        if (visited[curr]) return;
        if (curr == target) {
            path.push_back(curr);
            res.push_back(path);
            path.pop_back();
            return;
        }

        visited[curr] = true;
        path.push_back(curr);
        for (const auto &i : graph[curr]) {
            // path.push_back(i);
            recurse(res, graph, visited, path, i, target);
            // path.pop_back();
        }
        path.pop_back();
        visited[curr] = false;
    }
};
