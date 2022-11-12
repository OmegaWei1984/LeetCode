#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int thirdMax1(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });

        vector<int>::iterator i = nums.begin();
        int counter = 1, maximum = (*i);

        while (counter < 3 && (++i != nums.end())) {
            if (maximum > (*i)) {
                maximum = (*i);
                ++counter;
            }
        }

        return counter <= 2 ? (nums[0]) : maximum;
    }

    int thirdMax2(vector<int> &nums) {
        set<int> maximum;
        for (auto num : nums) {
            maximum.insert(num);
            if (maximum.size() > 3) {
                maximum.erase(maximum.begin());
            }
        }

        cout << maximum.size() << endl;

        // return maximum.size() < 3 ? *(--maximum.end()) : *maximum.begin();
        return maximum.size() < 3 ? *maximum.rbegin() : *maximum.begin();
    }

    int thirdMax3(vector<int> &nums) {
        const long int minimum = -2147483649;
        long int a = minimum, b = minimum, c = minimum;
        for (const auto &num : nums) {
            if (num > a) {
                c = b;
                b = a;
                a = num;
            } else if (a > num && num > b) {
                c = b;
                b = num;
            } else if (b > num && num > c) {
                c = num;
            }
        }

        return c != minimum ? c : a;
    }
};

int main(void)
{
    // vector<int> nums = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    // vector<int> nums = {2, 2, 3, 1};
    // vector<int> nums = {2, 1};
    vector<int> nums = {5,2,2};
    Solution solution;
    cout << solution.thirdMax3(nums) << endl;
    return 0;
}