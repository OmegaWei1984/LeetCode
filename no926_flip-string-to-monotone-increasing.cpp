#include <string>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int len = s.size();
        vector<int> p(len + 1, 0);
        for (int i = 0; i < len; ++i)
            p[i + 1] = p[i] + (s[i] == '1' ? 1 : 0);

        int ans = numeric_limits<int>::max();
        for (int i = 0; i <= len; ++i)
            ans = min(ans, p[i] + len - i - (p[len] - p[i]));

        return ans;
    }

    int minFlipsMonoIncr2(string &s)
    {
        int dp0 = 0;
        int dp1 = 0;

        for (char c : s) {
            dp1 = min(dp0, dp1);
            if (c == '1')
                ++dp0;
            else
                ++dp1;
        }

        return min(dp0, dp1);
    }
};

int main(void) {
    string s = "00110";
    Solution solution;
    int ans = solution.minFlipsMonoIncr(s);
    int ans2 = solution.minFlipsMonoIncr2(s);
    return 0;
}
