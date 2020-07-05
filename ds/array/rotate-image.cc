/* 

    You are given an n x n 2D matrix representing an image.
    Rotate the image by 90 degrees (clockwise).

    Note:
    You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
    DO NOT allocate another 2D matrix and do the rotation.

    Example 1:
    Given input matrix = 
    [
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ],

    rotate the input matrix in-place such that it becomes:
    [
        [7,4,1],
        [8,5,2],
        [9,6,3]
    ]

*/

#include <vector>

using namespace std;

// only works for square matrix
void rotate(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();

    // transpose the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = i; j < cols; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // swap row elements with 2 pointer
    // prefer swap(low, high) approach than swap(j, n-1-j)
    for (int i = 0; i < rows; ++i) {
        int low = 0;
        int high = cols - 1;
        while (low < high) {
            swap(matrix[i][low], matrix[i][high]);
            ++low;
            --high;
        }
    }
}

/* 

    Time Complexity: linear
    - O(n): n is the total number elements in the matrix
    - O(mn) if m rows and n cols are there

    Space Complexity:
    - O(1), Constant: As we are rotating image inplace

 */
