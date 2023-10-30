#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n % 3 == 1) {
            if (n <= 4) return n;
            return pow(3, (n/3) - 1) * 4;
        } else if (n % 3 == 2) {
            return pow(3, (n/3)) * 2;
        }
        else return pow(3, (n/3));
    }
};

int main() {
    Solution sol;
    int res = sol.integerBreak(8);
    cout << res << endl;
    return 0;
}
