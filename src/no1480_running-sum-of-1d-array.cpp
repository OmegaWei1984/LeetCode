// 1480. 一维数组的动态和寻找数组的中心下标 https://leetcode.cn/problems/running-sum-of-1d-array/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int sum = 0;
        for (const int& num : nums) {
            sum += num;
            result.push_back(sum);
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        for_each (nums.begin(), nums.end(), [&sum](int &num){
            sum += num;
            num = sum;
        });
        return nums;
    }
};


class Solution3 {
public:
    vector<int> runningSum(vector<int>& nums) {
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};

int main(void) {
    vector<int> nums = {1,2,3,4};
    Solution solution;
    vector<int> ans = solution.runningSum(nums);
    Solution2 solution2;
    vector<int> ans2 = solution2.runningSum(nums);
    return 0;
}
