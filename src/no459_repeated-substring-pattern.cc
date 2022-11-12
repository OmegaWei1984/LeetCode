#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for (int i = 1; i * 2 <= len; ++i)
        {
            if (len % i == 0) {
                bool is_match = true;
                for (int j = i; j < len; ++j) {
                    if (s[j] != s[j - i]) {
                        is_match = false;
                        break;
                    }
                }
                if (is_match) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(void)
{
    string s = "abcabcabcabc";
    Solution solution;
    cout << boolalpha << solution.repeatedSubstringPattern(s) << endl;
    return 0;
}