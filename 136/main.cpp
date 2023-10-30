#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto x:nums)
            ans^=x;
        return ans;
    }
};

int main() {
    Solution sol;
    unsigned short res = 0;
    unsigned short temp;

    while (true) {
        cin >> temp;
        res ^= temp;
        cout << "res = " << res << endl;
    }
    return 0;
}
