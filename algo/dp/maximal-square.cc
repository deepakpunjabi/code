/*
    Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

    Example:

    Input: 
    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0

    Output: 4
*/

#include <vector>

using namespace std;

/*
    At any point (i,j) square ending at (i,j) has side length
    = 1 + min(up, left, diagonal)
    provided cell itself is 1
*/
int maximalSquare(vector<vector<char>>& matrix) {
    int maxsq = 0;

    int rows = matrix.size() + 1;
    int cols = matrix[0].size() + 1;
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                maxsq = max(maxsq, dp[i][j]);
            }
        }
    }

    return maxsq;
}
