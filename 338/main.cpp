#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        if (!n) return vector<int>{0};
        vector<int> ans(n + 1, 0);
        int temp = 0;
        for (vector<int>::iterator it = (ans.end()-1); (it != ans.begin()) || n != 0; --it) {
            temp = n % 2;
            n = temp == 1 ? (n-1)/2 : n/2;
            *it = temp;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 165;
    vector<int> res = sol.countBits(n);
    for (int i : res) {
        cout << i << '\t';
    }
    cout << endl;
    return 0;
}
