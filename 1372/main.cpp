#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maximum = 0;
    void solve(TreeNode* cur, int dir, int currentLen) {
        if (!cur) return;
        maximum = max(currentLen, maximum);
        solve(cur->left, 0, dir? currentLen + 1 : 1);
        solve(cur->right, 1, dir? 1 : currentLen + 1);
    }

    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);
        solve(root, 1, 0);
        return maximum;
    }
};

int main() {
    TreeNode* a;
//    a = new TreeNode(1, nullptr,new TreeNode(1,new TreeNode(1),new TreeNode(1,new TreeNode(1, nullptr,new TreeNode(1)),new TreeNode(1))));
    a = new TreeNode(1,new TreeNode(1,new TreeNode(1), nullptr),new TreeNode(1, nullptr,new TreeNode(1)));

    Solution sol;
    int res = sol.longestZigZag(a);
    cout << res << endl;
    return 0;
}
