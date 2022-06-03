class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (int i = 1; i * (i + 1) <= 2 * n; ++i) {
            if (
                i % 2 == 0 ?
                n % i != 0 && 2 * n % i == 0 :
                n % i == 0
            ) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(void) {
    int n = 9;
    Solution solution;
    int ans = solution.consecutiveNumbersSum(n);
    return 0;
}