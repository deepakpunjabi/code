/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
    Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

    Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

    Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
    Explanation: There are a total of 2 courses to take. 
                To take course 1 you should have finished course 0. So it is possible.

    Example 2:
    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    Output: false
    Explanation: There are a total of 2 courses to take. 
                To take course 1 you should have finished course 0, and to take course 0 you should
                also have finished course 1. So it is impossible.
    

    Constraints:
    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.
    1 <= numCourses <= 10^5
*/

#include <vector>

using namespace std;

/* 
    This can be also solved by using BFS instead of DFS.
    You can also maintain set of nodes with indegree = 0
    and run BFS only from those nodes
*/


/*
    Here we improve upon the basic solution by not repeating on already covered paths.
    We do this by maintaining set of nodes who are completely visited
    vector<int> visited(n, 0)
    0 - unvisited
    1 - currently exploring
    2 - visited
*/
class SlightlyBetterSolution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependencies(numCourses);
        for (const auto &i: prerequisites) {
            dependencies[i[1]].push_back(i[0]);
        }
        
        vector<int> visited(numCourses, 0);
        for (int i=0; i<numCourses; ++i) {
            if (visited[i] == 0 && !recurse(dependencies, visited, i)) return false;
        }
        
        return true;
    }
    
    bool recurse(vector<vector<int>>& dependencies, vector<int> &visited, int src) {
        if (visited[src] == 1) return false;
        if (visited[src] == 2) return true;
        
        visited[src] = 1;
        for (const auto &i: dependencies[src]) {
            if (!recurse(dependencies, visited, i)) return false;
        }
        visited[src] = 2;
        
        return true;
    }
};

/*
    We try to sort graph topologically and if any cycle if found we return false.
*/
class BasicSolution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependencies(numCourses);
        for (const auto &i: prerequisites) {
            dependencies[i[1]].push_back(i[0]);
        }
        
        vector<bool> visited(numCourses, false);
        for (int i=0; i<numCourses; ++i) {
            if (!recurse(dependencies, visited, i)) return false;
        }
        
        return true;
    }
    
    bool recurse(vector<vector<int>>& dependencies, vector<bool> &visited, int src) {
        if (visited[src]) return false;
        
        visited[src] = true;
        for (const auto &i: dependencies[src]) {
            if (!recurse(dependencies, visited, i)) return false;
        }
        visited[src] = false;
        
        return true;
    }
};
