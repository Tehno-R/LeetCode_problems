#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> square;
        for (int i = 1; i * i <= n; ++i) {
            square.push_back(i * i);
        }
        queue<int> qu;
        qu.emplace(0);

        int counter{1};
        while (!qu.empty()) {
            for (int i = 0, sz = qu.size(); i < sz; i++) {
                int cur = qu.front();
                qu.pop();
                for (auto e: square) {
                    if (cur + e == n) return counter;
                    else if (cur + e < n) {
                        qu.emplace(cur + e);
                    } else break;
                }
            }
            counter++;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int res = sol.numSquares(15);
    cout << res << endl;
    return 0;
}