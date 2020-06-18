#include <iostream>
#include <vector>

using namespace std;

class SRegions {
   public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) && board[i][j] == 'O') {
                    markDFS(board, visited, i, j);
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'Z') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void markDFS(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if (visited[i][j]) return;
        if (board[i][j] != 'O') return;

        board[i][j] = 'Z';
        visited[i][j] = true;

        markDFS(board, visited, i - 1, j);
        markDFS(board, visited, i, j - 1);
        markDFS(board, visited, i + 1, j);
        markDFS(board, visited, i, j + 1);
    }
};
