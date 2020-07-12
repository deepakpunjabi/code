/* 

    You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
    Grid cells are connected horizontally/vertically (not diagonally). 
    The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
    The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
    One cell is a square with side length 1. 
    The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

    Example:
    Input:
        [[0,1,0,0],
        [1,1,1,0],
        [0,1,0,0],
        [1,1,0,0]]

    Output: 16

*/

#include <vector>

using namespace std;

// this is simple approach of iterating over grid and counting perimeter
// problem with this approach is if grid is too big and island is small, than you are wasting time
// unnecessarily travesing the grid
int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    if (rows == 0) return 0;
    int cols = grid[0].size();

    int peri = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // check left and right boundary
            if ((j == 0 || grid[i][j - 1] == 0) && grid[i][j] == 1) ++peri;
            if ((j == cols - 1 || grid[i][j + 1] == 0) && grid[i][j] == 1) ++peri;
            // check up and down boundary
            if ((i == 0 || grid[i - 1][j] == 0) && grid[i][j] == 1) ++peri;
            if ((i == rows - 1 || grid[i + 1][j] == 0) && grid[i][j] == 1) ++peri;
        }
    }

    return peri;
}

// this is a better method as it will not traverse the whole grid
// find first occurennce of 1 and recurse from there
int islandPerimeterDFS(vector<vector<int>>& grid) {
    int res = 0;
    pair<int, int> pos = findOne(grid);
    recurse(grid, pos.first, pos.second, res);
    return res;
}

void recurse(vector<vector<int>>& grid, int i, int j, int& res) {
    if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1) {
        res += 1;
        return;
    }
    if (grid[i][j] == 0) {
        res += 1;
        return;
    }
    if (grid[i][j] == 2) return;

    grid[i][j] = 2;
    recurse(grid, i - 1, j, res);
    recurse(grid, i, j - 1, res);
    recurse(grid, i + 1, j, res);
    recurse(grid, i, j + 1, res);
}

pair<int, int> findOne(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j]) return pair<int, int>(i, j);
        }
    }
}
