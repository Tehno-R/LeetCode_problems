#include <iostream>

using namespace std;
// isBadVersion is a LeetCode API

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        while (l < r) {
            int mid = (r - l) / 2.0;
            if (isBadVersion(l + mid) == false) {
                l = l + mid + 1;
            } else r = l + mid;
        }
        return l;
    }
};

int main() {
    Solution sol;
    int res = sol.firstBadVersion(10);
    cout << res << endl;
    return 0;
}
