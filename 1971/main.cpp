#include <iostream>
#include <vector>

using namespace std;
bool check(int n, vector<vector<int>>& edges, int source, int destination, vector<int>& arr) {
    if (source == destination) return true;
    else {
        bool ans{false};
        for (int i = 0; i < n; ++i) {
            if (edges[i][0] == source) {
                bool flag{false};
                for (int j = 0; j < arr.size(); ++j) {
                    if (edges.at(i).at(1) == arr[j]) flag = true;
                }
                if (flag) continue;
                else arr.emplace_back(edges[i][1]);
                ans = check(n, edges, edges[i][1], destination, arr);
            }
            if (edges[i][1] == source) {
                bool flag{false};
                for (int j = 0; j < arr.size(); ++j) {
                    if (edges.at(i).at(0) == arr[j]) flag = true;
                }
                if (flag) continue;
                else arr.emplace_back(edges[i][0]);
                ans = check(n, edges, edges[i][0], destination, arr);
            }
            if (ans) return ans;
        }
        return ans;
    }
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<int> arr {};
    return check(n, edges, source, destination, arr);
};

int main() {
    int n{10};
    vector<vector<int>> edges {
            {4,3},{1,4},{4,8},{1,7},{6,4},
            {4,2},{7,4},{4,0},{0,9},{5,4}
    };
    bool answer = validPath(n, edges, 5, 9);
    cout << answer << endl;
    return 0;
}
