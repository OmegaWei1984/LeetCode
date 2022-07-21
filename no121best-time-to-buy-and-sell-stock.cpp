// 121. 买卖股票的最佳时机 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = 0;
        for (const int& price : prices) {
            profit = max(profit, price - minPrice);
            minPrice = min(price, minPrice);
        }
        return profit;
    }
};

int main(void) {
    vector<int> prices = {7,1,5,3,6,4};
    Solution solution;
    int ans = solution.maxProfit(prices);
    return 0;
}
