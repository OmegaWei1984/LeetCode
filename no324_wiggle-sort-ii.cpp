// https://leetcode.cn/problems/wiggle-sort-ii/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end(), [](int i, int j){
            return i < j;
        });
        int n = nums.size();
        int x = (n + 1) / 2;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
            nums[i] = tmp[j];
            if (i + 1 < n) {
                nums[i + 1] = tmp[k];
            }
        }
    }
};

int main(void) {
    vector<int> nums = {1,5,1,1,6,4,2};
    Solution solution;
    solution.wiggleSort(nums);
    vector<int> nums2 = {1,3,2,2,3,1};
    solution.wiggleSort(nums2);
}
