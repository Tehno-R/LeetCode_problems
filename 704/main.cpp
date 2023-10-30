#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool arr[1000000 + 1];
    int fb = 1000000; //rand() % 100;
    Solution(int n) {
        arr[0] = false;
        for (int i = 1; i < n + 1; ++i) {
            arr[i] = arr[i-1];
            if (i == fb) arr[i] = true;
        }
    }
    bool isBadVersion(int ind) {
        return arr[ind];
    }
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        while (l < r) {
            int mid = (r - l) / 2;
            if (isBadVersion(l + mid) == false) {
                l = l + mid + 1 ;
            } else r = r - mid;
        }
        return l;
    }
};

int main() {
    srand(time(nullptr));
    Solution sol(1000000);
    int res = sol.firstBadVersion(1000000);
    cout << res << endl;
    return 0;
}
