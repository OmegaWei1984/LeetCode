// httis://leetcode.cn/problems/is-subsequence/
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
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
    Solution solution;
    string s = "abc";
    string t = "ahbgdc";
    bool ans = solution.isSubsequence(s, t);
    s = "axc";
    ans = solution.isSubsequence(s, t);
    return 0;
}