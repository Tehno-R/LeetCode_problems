#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int len = prices.size();
        int minprice = INT_MAX;
        int profit = 0;
        for (int price : prices) {
            minprice = min(price, minprice);
            profit = price - minprice;
            ans = max(ans, profit);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {2, 100, 1, 10};
    int res = sol.maxProfit(vec);
    cout << res << endl;
    return 0;
}
