#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int factorial(int n)
    {
        int fc = 1;
        for (int i = 1; i <= n; ++i)
            fc *= i;
        return fc;
    }

    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;

        int ans = 10;
        for (int d = 2; d <= n; ++d)
        {
            int m1 = d - 1, n1 = 9;
            int x2 = 9 * (factorial(n1) / factorial(n1 - m1));
            int x = 9 * (tgamma(n1 + 1) / tgamma(n1 - m1 + 1));
            // ans += x;
            ans += x2;
        }

        return ans;
    }
};

int main(void)
{
    Solution solution;
    int ans = solution.countNumbersWithUniqueDigits(5);
    return 0;
}