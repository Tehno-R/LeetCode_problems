#include <iostream>
#include <vector>

using namespace std;

// 1000 ... 50 ... -5
// 1000 ... -1 ... -5
// 0 -1

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int sum = 0;
        int il = 0, ir = grid[0].size() - 1 ,jl = 0, jr = grid.size() - 1, mid = 0, temp = 0;
        while (temp < grid.size()) {
            if (ir == -1) {
                sum += (grid.size() - temp) * grid[0].size();
                break;
            }
            jl = temp;
            while (il < ir) {
                mid = (ir - il) / 2 + il + 1;
                if (grid[jl][mid] < 0) ir = mid - 1;
                else il = mid;
            }
            il = 0;
            if (ir == 0 && grid[jl][ir] < 0) {
                sum += (grid.size() - temp) * grid[0].size();
                break;
            }
            while (jl < jr) {
                mid = (jr - jl) / 2 + jl + 1;
                if (grid[mid][ir] < 0) jr = mid - 1;
                else jl = mid;
            }
            sum += ((++jr) - temp) * (grid[0].size() - ir - 1);
            temp = jr;
            jr = grid.size() - 1;
            ir -= 1;
        }
        return sum;
    }
};
//        nlog(n)+mlog(m)
//       5  1  0
//      -5 -5 -5

int main() {
    Solution sol;
//    vector<vector<int>> arr = {{3,2}, {1,0}};
    vector<vector<int>> arr = {{5,1,0},{-5,-5,-5}};
    int res = sol.countNegatives(arr);
    cout << res << endl;
    return 0;
}

//  4 3 2 -1
//  3 2 1 -1
//  1 1 -1 -2
// -1 -1 -2 -3