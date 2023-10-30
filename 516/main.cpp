#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int counter = 0;
    int longestPalindromeSubseq(string s) {
        auto l = s.begin();
        auto r = s.end() - 1;
        int mid = s.length() / 2;
        auto midIt = std::next(s.begin(), mid);
        while (l < r) {
            if (*l == *r) {
                counter++;
                l++;
                r--;
            } else {
                if (*(r-1) == *l) r--;
                else l++;
            }
        }
        return counter*2;
    }
};

int main() {
    Solution a;
    string str = "weQ wE Q |weq| Qe E Q";
    int res = a.longestPalindromeSubseq(str);
    cout << res << endl;
    return 0;
}

// w - 3            1
// e - 5            1
// q - 5            1

// b oqfjqoji z - b wgfweoke z