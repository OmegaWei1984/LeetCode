// https://leetcode.cn/problems/JEj789/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len = costs.size();
        vector<int> dp(3);
        for (int i = 0; i < 3; ++i) {
            dp[i] = costs[0][i];
        }
        for (int i = 1; i < len; ++i) {
            vector<int> tmp(3);
            for (int j = 0; j < 3; ++j)
                tmp[j] = min(dp[(j + 1) % 3], dp[(j + 2) % 3]) + costs[i][j];
            dp = tmp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};

int main(void) {
    vector<vector<int>> costs = {{17,2,17},{16,16,5},{14,3,19}};
    Solution solution;
    int ans = solution.minCost(costs);
    return 0;
}
