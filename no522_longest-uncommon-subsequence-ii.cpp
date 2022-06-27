// https://leetcode.cn/problems/longest-uncommon-subsequence-ii/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        for (int i = 0; i < strs.size(); ++i) {
            int count = 0;
            bool isSpacial = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    isSpacial = false;
                    break;
                }
            }
            if (isSpacial)
                maxLen = max(maxLen, static_cast<int>(strs[i].size()));
        }
        return maxLen;
    }

    bool isSubsequence(string s, string t) {
        string::iterator is = s.begin();
        string::iterator it = t.begin();
        while (*is && *it) {
            if (*is == *it)
                ++is;
            ++it;
        }
        return is == s.end();
    }
};

int main(void) {
    vector<string> strs = {"aba","cdc","eae"};
    Solution solution;
    int ans = solution.findLUSlength(strs);
    strs = {"aaa", "aaa", "aa"};
    ans = solution.findLUSlength(strs);
    return 0;
}
