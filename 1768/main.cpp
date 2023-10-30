#include <iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string::iterator it1 = word1.begin(), it2 = word2.begin();
        bool f1 = true, f2 = true;
        string mergedWord;
        while (f1 || f2) {
            if (it1 != word1.end()) mergedWord += (*(it1++));
            else f1 = false;
            if (it2 != word2.end()) mergedWord += (*(it2++));
            else f2 = false;
        }
        return mergedWord;
    }
};

int main() {
    Solution sol;
    string w1, w2;
    cin >> w1 >> w2;
    string ans = sol.mergeAlternately(w1, w2);
    cout << ans << endl;
    return 0;
}
