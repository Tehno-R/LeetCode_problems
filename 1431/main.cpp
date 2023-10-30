#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        for (auto e : candies) if (e > max) max = e;
        vector<bool> greatest(candies.size(), false);
        for (int i = 0; i < candies.size(); ++i) if (candies[i] + extraCandies >= max) greatest[i] = true;
        return greatest;
    }
};

int main() {
    Solution sol;
    vector<int> cand {2,3,5,1,3};
    vector<bool> res = sol.kidsWithCandies(cand, 3);
    for (auto e : res) {
        cout << e << endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
