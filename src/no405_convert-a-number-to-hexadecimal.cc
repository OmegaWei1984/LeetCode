#include <iostream>

using namespace std;

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";

        string strBuff;
        for (int i = 7; i >= 0; --i)
        {
            int value = (num >> (4 * i)) & 0xf;
            if (strBuff.length() > 0 || value > 0) {
                char digit = value < 10 ? (char) ('0' + value) : (char) ('a' + value - 10);
                strBuff.push_back(digit);
            }
        }
        return strBuff;
    }
};

int main(void)
{
    int num = 26;
    Solution solution;
    cout << solution.toHex(num) << endl;
    return 0;
}
