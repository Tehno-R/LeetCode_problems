#include <iostream>
#include <vector>
using namespace std;

void islandMark(vector<vector<char>>& grid, int i, int j) {
    grid[i][j] = 'x';
    if (i + 1 < grid.size() && grid[i+1][j] == '1') {
        islandMark(grid,i+1,j);
    }
    if (i - 1 >= 0 && grid[i-1][j] == '1') {
        islandMark(grid,i-1,j);
    }
    if (j + 1 < grid[0].size() && grid[i][j+1] == '1') {
        islandMark(grid,i,j+1);
    }
    if (j - 1 >= 0 && grid[i][j-1] == '1') {
        islandMark(grid,i,j-1);
    }
}

int numIslands(vector<vector<char>>& grid) {

    int islandCount{0};
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                islandMark(grid, i, j);
                islandCount++;
            }
        }
    }
    return islandCount;
}


int main() {

    vector<vector<char>> grid = {{'1','1','0','1','0'},
                                 {'1','1','0','1','0'},
                                 {'1','1','0','0','1'},
                                 {'0','0','1','0','0'}};
    int res = numIslands(grid);
    cout << res << endl;
    return 0;
}
