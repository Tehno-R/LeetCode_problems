#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        auto afterEven = nums.begin();
        while (*afterEven % 2 == 0 && afterEven != nums.end()) afterEven += 1;
        auto it = afterEven;
        if (it == nums.end()) return nums;
        while (it != nums.end()) {
            if (*it % 2 == 0) {
                swap(*it, *afterEven);
                afterEven += 1;
            }
            it += 1;
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> testArr = {0, 2};
    auto res = sol.sortArrayByParity(testArr);
    for (auto i : res) {
        cout << i << ' ';
    }
    return 0;
}
