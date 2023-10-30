#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            if (s.empty()) break;
            if (s[i] == '#') {
                if (i == 0) {
                    s = s.substr(1, s.size() - 1);
                    i -= 1;
                    size -= 1;
                    continue;
                }
                s = s.substr(0, i-1) + s.substr(i+1, s.size() - (i+1));
                i -= 2;
                size -= 2;
            }
        }
        size = t.size();
        for (int i = 0; i < t.size(); ++i) {
            if (t.empty()) break;
            if (t[i] == '#') {
                if (i == 0) {
                    t = t.substr(1, t.size() - 1);
                    i -= 1;
                    size -= 1;
                    continue;
                }
                t = t.substr(0, i-1) + t.substr(i+1, t.size() - (i+1));
                i -= 2;
                size -= 2;
            }
        }
        return s == t;
    }
};

int main() {
    Solution sol;
    cout << sol.backspaceCompare("gtc#uz#", "gtcm##uz#");
    return 0;
}
