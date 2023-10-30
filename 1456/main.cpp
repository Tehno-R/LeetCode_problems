#include <iostream>

using namespace std;

class Solution {

    int l = 0, r = 0;
    int len{0};
    int counter = 0;
    int maximum = 0;
public:
    int maxVowels(string s, int k) {
        len = s.size();
        if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') {
            counter++;
            maximum = 1;
        }
        while (l != len - 1 && r != len - 1) {
            if (r + 1 -l < k) {
                r++;
                char rchar = s[r];
                bool vowels = (rchar == 'a' || rchar == 'e' || rchar == 'i' || rchar == 'o' || rchar == 'u');
                if (vowels) {
                    counter++;
                    if (counter > maximum) maximum = counter;
                }
            } else {
                counter--;
                stepL(s);
            }
        }
        return maximum;
    }

    bool checkVowels(int ptr) {
        if (ptr == 'a' || ptr == 'e' || ptr == 'i' || ptr == 'o' || ptr == 'u') return true;
        else return false;
    }

    void stepL(string s) {
        l++;
        char lchar = s[l];
        bool vowels = (lchar == 'a' || lchar == 'e' || lchar == 'i' || lchar == 'o' || lchar == 'u');
        if (!checkVowels(l)) {
            if (l != r) stepL(s);
        } else {
            counter++;
            if (counter > maximum) maximum = counter;
        }
    }
};

int main() {
    Solution sol;
    string str = "ojgwjhhjooienddhy";
    int c = 5;
    int res = sol.maxVowels(str, c);
    cout << str << endl << res << endl;
    return 0;
}
