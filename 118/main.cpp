#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void foo(vector<vector<int>>& res, int numRow, int i = 2) {
        vector<int> row(i);
        *row.begin() = 1;
        *(row.end()-1) = 1;
        vector<int> &lastVec = *(res.end()-1);
        for (int j = 1; j < i/2; ++j) {
            row[j] = lastVec[j] + lastVec[j-1];
            row[i-1-j] = row[j];
        }
        if (i % 2 == 1) row[i/2] = lastVec[i/2] + lastVec[i/2-1];
        res.emplace_back(row);
        if (i == numRow) return;
        else foo(res, numRow, i+1);
    }

    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> res;
        res.emplace_back(vector<int>{1});
        if (numRows == 1) return res;
        foo(res, numRows);
        return res;
    }
};

int main() {
    Solution sol;
    int x = 5;
    vector<vector<int>> res = sol.generate(x);
    for (vector<int> i : res) {
        for (int j : i) {
            cout << j << '\t';
        }
        cout << endl;
    }
    return 0;
}
