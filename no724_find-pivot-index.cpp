// 724. 寻找数组的中心下标 https://leetcode.cn/problems/find-pivot-index/

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, right = accumulate(nums.begin() + 1, nums.end(), 0);
        if (right == 0) {
            return 0;
        }
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            left += nums[i - 1];
            right -= nums[i];
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
};

int main(void) {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    Solution solution;
    int ans = solution.pivotIndex(nums);
}
