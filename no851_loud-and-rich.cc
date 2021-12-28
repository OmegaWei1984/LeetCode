#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> g(n);
        for (auto &r : richer) {
            g[r[1]].emplace_back(r[0]);
        }

        vector<int> answer(n, -1);

        function<void(int)> dfs = [&](int x) {
            
        };


        return answer;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>>richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    vector<int>quiet = {3,2,5,4,6,1,7,0};
    vector<int> answer = solution.loudAndRich(richer, quiet);
    // [5,5,2,5,4,5,6,7]

    return 0;
}
