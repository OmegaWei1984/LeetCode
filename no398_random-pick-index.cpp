#include <vector>
#include <map>
#include <iostream>
#include <random>

using namespace std;

class Solution {
public:
    map<int, vector<int>> group;

    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            group[num].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> candidates = group[target];
        random_device rd;     // only used once to initialise (seed) engine
        mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
        uniform_int_distribution<int> uni(0, candidates.size() - 1); // guaranteed unbiased

        return candidates[uni(rng)];
    }
};

int main(void) {
    vector<int> nums = {1,2,3,3,3};
    Solution* solution = new Solution(nums);
    int ans = solution->pick(3);
    ans = solution->pick(3);
    return 0;
}