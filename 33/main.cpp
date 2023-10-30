#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int bias = 0;
        for (std::vector<int>::iterator it = nums.begin(); it != nums.end() - 1; ++it) {
            if (*it > *(it + 1)) {
                if (target <= *it) bias = -(std::distance(it, nums.end()-1));
                else bias = std::distance(nums.begin(), it + 1);
                std::rotate(nums.begin(), it + 1, nums.end());
                break;
            }
        }
        std::vector<int>::iterator it = std::lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end() && *it == target) {
            int ind = std::distance(nums.begin(), it);
            return ind + bias;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {3, 1};
    int res = sol.search(vec, 3);
    cout << res << endl;
    return 0;
}
