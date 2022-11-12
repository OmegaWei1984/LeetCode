#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();

        if (size == 1)
            return 1;

        vector<int> dp(size), counter(size);
        int maximum = 0, maxCount = 0;

        for (int i = 0; i < size; ++i) {
            dp[i] = 1;
            counter[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        counter[i] = counter[j];
                    } else if (dp[i] == dp[j] + 1) {
                        counter[i] += counter[j];
                    }
                }
            }
            if (dp[i] > maximum) {
                maximum = dp[i];
                maxCount =  counter[i];
            } else if (maximum == dp[i]) {
                maxCount += counter[i];
            }
        }

        return maxCount;
    }
};

int main(void) {
    vector<int> nums = {1,3,5,4,7};

    Solution solution;
    int ans = solution.lengthOfLIS(nums);
    cout << ans << endl;
    return 0;
}
