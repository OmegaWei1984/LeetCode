// 278. 第一个错误的版本 https://leetcode.cn/problems/first-bad-version/

using namespace std;

class Solution {
private:
    int bad;

    bool isBadVersion(int ver) {
        return ver == bad;
    }

public:
    Solution(int bad) : bad(bad) {}

    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = ((r - l) / 2) + l;
            if (isBadVersion(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};


int main(void) {
    int n = 5, bad = 4;
    Solution solution(bad);
    int ans = solution.firstBadVersion(n);
    return 0;
}
