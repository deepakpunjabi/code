/*

    Given an m x n matrix, return all elements of the matrix in spiral order.

    Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]

    Example 2:
    Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]

    Constraints:
    - m == matrix.length
    - n == matrix[i].length
    - 1 <= m, n <= 10
    - -100 <= matrix[i][j] <= 100

*/

#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty()) return res;

    // just like android constraints
    int top = 0;
    int bottom = matrix.size() - 1;
    
    int start = 0;
    int end = matrix[0].size() - 1;

    while (top <= bottom && start <= end) {
        for (int j = start; j <= end; ++j) {
            res.push_back(matrix[top][j]);
        }
        top++;
        
        // imagine sendnario: single row
        if (top > bottom) {
            break;
        }

        for (int i = top; i <= bottom; ++i) {
            res.push_back(matrix[i][end]);
        }
        end--;
        
        // imagine sendnario: single column
        if (start > end) {
            break;
        }

        for (int j = end; j >= start; --j) {
            res.push_back(matrix[bottom][j]);
        }
        bottom--;

        for (int i = bottom; i >= top; --i) {
            res.push_back(matrix[i][start]);
        }
        start++;
    }

    return res;
}
