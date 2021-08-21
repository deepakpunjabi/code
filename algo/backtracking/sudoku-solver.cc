/* 

    Write a program to solve a Sudoku puzzle by filling the empty cells.

    A sudoku solution must satisfy all of the following rules:
    - Each of the digits 1-9 must occur exactly once in each row.
    - Each of the digits 1-9 must occur exactly once in each column.
    - Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    - The '.' character indicates empty cells.

    Input: board = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    Output: [
        ["5","3","4","6","7","8","9","1","2"],
        ["6","7","2","1","9","5","3","4","8"],
        ["1","9","8","3","4","2","5","6","7"],
        ["8","5","9","7","6","1","4","2","3"],
        ["4","2","6","8","5","3","7","9","1"],
        ["7","1","3","9","2","4","8","5","6"],
        ["9","6","1","5","3","7","2","8","4"],
        ["2","8","7","4","1","9","6","3","5"],
        ["3","4","5","2","8","6","1","7","9"]
    ]
    Explanation: The input board is shown above and the only valid solution is shown below:

    Constraints:
    - board.length == 9
    - board[i].length == 9
    - board[i][j] is a digit or '.'.
    - It is guaranteed that the input board has only one solution.
*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    unordered_set<string> mapping;

   public:
    void solveSudoku(vector<vector<char>>& board) {
        updateMapping(board);
        // for (auto i : mapping) {
        //     cout << i << endl;
        // }
        backtrack(board, 0, 0);
    }

    void updateMapping(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    mapping.insert("row " + to_string(i) + " contains " + board[i][j]);
                    mapping.insert("col " + to_string(j) + " contains " + board[i][j]);
                    mapping.insert("box " + to_string(i / 3) + "," + to_string(j / 3) + " contains " + board[i][j]);
                }
            }
        }
    }

    void backtrack(vector<vector<char>>& board, int i, int j) {
        // printf("calling backtrack(%d,%d)\n", i, j);
        print(board);
        if (i == 9 or j == 9) {
            return;
        }

        if (board[i][j] == '.') {
            for (int k = 1; k <= 9; ++k) {
                string row = "row " + to_string(i) + " contains " + to_string(k);
                string col = "col " + to_string(j) + " contains " + to_string(k);
                string box = "box " + to_string(i / 3) + "," + to_string(j / 3) + " contains " + to_string(k);

                if (mapping.find(row) != mapping.end() or mapping.find(col) != mapping.end() or mapping.find(box) != mapping.end()) {
                    // printf("continue on board[%d][%d] for k=%d \n", i, j, k);
                    continue;
                } else {
                    // printf("putting board[%d][%d] = %c \n", i, j, to_string(k)[0]);
                    board[i][j] = to_string(k)[0];

                    mapping.insert(row);
                    mapping.insert(col);
                    mapping.insert(box);

                    if (j < 8) {
                        backtrack(board, i, j + 1);
                    } else {
                        backtrack(board, i + 1, 0);
                    }
                    if (!validate(board)) {
                        // printf("erasing board[%d][%d]\n", i, j);
                        board[i][j] = '.';
                        mapping.erase(row);
                        mapping.erase(col);
                        mapping.erase(box);
                    } else {
                        break;
                    }
                }
            }
        } else {
            if (j < 8) {
                backtrack(board, i, j + 1);
            } else {
                backtrack(board, i + 1, 0);
            }
        }
    }

    bool validate(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    void print(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "------------------" << endl;
    }
};

int main() {
    vector<vector<char>> matrix = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    Solution s;
    s.solveSudoku(matrix);
    cout << endl;
    s.print(matrix);
}
