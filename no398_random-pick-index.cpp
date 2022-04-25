#include <vector>
#include <iostream>
#include <random>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> group;

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

class Solution1 {
    unordered_map<int, vector<int>> pos;
public:
    Solution1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto& indices = pos[target];
        return indices[rand() % indices.size()];
    }
};

class Solution2 {
    vector<int> &nums;
public:
    Solution2(vector<int>& nums) : nums(nums) {}

    int pick(int target) {
        int result;
        for (int i = 0, counter = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++counter;
                if (rand() % counter == 0)
                    result = i;
            }
        }
        return result;
    }
};

int main(void) {
    vector<int> nums = {1,2,3,3,3};
    Solution* solution = new Solution(nums);
    int ans = solution->pick(3);
    ans = solution->pick(3);

    Solution1 *solution1 = new Solution1(nums);
    int ans1 = solution1->pick(3);
    ans1 = solution1->pick(3);

    Solution2 *solution2 = new Solution2(nums);
    int ans2 = solution2->pick(3);
    ans = solution2->pick(3);

    return 0;
}