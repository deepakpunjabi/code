/* 
    Given a 2D board and a word, find if the word exists in the grid.
    The word can be constructed from letters of sequentially adjacent cell, 
    where "adjacent" cells are those horizontally or vertically neighboring. 
    The same letter cell may not be used more than once.

    Example:
    board =
    [
        ['A','B','C','E'],
        ['S','F','C','S'],
        ['A','D','E','E']
    ]

    Given word = "ABCCED", return true.
    Given word = "SEE", return true.
    Given word = "ABCB", return false.

    Constraints:
    - board and word consists only of lowercase and uppercase English letters.
    - 1 <= board.length <= 200
    - 1 <= board[i].length <= 200
    - 1 <= word.length <= 10^3
*/

#include <string>
#include <vector>

using namespace std;

class WordSearch {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    if (dfs(board, visited, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string word, int pos) {
        if (word.length() == pos) return true;
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size()) return false;
        if (visited[i][j]) return false;
        if (board[i][j] != word[pos]) return false;

        visited[i][j] = true;
        if (dfs(board, visited, i + 1, j, word, pos + 1)) return true;
        if (dfs(board, visited, i, j + 1, word, pos + 1)) return true;
        if (dfs(board, visited, i - 1, j, word, pos + 1)) return true;
        if (dfs(board, visited, i, j - 1, word, pos + 1)) return true;
        visited[i][j] = false;

        return false;
    }
};
