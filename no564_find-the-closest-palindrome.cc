#include<vector>
#include<string>
#include<cmath>

using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        long number = stol(n), ans = -1;
        const vector<long> &candidates = getCandidates(n);
        for (auto &candidate : candidates) {
            if (
                (candidate != number) &&
                (
                    ans == -1 ||
                    (abs(candidate - number) < abs(ans - number)) ||
                    (abs(candidate - number) == abs(ans - number) && candidate < ans)
                )
            ) {
                ans = candidate;
            }
        }
        return to_string(ans);
    }

    vector<long> getCandidates(const string &n) {
        int len = n.length();
        vector<long> candidates = {
            (long)pow(10, len - 1) - 1,
            (long)pow(10, len) + 1 
        };
        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (int i : {prefix - 1, prefix, prefix + 1}) {
            string prefixStr = to_string(i);
            string candidate = prefixStr + string(prefixStr.rbegin() + (len & 1), prefixStr.rend());
            candidates.push_back(stol(candidate));
        }
        return candidates;
    }
};

int main(void) {
    string str = "1123123123131";
    Solution solution;
    string ans = solution.nearestPalindromic(str);
    string str2 = "11";
    ans = solution.nearestPalindromic(str2);
    return 0;
}