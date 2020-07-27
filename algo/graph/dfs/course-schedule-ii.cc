/*

    There are a total of n courses you have to take, labeled from 0 to n-1.
    Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
    which is expressed as a pair: [0,1]

    Given the total number of courses and a list of prerequisite pairs, 
    return the ordering of courses you should take to finish all courses.

    There may be multiple correct orders, you just need to return one of them. 
    If it is impossible to finish all courses, return an empty array.

    Example 1:
    Input: 2, [[1,0]] 
    Output: [0,1]
    Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
                course 0. So the correct course order is [0,1] .

    Example 2:
    Input: 4, [[1,0],[2,0],[3,1],[3,2]]
    Output: [0,1,2,3] or [0,2,1,3]
    Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
                courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
                So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

    Note:
    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.

*/

#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

/* 
We keep track of order that which nodes are not yet visited(0), which nodes are in currently visiting path(1),
and which are completely visited(2). if we find a 1, it means graph has cycle.
*/
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    // build adjacency list for the graph
    vector<vector<int>> adj(numCourses);
    for (const auto &i : prerequisites) {
        adj[i[1]].push_back(i[0]);
    }

    // usually we use stack in topological sort, 
    // but as we have to return vector, we can directly use it and emulate stack via push_back
    vector<int> res;
    vector<int> visited(numCourses, 0);  // possible states -> 0,1,2

    // recurse for every unvisited node
    for (int i = 0; i < numCourses; ++i) {
        if (visited[i] == 0 && hasCycle(res, visited, i, adj)) return {};
    }
    reverse(res.begin(), res.end()); // similar to popping from stack and inserting in vector
    return res;
}

bool hasCycle(vector<int> &res, vector<int> &visited, int u, vector<vector<int>> &adj) {
    visited[u] = 1;

    for (const auto &i : adj[u]) {
        if (visited[i] == 1) return true;
        if (visited[i] == 0 && hasCycle(res, visited, i, adj)) return true;
    }

    visited[u] = 2;
    res.push_back(u);
    return false;
}

/* 
    TC: O(v+e), as we will visit each process each node and vertice once
    SC: O(v), might need to store whole graph in the stack
*/
