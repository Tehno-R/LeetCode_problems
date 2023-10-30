#include <iostream>
#include <string>
#include "stack"

using namespace std;

class Solution {
public:
    stack<char> stk;
    bool isValid(string s) {
        for( auto e : s) {
            if (e == '[' || e == '(' || e == '{') stk.push(e);
            else {
                if (stk.empty()) return false;
                char top = stk.top();
                switch (top) {
                    case '[':
                        if (e == ']') stk.pop();
                        else return false;
                        break;
                    case '(':
                        if (e == ')') stk.pop();
                        else return false;
                        break;
                    case '{':
                        if (e == '}') stk.pop();
                        else return false;
                        break;
                    default:
                        return false;
                }
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution sol;
    string str = "(])";
    bool res = sol.isValid(str);
    cout << res << endl;
    return 0;
}
