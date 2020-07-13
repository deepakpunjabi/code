/* 
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

#include <vector>

using namespace std;

/* 

    There is only 1 way to traverse 1st row or column, so sum that path.
    For other cells, you can choose if (i-1, j) or (i, j-1) has minimal cost.

    To find out the actual path, start from last cell, and retrace which minimum you had choosen.

    This should work find with negative numbers as well(not fully sure if this can lead to longest path problem), 
    just need to keep track of minimum from up and left.

*/
int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size();
    if (rows == 0) return 0;
    int cols = grid[0].size();

    int dp[rows][cols];
    dp[0][0] = grid[0][0];

    for (int i = 1; i < rows; ++i) dp[i][0] = grid[i][0] + dp[i - 1][0];
    for (int j = 1; j < cols; ++j) dp[0][j] = grid[0][j] + dp[0][j - 1];

    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            // don't forget to add up your own cost!
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[rows - 1][cols - 1];
}

/* 
    Time Complexity: O(m*n)/(Linear in total number of elements) where m is number of rows and n is number of columns
    Space Complexity: O(m*n) as we are making copy of original grid

    Get the actual path:
    Time Complexity: O(mn) + max(O(m), O(n)) --> O(mn)
    Space is same.
*/
