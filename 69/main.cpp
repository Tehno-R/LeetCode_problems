#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        else if (x == 1) return 1;
        unsigned int l = 0, r = x, mid = 0, temp = 0;
        if (r > 65536) r = 65535;
        while (l < r - 1) {
            mid = ((r + l + 1) / 2);
            temp = mid * mid;
            if (temp == x) return mid;
            else if (temp > x) r = mid;
            else l = mid;
        }
        return l;
    }
};

int main() {
    Solution sol;
    int x = 2147395599;//4554654;
    int res = sol.mySqrt(x);
    cout << res << endl;
    return 0;
}
