#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n, "");
        for (int i = 1; i-1 < n; ++i) {
            if (!(i % 3) || !(i % 5)) {
                if (!(i % 3)) ans[i-1] += "Fizz";
                if (!(i % 5)) ans[i-1] += "Buzz";
            } else ans[i-1] = std::to_string(i);
        }
        return ans;
    }
};
int main() {
    Solution sol;
    int n = 15;
    vector<string> ans = sol.fizzBuzz(n);
    for (string i : ans) {
        cout << i << endl;
    }
    return 0;
}
