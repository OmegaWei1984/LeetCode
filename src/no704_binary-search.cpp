// 704. 二分查找 https://leetcode.cn/problems/binary-search/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = ((r - l) / 2) + l;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                r = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            }
        }
        return -1;
    }
};

int main(void) {
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    Solution solution;
    int ans = solution.search(nums, target);
    return 0;
}
