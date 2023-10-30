#include <iostream>
using namespace std;

class Solution {
public:
    long Nod(long a, long b)
    {
        return a && b ? (a > b ? Nod(a%b, b) : Nod(a, b%a)) : (a ? a : b);
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1.empty() || str2.empty()) return "";
        std::string::iterator it1, it2;
        if (str1.size() < str2.size()) {
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        it1 = str1.begin();
        it2 = str2.begin();
        string res;
        int s1 = str1.size();
        int s2 = str2.size();
        int limit = str2.size() - (str1.size() % str2.size());
        int nod = Nod(str1.size(), str2.size());
        if (*(it2) != *(it1 + str2.size())) return "";
        while (it2 != str2.end() && res.size() < limit && (res.size() / nod * str2.size() != 0)) {
            if (*(it1++) == *it2) res += *(it2++);
            else break;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string w1, w2, res;
    cin >> w1 >> w2;
    res = sol.gcdOfStrings(w1, w2);
    cout << res << endl;
    return 0;
}
