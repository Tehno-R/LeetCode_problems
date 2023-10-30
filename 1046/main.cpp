#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1) {
            int maxInd1{-1};
            int maxInd2{-1};
            for (int i = 0; i < stones.size(); ++i) {
                if (maxInd2 == -1 || stones[i] >= stones[maxInd2]) {
                    maxInd1 = maxInd2;
                    maxInd2 = i;
                }
            }
            for (int i = 0; i < stones.size(); ++i) {
                if ((maxInd1 == -1 || stones[i] > stones[maxInd1]) && i != maxInd2) maxInd1 = i;
            }
            int res = stones[maxInd2] - stones[maxInd1];
            stones.erase(stones.begin() + maxInd1);
            if (maxInd2 > maxInd1) maxInd2--;
            if (res != 0) {
                stones[maxInd2] = res;
            } else stones.erase(stones.begin() + maxInd2);
        }
        if (stones.empty()) return 0;
        else return stones[0];
    }
};

int main() {
    Solution sol;
    vector<int> vec {857,149,920,468,623,117,984,537,51,160,512,271,852,372,728,160,512,363,292,838,802,459,961,837,165,
                     203,133,518,184,733};
    int res = sol.lastStoneWeight(vec);
    cout << res << endl;
    return 0;
}
