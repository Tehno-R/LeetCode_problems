#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex);
        for (int i = 0; i < rowIndex; ++i) {
            res[i] = 1 + (i*(rowIndex-i-1))
        }
    }
};

int main() {
    Solution sol;
    int n = 10;
    vector<int> ans = sol.getRow(n);
    for (int i : ans) {
        cout << i << '\t';
    }
    return 0;
}
