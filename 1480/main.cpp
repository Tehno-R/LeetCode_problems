#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = nums[i] + nums[i-1];
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> arr {15, 16, 1, 22, 105, 84};
    sol.runningSum(arr);
    return 0;
}
