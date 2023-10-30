#include <iostream>

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start;
        int temp = 0;
        for (int i = 1; i < n; ++i) {
            temp = start + 2 * i;
            res = (res ^ temp);
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.xorOperation(5, 0) << '\n';
    return 0;
}
