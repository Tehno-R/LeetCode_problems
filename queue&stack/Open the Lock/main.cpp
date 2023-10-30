#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {

public:
    string code = "0000";
    int count{-1};
    queue<string> qu;
    unordered_set<string> pass;
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        string cur {"0000"};
        if (dead.count(cur)) return -1;
        qu.emplace(cur);
        pass.emplace(cur);
        while (!qu.empty()) {
            int quSize = qu.size();
            count++;
            while (quSize--) {
                cur = qu.front();
                if (cur == target) return count;
                qu.pop();
                pass.emplace(cur);
                for (int i = 0; i < 4; ++i) {
                    for (int j = -1; j < 2; j += 2) {
                        string next = cur;
                        next[i] = (next[i] - '0' + j + 10) % 10 + '0';
                        if (dead.count(next) || pass.count(next)) continue;
                        else {
                            qu.emplace(next);
                            pass.emplace(next);
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<string> banList{"0000"};
    Solution sol;
    int res = sol.openLock(banList, "8888");
    cout << res << endl;
    return 0;
}
