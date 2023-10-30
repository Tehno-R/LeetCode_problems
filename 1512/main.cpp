#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> table;
        for (int i : nums) {
            table[i] += 1;
        }
        int res = 0;
        int temp;
        for (auto i : table) {
            temp = -1 + i.second;
            res += sum();
        }
        return res;
    }
};

int main() {
    vector<int> arr {1,2,3,1,1,3};
    Solution sol;
    int ans = sol.numIdenticalPairs(arr);
    cout << ans << '\n';
    return 0;
}
