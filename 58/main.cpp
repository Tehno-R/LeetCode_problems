#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int counter = 0;
        int lastL = 0;
        for (char c : s) {
            if (c == ' ') {
                if (counter) lastL = counter;
                counter = 0;
            } else counter++;
        }
        if (counter) lastL = counter;
        return lastL;
    }
};

int main() {
    Solution sol;
    string s = "luffy is still joyboy";
    int res = sol.lengthOfLastWord(s);
    cout << res << endl;
    return 0;
}
