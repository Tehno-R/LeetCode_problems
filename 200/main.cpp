#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int dfs(vector<vector<char>> &arr, int i, int j) {
        if (i < 0 || i >= arr.size() ||
            j < 0 || j >= arr[0].size() ||
            arr[i][j] == '0') return 0;
        else {
            arr[i][j] = '0';
            dfs(arr, i+1, j);
            dfs(arr, i-1, j);
            dfs(arr, i, j+1);
            dfs(arr, i, j-1);
        }
        return 1;
    }
public:
    int foo(vector<vector<char>> &arr) {
        int numIsland{0};
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr[0].size(); ++j) {
                if (arr[i][j] == '1') numIsland += dfs(arr, i, j);
            }
        }
        return numIsland;
    }
};

int main() {
    // Put here ur argument
    vector<vector<char>> grid = {
            {'1', '0', '1', '0', '1'},
            {'0', '1', '0', '1', '0'},
            {'1', '0', '1', '0', '1'},
            {'0', '1', '0', '1', '0'}
    };
    //

    Solution sol;
    auto ans = sol.foo(grid);
    cout << ans << endl;
    return 0;
}
