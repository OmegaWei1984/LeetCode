#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());

        return maxNum - minNum <= 2 * k ? 0 : maxNum - minNum - 2 * k;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums = {1, 3, 6};
    int k = 3;
    int ans = solution.smallestRangeI(nums, k);
    return 0;
}
