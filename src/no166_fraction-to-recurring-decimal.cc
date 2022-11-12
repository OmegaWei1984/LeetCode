#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string sb;
        long long n = abs(numerator), d = abs(denominator);
        if ((numerator < 0 ^ denominator < 0) && numerator != 0)
            sb.append("-");

        long long integer = n / d;
        sb.append(to_string(integer));

        n %= d;
        if (n == 0)
            return sb;

        sb.append(".");

        unordered_map<int, int> remainders;
        string decimal;
        for (int i = 0; n && !remainders.count(n); ++i)
        {
            remainders[n] = i;
            n *= 10;
            decimal.append(to_string(n / d));
            n %= d;
        }

        if (n != 0)
        {
            sb.append(decimal.substr(0, remainders[n])).append("(" + decimal.substr(remainders[n]) + ")");
        }
        else
        {
            sb.append(decimal);
        }

        return sb;
    }
};

int main(void)
{
    Solution solution;
    cout << solution.fractionToDecimal(0, -5) << endl;
    return 0;
}