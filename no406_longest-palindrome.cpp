// 409. 最长回文串 https://leetcode.cn/problems/longest-palindrome/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counters;
        int result = 0;
        for (const char& letter : s) {
            ++counters[letter];
        }
        for (auto pair : counters) {
            int value = pair.second;
            result += (value / 2) * 2;
            if (value % 2 == 1 && result % 2 == 0) {
                ++result;
            }
        }
        return result;
    }
};

int main(void) {
    string s = "abccccdd";
    Solution solution;
    int ans = solution.longestPalindrome(s);
    return 0;
}
