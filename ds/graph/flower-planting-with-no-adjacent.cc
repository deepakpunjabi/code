/* 

    lid: https://leetcode.com/problems/flower-planting-with-no-adjacent/

    You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.
    paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.
    Also, there is no garden that has more than 3 paths coming into or leaving it.
    Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, 
    they have different types of flowers.

    Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  
    The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

    Example 1:
    Input: N = 3, paths = [[1,2],[2,3],[3,1]]
    Output: [1,2,3]

    Example 2:
    Input: N = 4, paths = [[1,2],[3,4]]
    Output: [1,2,1,2]

    Example 3:
    Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
    Output: [1,2,3,4]

    Note:
    - 1 <= N <= 10000
    - 0 <= paths.size <= 20000
    - No garden has 4 or more paths coming into or leaving it.
    - It is guaranteed an answer exists.

*/

#include <list>
#include <vector>

using namespace std;

vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
    list<int> adj[N + 1];
    for (const auto &p : paths) {
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }

    vector<int> res(N + 1, 0);
    for (int i = 1; i < N + 1; ++i) {
        vector<bool> color(5, false);
        // check if the color is used by neighbour
        // as problem specifically states answer exists and
        // there are maximum 3 edges to a node, 1 color must remain unused
        for (const auto &dest : adj[i]) {
            color[res[dest]] = true;
        }
        for (int j = 1; j < color.size(); ++j) {
            // printf("coloring res[%d]=%d\n", i, j);
            if (!color[j]) {
                res[i] = j;
                break;
            }
        }
    }

    // this makes solution slower, instead you can use index-1 with res(N, 0)
    vector final(res.begin() + 1, res.end());
    return final;
}
