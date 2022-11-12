// https://leetcode.cn/problems/next-permutation

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int len = nums.size();
        int i = len - 2;
        while (i >= 0 && (nums[i] >= nums[i + 1]))
        {
            --i;
        }
        if (i >= 0)
        {
            int j = len - 1;
            while (j >= 0 && (nums[i] >= nums[j]))
            {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main(void)
{
    vector<int> nums = {1, 2, 3};
    Solution solution;
    solution.nextPermutation(nums);

    return 0;
}
