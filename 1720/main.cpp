#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        encoded.emplace(encoded.begin(), first);
        for (int i = 1; i < encoded.size(); ++i) {
            encoded[i] = encoded[i] ^ first;
            first = encoded[i];
        }
        return encoded;
    }
};

int main() {
    Solution sol;
    vector<int> arr {1, 2, 3};
    int val = 1;
    vector<int> res = sol.decode(arr, val);
    for (int i : res) {
        cout << i << ' ';
    }
    return 0;
}
