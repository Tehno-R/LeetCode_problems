#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) map.emplace(nums[i], 1);
            else map[nums[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            int maxInd = -10e4;
            for (auto it = ; it != map.end(); it++) {
                if (map[maxInd] < (*it).second) maxInd = (*it).first;
            }
            map[maxInd] = 0;
            ans.push_back(maxInd);
        }
        return ans;
    }
};

int main() {
    srand(time(nullptr));
    Solution sol;
    vector<int> nums = {6,0,1,4,9,7,-3,1,-4,-8,4,-7,-3,3,2,-3,9,5,-4,0};
    int k = 6;
    vector<int> ans = sol.topKFrequent(nums, k);
    for (int e : ans) {
        cout << e << '\t';
    }
    return 0;
}
