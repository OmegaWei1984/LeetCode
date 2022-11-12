// 205. 同构字符串 https://leetcode.cn/problems/isomorphic-strings/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int size = s.size();
        unordered_map<char, char> st;
        unordered_map<char, char> ts;
        for (int i = 0; i < size; ++i) {
            if (
                (st.find(s[i]) != st.end() && st[s[i]] != t[i]) ||
                (ts.find(t[i]) != ts.end() && ts[t[i]] != s[i])
            ) {
                return false;
            }
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
        return true;
    }
};

int main(void) {
    string s = "badc", t = "baba";
    Solution solution;
    bool ans = solution.isIsomorphic(s, t);
    return 0;
}
