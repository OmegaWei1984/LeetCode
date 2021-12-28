#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int len = ages.size();
        sort(ages.begin(), ages.end());
        int left = 0, right = 0, count = 0;
        for (const int age : ages) {
            if (age < 15) continue;
            while (ages[left] <= 0.5 * age + 7)
                ++left;
            while (right + 1 < len && ages[right + 1] <= age)
                ++right;
            count += right - left;
        }
        return count;
    }
};

int main(void) {
    vector<int> ages = {20, 30, 100, 110, 120};
    Solution solution;
    cout << solution.numFriendRequests(ages) << endl;
    return 0;
}