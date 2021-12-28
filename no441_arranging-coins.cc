#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (right - left + 1) / 2 + left;
            if ((long long) mid * (mid + 1) <= (long long) 2 * n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
        // int steps = 1, sum = 1;
        // while (sum <= n) {
        //     ++steps;
        //     sum = ((1 + steps) * steps) / 2;
        // }
        // return --steps;
    }
};

int main(void) {
    Solution solution;
    cout << solution.arrangeCoins(3) << endl;
    return 0;
}