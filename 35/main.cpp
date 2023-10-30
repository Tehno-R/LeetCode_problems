#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = (r - l) / 2.0;
            if (nums[l + mid] < target) {
                l = l + mid + 1;
            } else r = l + mid;
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<int> vec {1,7,9,15,19,20,21,24,26,30,33};
    int res = sol.searchInsert(vec, 8);
    cout << res << endl;
    return 0;
}
