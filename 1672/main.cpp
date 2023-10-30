#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        int temp = 0;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = accounts[i].size() - 1; j > 0; --j) {
                temp += accounts[i][j];
            }
            temp += accounts[i][0];
            max = std::max(max, temp);
            temp = 0;
        }
        return max;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr{{1, 3}, {3, 7}, {1, 5}};
    int res = sol.maximumWealth(arr);
    cout << res << endl;
    return 0;
}
