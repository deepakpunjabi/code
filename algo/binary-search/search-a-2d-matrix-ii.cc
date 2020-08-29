#include <vector>

using namespace std;

/*
    Start at top right corner.
    If target is greater go down
    If target is smaller go left
*/
class Greedy {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int i = 0;
        int j = cols-1;
        
        while (i < rows && j >= 0) {
            if (matrix[i][j] == target) return true;
            
            if (target > matrix[i][j]) {
                ++i;
            } else {
                --j;
            }
        }
        
        return false;
    }
};
