/* 
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
    The robot can only move either down or right at any point in time. 
    The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
    How many possible unique paths are there?

    Example 1:
    Input: m = 3, n = 2
    Output: 3
    Explanation:
    From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Right -> Down
    2. Right -> Down -> Right
    3. Down -> Right -> Right

    Example 2:
    Input: m = 7, n = 3
    Output: 28
    
    Constraints:
    1 <= m, n <= 100
    It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.
*/

/* 
    Recurse down and right from each cell.
    When you reach end row or column, you have come this via 1 unique path.
    Add that to your result.
*/

class ClassyDP {
   public:
    int uniquePaths(int m, int n) {
        int dp[m][n];

        // there is only one way you can traverse first row(right) or first column(down).
        for (int i = 0; i < m; ++i) dp[i][0] = 1;
        for (int j = 0; j < n; ++j) dp[0][j] = 1;

        // for every other cells, you can add ways from where the cell can be reached via left or down.
        // you can reach (i, j) from (i-1, j) via down or from (i, j-1) via right
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

/* 
    Time Complexity: O(m*n)/(Linear in total number of elements) where m is number of rows and n is number of columns
    Space Complexity: O(m*n) as we are making copy of original grid
*/

class FancyPantsDFS {
   public:
    int uniquePaths(int m, int n) {
        int res = 0;
        int start = 0, end = 0;

        if (m - 1 == 0 || n - 1 == 0) return 1;

        recurse(res, start + 1, end, m - 1, n - 1);
        recurse(res, start, end + 1, m - 1, n - 1);

        return res;
    }

    void recurse(int &res, int x, int y, int row, int col) {
        if (x == row || y == col) {
            res += 1;
            return;
        }

        recurse(res, x + 1, y, row, col);
        recurse(res, x, y + 1, row, col);
    }
};

/* 
    Time Complexity: 2^(m*n) as at every cell, you have maximum 2 choices
    Space Complexity: O(1) if we don't count stack space.
*/
