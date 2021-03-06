#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();

        if (size == 1)
            return 1;

        vector<int> dp(size);
        dp[0] = 1;
        int maximum = 0;

        for (int i = 1; i < size; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maximum = max(maximum, dp[i]);
        }
        return maximum;
    }
};

int main(void) {
    vector<int> nums = {10,9,2,5,3,7,101,18};

    Solution solution;
    int ans = solution.lengthOfLIS(nums);
    cout << ans << endl;
    return 0;
}
