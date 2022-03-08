#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto query : queries) {
            int l = query[0], r = query[1];
            int li = l, ri = r;

            while (li < r) {
                if (s[li++] == '|') break;
            }
            
            while (ri > l) {
                if (s[ri--] == '|') break;
            }

            int count = 0;
            if (li < ri) {
                for (int i = li; i <= ri; i++) {
                    if (s[i] == '*') ++count;
                }
            }
            ans.push_back(count);
        }

        return ans;
    }

    vector<int> platesBetweenCandles2(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> preSum(n);
        for (int i = 0, sum = 0; i < n; i++) {
            if (s[i] == '*') {
                sum++;
            }
            preSum[i] = sum;
        }
        vector<int> left(n);
        for (int i = 0, l = -1; i < n; i++) {
            if (s[i] == '|') {
                l = i;
            }
            left[i] = l;
        }
        vector<int> right(n);
        for (int i = n - 1, r = -1; i >= 0; i--) {
            if (s[i] == '|') {
                r = i;
            }
            right[i] = r;
        }
        vector<int> ans;
        for (auto& query : queries) {
            int x = right[query[0]], y = left[query[1]];
            ans.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x]);
        }
        return ans;
    }
};

int main(void) {
    string s = "**|**|***|";
    vector<vector<int>> queries = {{2,5},{5,9}};
    Solution solution;
    vector<int> ans = solution.platesBetweenCandles(s, queries);
    string s2 = "***|**|*****|**||**|*";
    vector<vector<int>> queries2 = {{1,17},{4,5},{14,17},{5,11}};
    vector<int> ans2 = solution.platesBetweenCandles(s2, queries2);
    vector<int> ans3 = solution.platesBetweenCandles2(s, queries);
    vector<int> ans4 = solution.platesBetweenCandles2(s2, queries2);
    return 0;
}
