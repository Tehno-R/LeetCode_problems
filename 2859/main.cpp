#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (__builtin_popcount(i) == k) ans += nums[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr {4,3,2,1};
    int k = 2;
    int res = sol.sumIndicesWithKSetBits(arr, k);
    cout << res << '\n';
    return 0;
}
