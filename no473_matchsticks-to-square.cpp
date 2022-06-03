#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool dfs(int index, vector<int> &matchsticks, vector<int> &edges, int lenOfside) {
        if (index == matchsticks.size())
            return true;
        for (int i = 0; i < edges.size(); ++i) {
            edges[i] += matchsticks[index];
            if (edges[i] <= lenOfside && dfs(index + 1, matchsticks, edges, lenOfside)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int len = accumulate(matchsticks.cbegin(), matchsticks.cend(), 0);
        if (len % 4 != 0)
            return false;
        int lenOfside = len / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> edges(4);
        return dfs(0, matchsticks, edges, lenOfside);
    }
};

int main(void) {
    Solution solution;
    // vector<int> matchsticks = {1,1,2,2,2};
    vector<int> matchsticks = {3, 3, 3, 3, 4};
    bool ans = solution.makesquare(matchsticks);
    return 0;
}
