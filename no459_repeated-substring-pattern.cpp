#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return kmp(s + s, s);
    }

    bool kmp(const string &text, const string &pattern)
    {
        int m = text.size(), n = pattern.size();

        vector<int> w(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = w[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = w[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                w[i] = j + 1;
            }
        }

        int match = -1;
        for (int i = 1; i < m - 1; ++i) {
            while (match != -1 && pattern[match + 1] != text[i]) {
                match = w[match];
            }
            if (pattern[match + 1] == text[i]) {
                ++match;
                if (match == n - 1) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main(void) {
    string s = "abcdefghabcdaefgh";
    Solution solution;
    cout << boolalpha << solution.repeatedSubstringPattern(s) << endl;
    return 0;
}