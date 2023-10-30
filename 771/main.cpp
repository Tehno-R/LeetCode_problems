#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> table;
        for (char i : stones) table[i] += 1;
        int res = 0;
        for (char i : jewels) res += table[i];
        return res;
    }
};

int main() {
    Solution sol;
    string jew = "Ab", st = "AAoiuhuibewb";
    int ans = sol.numJewelsInStones(jew, st);
    cout << ans << '\n';
    return 0;
}
