#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < size; ++i) {
            if (nums[i] - 1 != i) {
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};

class Solution2 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        for (int i = 0; i < size; ++i) {
            int index = abs(nums[i]);
            if (nums[index - 1] > 0)
                nums[index - 1] = -nums[index - 1];
            else
                result.push_back(index);
        }
        return result;
    }
};

int main(void) {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution solution;
    vector<int> ans = solution.findDuplicates(nums);
    return 0;
}
